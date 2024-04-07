#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "dma_data/dma_data.h"
#include "behavior_data.h"
#include "audio/external.h"
#include "engine/graph_node.h"
#include "area.h"
#include "bsm_level_select_menu.h"
#include "debug.h"
#include "game_init.h"
#include "ingame_menu.h"
#include "object_helpers.h"
#include "object_list_processor.h"
#include "print.h"
#include "rendering_graph_node.h"
#include "save_file.h"
#include "segment2.h"
#include "segment7.h"
#include "spawn_object.h"
#include "sm64.h"
#ifdef PUPPYPRINT
#include "puppyprint.h"
#endif

#define TEXTURE_WIDTH  178 // 74 * 1.2 * 2, round up
#define TEXTURE_HEIGHT 82  // 34 * 1.2 * 2, round up
#define TEXTURE_HEIGHT_4K 11
#define TEXTURE_COUNT 8

#define GAME_FRAMERATE 30

struct BSMDMAImageProperties {
    const Texture *dataAddr;
    const Texture *paletteAddr;
    u32 relativeLoopStart;
    u32 frameTotal;
    u32 framerate;
    u32 startFrame;
};

struct BSMDMAImageProperties bsmDMAProps[BSM_COURSE_COUNT] = {
    [BSM_COURSE_1_SNOWY_PEAK]        = {.dataAddr = course1_video_data, .paletteAddr = course1_video_palettes, .relativeLoopStart = 0, .frameTotal = 292, .startFrame = 0, .framerate = 30},
    [BSM_COURSE_2_LAVA_ISLE]         = {.dataAddr = course2_video_data, .paletteAddr = course2_video_palettes, .relativeLoopStart = 0, .frameTotal = 292, .startFrame = 0, .framerate = 30},
    [BSM_COURSE_3_FUNGI_CANYON]      = {.dataAddr = course3_video_data, .paletteAddr = course3_video_palettes, .relativeLoopStart = 0, .frameTotal = 292, .startFrame = 0, .framerate = 30},
    [BSM_COURSE_4_STARLIGHT_FEST]    = {.dataAddr = course4_video_data, .paletteAddr = course4_video_palettes, .relativeLoopStart = 0, .frameTotal = 292, .startFrame = 0, .framerate = 30},
    [BSM_COURSE_5_HOLIDAY_PEAK]      = {.dataAddr = course5_video_data, .paletteAddr = course5_video_palettes, .relativeLoopStart = 0, .frameTotal = 292, .startFrame = 0, .framerate = 30},
    [BSM_COURSE_6_SCORCH_ISLE]       = {.dataAddr = course6_video_data, .paletteAddr = course6_video_palettes, .relativeLoopStart = 0, .frameTotal = 292, .startFrame = 0, .framerate = 30},
    [BSM_COURSE_7_SPORE_CANYON]      = {.dataAddr = course7_video_data, .paletteAddr = course7_video_palettes, .relativeLoopStart = 0, .frameTotal = 292, .startFrame = 0, .framerate = 30},
    [BSM_COURSE_8_CYBER_FEST]        = {.dataAddr = course8_video_data, .paletteAddr = course8_video_palettes, .relativeLoopStart = 0, .frameTotal = 292, .startFrame = 0, .framerate = 30},
    [BSM_COURSE_9_CORNERSOFT_PARADE] = {.dataAddr = course9_video_data, .paletteAddr = course9_video_palettes, .relativeLoopStart = 0, .frameTotal = 1,   .startFrame = 0, .framerate = 30},
};

// NOTE: This has acceptable alignment, but should otherwise be taken into consideration with DMA usage.
#define TEXTURE_SIZE ALIGN16(TEXTURE_WIDTH * TEXTURE_HEIGHT * sizeof(u8))
#define ALIGNED_BUFFER_SIZE (ALIGN16(TEXTURE_SIZE) + 16)
#define PALETTE_SIZE (0x100 * sizeof(RGBA16))

OSIoMesg bsmMenuImageDMAIoMesg[TEXTURE_COUNT];
OSMesg bsmMenuImageDMAReceivedMesg[TEXTURE_COUNT];
OSMesgQueue bsmMenuImageDMAQueue;

u8 gSafeToLoadVideo = BSM_VIDEO_UNALLOCATED;
u8 sTripleBufferIndex = 0;
u8 bsmSafeBufferIndex = 0;
u8 sBSMWaitFrames = BSM_VIDEO_FRAMES_TO_WAIT;
u8 hasInitializedMessageQueue = FALSE;
s32 sImageDMACount = 0;

Texture *bsmDMATextures[3];
Texture *bsmDMAPaletteTextures[3];
u8 bsmDMAMisaligned[ARRAY_COUNT(bsmDMATextures)];

u32 bsmImageGameFrame = 0;
u32 bsmImageVideoFrame = 0;
s32 bsmCourseIndex = BSM_COURSE_1_SNOWY_PEAK;

static void dma_read_image_noblock(u8 *dest, u8 *srcStart, u8 *srcEnd) {
    u32 size = ALIGN16(srcEnd - srcStart);

    osInvalDCache(dest, size);
    while (size != 0) {
        u32 copySize = (size >= 0x1000) ? 0x1000 : size;

        osPiStartDma(&bsmMenuImageDMAIoMesg[sImageDMACount++], OS_MESG_PRI_NORMAL, OS_READ, (uintptr_t) srcStart, dest, copySize,
                     &bsmMenuImageDMAQueue);

        dest += copySize;
        srcStart += copySize;
        size -= copySize;
    }

    assert(sImageDMACount <= TEXTURE_COUNT + 1, "sImageDMACount too large!");
}

static void dma_read_image_at_offset(u8 *dest, u8 *relativeAddr, size_t size) {
    dma_read_image_noblock(dest, relativeAddr, (u8 *) ((size_t) relativeAddr + size));
}

static void dma_bsm_frame(const Texture *startingAddr, const Texture *paletteAddr, u32 imageIndex) {
    Texture *relativeAddr = (Texture *) ((u32) startingAddr + (imageIndex * TEXTURE_SIZE));
    Texture *dest = bsmDMATextures[sTripleBufferIndex];
    bsmDMAMisaligned[sTripleBufferIndex] = (0x10 - ((size_t) relativeAddr & 0xF)) & 0xF;
    dma_read_image_at_offset(dest, (u8 *) ((size_t) relativeAddr & ~0xF), ALIGNED_BUFFER_SIZE);

    relativeAddr = (Texture *) ((u32) paletteAddr + (imageIndex * PALETTE_SIZE));
    dest = bsmDMAPaletteTextures[sTripleBufferIndex];
    dma_read_image_at_offset(dest, (u8 *) relativeAddr, PALETTE_SIZE);

    sTripleBufferIndex = (sTripleBufferIndex + 1) % ARRAY_COUNT(bsmDMATextures);
}

static void add_menu_frame(void) {
    if (bsmCourseIndex < BSM_COURSE_COUNT) {
        bsmImageGameFrame++;
        bsmImageVideoFrame = bsmImageGameFrame * bsmDMAProps[bsmCourseIndex].framerate / GAME_FRAMERATE;
        if (bsmImageVideoFrame >= bsmDMAProps[bsmCourseIndex].frameTotal) {
            bsmImageGameFrame = bsmDMAProps[bsmCourseIndex].relativeLoopStart * GAME_FRAMERATE / bsmDMAProps[bsmCourseIndex].framerate;
            bsmImageVideoFrame = bsmImageGameFrame * bsmDMAProps[bsmCourseIndex].framerate / GAME_FRAMERATE;
        }
    }
}

s32 init_menu_video_buffers(UNUSED s16 arg0, UNUSED s32 arg1) {
    gSafeToLoadVideo = BSM_VIDEO_UNALLOCATED;
    bsmImageGameFrame = 0;
    bsmImageVideoFrame = 0;
    bsmCourseIndex = BSM_COURSE_1_SNOWY_PEAK;
    sTripleBufferIndex = 0;
    bsmSafeBufferIndex = 0;
    sBSMWaitFrames = BSM_VIDEO_FRAMES_TO_WAIT;

    u8 *paletteaddr = main_pool_alloc(PALETTE_SIZE * ARRAY_COUNT(bsmDMAPaletteTextures), MEMORY_POOL_LEFT);
    if (paletteaddr == NULL) {
        assert(FALSE, "Out of memory! :(");
        return TRUE;
    }
    u8 *memaddr = main_pool_alloc(ALIGNED_BUFFER_SIZE * ARRAY_COUNT(bsmDMATextures), MEMORY_POOL_LEFT);
    if (memaddr == NULL) {
        assert(FALSE, "Out of memory! :(");
        return TRUE;
    }

    if (!hasInitializedMessageQueue) {
        hasInitializedMessageQueue = TRUE;
        osCreateMesgQueue(&bsmMenuImageDMAQueue, bsmMenuImageDMAReceivedMesg,
                        ARRAY_COUNT(bsmMenuImageDMAReceivedMesg));
    }

    gSafeToLoadVideo = BSM_VIDEO_UNSAFE;

    for (s32 i = 0; i < ARRAY_COUNT(bsmDMAPaletteTextures); i++) {
        bsmDMAPaletteTextures[i] = &paletteaddr[PALETTE_SIZE * i];
    }

    for (s32 i = 0; i < ARRAY_COUNT(bsmDMATextures); i++) {
        bsmDMATextures[i] = &memaddr[ALIGNED_BUFFER_SIZE * i];
        bsmDMAMisaligned[i] = 0;
    }

    return TRUE;
}

s32 update_menu_video_buffers(UNUSED s16 arg0, UNUSED s32 arg1) {
    if (gSafeToLoadVideo == BSM_VIDEO_UNALLOCATED || !gBSMInitialized) {
        return TRUE;
    }

    assert(get_selcted_menu_object(gBSMSelectedButton) != NULL, "gBSMSelectedButton is NULL!");

    if (
        !get_selcted_menu_object(gBSMSelectedButton)->oBSMMenuIsSelected
        || gBSMSelectedButton != bsmCourseIndex
    ) {
        if (gBSMSelectedButton < BSM_COURSE_COUNT) {
            bsmCourseIndex = gBSMSelectedButton;
        }
        gSafeToLoadVideo = BSM_VIDEO_UNSAFE;
        sBSMWaitFrames = BSM_VIDEO_FRAMES_TO_WAIT;
    }

    if (!check_image_dma_complete(0, 0)) {
        if (sBSMWaitFrames > 0) {
            sBSMWaitFrames--;
        }

        if (gSafeToLoadVideo != BSM_VIDEO_UNSAFE) {
            add_menu_frame();
        }
        return TRUE;
    }

    if (sBSMWaitFrames > 0) {
        sBSMWaitFrames--;
        return TRUE;
    }

    if (gSafeToLoadVideo == BSM_VIDEO_UNSAFE) {
        if (gBSMSelectedButton < BSM_COURSE_COUNT) {
            bsmCourseIndex = gBSMSelectedButton;
            bsmImageGameFrame = bsmDMAProps[bsmCourseIndex].startFrame * GAME_FRAMERATE / bsmDMAProps[bsmCourseIndex].framerate;
            bsmImageVideoFrame = bsmImageGameFrame * bsmDMAProps[bsmCourseIndex].framerate / GAME_FRAMERATE;
            bsmSafeBufferIndex = sTripleBufferIndex;
            gSafeToLoadVideo = BSM_VIDEO_ACTIVE_DMA;
        }
    } else {
        add_menu_frame();
    }

    dma_bsm_frame(bsmDMAProps[bsmCourseIndex].dataAddr, bsmDMAProps[bsmCourseIndex].paletteAddr, bsmImageVideoFrame);

    if (gSafeToLoadVideo == BSM_VIDEO_ACTIVE_DMA && bsmSafeBufferIndex == sTripleBufferIndex) {
        gSafeToLoadVideo = BSM_VIDEO_SAFE;
    }

    return TRUE;
}

s32 check_image_dma_complete(UNUSED s16 arg0, UNUSED s32 arg1) {
    while (osRecvMesg(&bsmMenuImageDMAQueue, NULL, OS_MESG_NOBLOCK) == 0) {
        sImageDMACount--;
        assert(sImageDMACount >= 0, "Negative sImageDMACount detected!");
        if (sImageDMACount < 0) {
            sImageDMACount = 0;
        }
    }

    return (sImageDMACount == 0);
}



ALIGNED16 static const Vtx bsm_menu_cutscene_vtx_0[4] = {
	{{ {-371, 320, -20}, 0, {                 0, TEXTURE_HEIGHT_4K << 5}, {255, 255, 255, 255} }},
	{{ { 371, 320, -20}, 0, {TEXTURE_WIDTH << 5, TEXTURE_HEIGHT_4K << 5}, {255, 255, 255, 255} }},
	{{ { 371, 366, -20}, 0, {TEXTURE_WIDTH << 5,                      0}, {255, 255, 255, 255} }},
	{{ {-371, 366, -20}, 0, {                 0,                      0}, {255, 255, 255, 255} }},
};
ALIGNED16 static const Vtx bsm_menu_cutscene_vtx_1[4] = {
	{{ {-371, 274, -20}, 0, {                 0, TEXTURE_HEIGHT_4K << 5}, {255, 255, 255, 255} }},
	{{ { 371, 274, -20}, 0, {TEXTURE_WIDTH << 5, TEXTURE_HEIGHT_4K << 5}, {255, 255, 255, 255} }},
	{{ { 371, 320, -20}, 0, {TEXTURE_WIDTH << 5,                      0}, {255, 255, 255, 255} }},
	{{ {-371, 320, -20}, 0, {                 0,                      0}, {255, 255, 255, 255} }},
};
ALIGNED16 static const Vtx bsm_menu_cutscene_vtx_2[4] = {
	{{ {-371, 228, -20}, 0, {                 0, TEXTURE_HEIGHT_4K << 5}, {255, 255, 255, 255} }},
	{{ { 371, 228, -20}, 0, {TEXTURE_WIDTH << 5, TEXTURE_HEIGHT_4K << 5}, {255, 255, 255, 255} }},
	{{ { 371, 274, -20}, 0, {TEXTURE_WIDTH << 5,                      0}, {255, 255, 255, 255} }},
	{{ {-371, 274, -20}, 0, {                 0,                      0}, {255, 255, 255, 255} }},
};
ALIGNED16 static const Vtx bsm_menu_cutscene_vtx_3[4] = {
	{{ {-371, 182, -20}, 0, {                 0, TEXTURE_HEIGHT_4K << 5}, {255, 255, 255, 255} }},
	{{ { 371, 182, -20}, 0, {TEXTURE_WIDTH << 5, TEXTURE_HEIGHT_4K << 5}, {255, 255, 255, 255} }},
	{{ { 371, 228, -20}, 0, {TEXTURE_WIDTH << 5,                      0}, {255, 255, 255, 255} }},
	{{ {-371, 228, -20}, 0, {                 0,                      0}, {255, 255, 255, 255} }},
};
ALIGNED16 static const Vtx bsm_menu_cutscene_vtx_4[4] = {
	{{ {-371, 136, -20}, 0, {                 0, TEXTURE_HEIGHT_4K << 5}, {255, 255, 255, 255} }},
	{{ { 371, 136, -20}, 0, {TEXTURE_WIDTH << 5, TEXTURE_HEIGHT_4K << 5}, {255, 255, 255, 255} }},
	{{ { 371, 182, -20}, 0, {TEXTURE_WIDTH << 5,                      0}, {255, 255, 255, 255} }},
	{{ {-371, 182, -20}, 0, {                 0,                      0}, {255, 255, 255, 255} }},
};
ALIGNED16 static const Vtx bsm_menu_cutscene_vtx_5[4] = {
	{{ {-371,  90, -20}, 0, {                 0, TEXTURE_HEIGHT_4K << 5}, {255, 255, 255, 255} }},
	{{ { 371,  90, -20}, 0, {TEXTURE_WIDTH << 5, TEXTURE_HEIGHT_4K << 5}, {255, 255, 255, 255} }},
	{{ { 371, 136, -20}, 0, {TEXTURE_WIDTH << 5,                      0}, {255, 255, 255, 255} }},
	{{ {-371, 136, -20}, 0, {                 0,                      0}, {255, 255, 255, 255} }},
};
ALIGNED16 static const Vtx bsm_menu_cutscene_vtx_6[4] = {
	{{ {-371,  44, -20}, 0, {                 0, TEXTURE_HEIGHT_4K << 5}, {255, 255, 255, 255} }},
	{{ { 371,  44, -20}, 0, {TEXTURE_WIDTH << 5, TEXTURE_HEIGHT_4K << 5}, {255, 255, 255, 255} }},
	{{ { 371,  90, -20}, 0, {TEXTURE_WIDTH << 5,                      0}, {255, 255, 255, 255} }},
	{{ {-371,  90, -20}, 0, {                 0,                      0}, {255, 255, 255, 255} }},
};
ALIGNED16 static const Vtx bsm_menu_cutscene_vtx_7[4] = {
	{{ {-371,  23, -20}, 0, {                 0, (TEXTURE_HEIGHT - (TEXTURE_HEIGHT_4K * 7)) << 5}, {255, 255, 255, 255} }},
	{{ { 371,  23, -20}, 0, {TEXTURE_WIDTH << 5, (TEXTURE_HEIGHT - (TEXTURE_HEIGHT_4K * 7)) << 5}, {255, 255, 255, 255} }},
	{{ { 371,  44, -20}, 0, {TEXTURE_WIDTH << 5,                                               0}, {255, 255, 255, 255} }},
	{{ {-371,  44, -20}, 0, {                 0,                                               0}, {255, 255, 255, 255} }},
};
ALIGNED16 static const Gfx bsm_menu_cutscene_tri_0[] = {
	gsSPVertex(bsm_menu_cutscene_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};
ALIGNED16 static const Gfx bsm_menu_cutscene_tri_1[] = {
	gsSPVertex(bsm_menu_cutscene_vtx_1 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};
ALIGNED16 static const Gfx bsm_menu_cutscene_tri_2[] = {
	gsSPVertex(bsm_menu_cutscene_vtx_2 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};
ALIGNED16 static const Gfx bsm_menu_cutscene_tri_3[] = {
	gsSPVertex(bsm_menu_cutscene_vtx_3 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};
ALIGNED16 static const Gfx bsm_menu_cutscene_tri_4[] = {
	gsSPVertex(bsm_menu_cutscene_vtx_4 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};
ALIGNED16 static const Gfx bsm_menu_cutscene_tri_5[] = {
	gsSPVertex(bsm_menu_cutscene_vtx_5 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};
ALIGNED16 static const Gfx bsm_menu_cutscene_tri_6[] = {
	gsSPVertex(bsm_menu_cutscene_vtx_6 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};
ALIGNED16 static const Gfx bsm_menu_cutscene_tri_7[] = {
	gsSPVertex(bsm_menu_cutscene_vtx_7 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

ALIGNED16 static const Gfx bsm_menu_cutscene_dl_before[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0),
	gsDPSetTextureFilter(G_TF_POINT),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsSPEndDisplayList(),
};
ALIGNED16 static const Gfx bsm_menu_cutscene_dl_after[] = {
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsDPPipeSync(),
	gsDPSetTextureFilter(G_TF_BILERP),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};
ALIGNED16 static const Gfx bsm_menu_cutscene_image_0[] = {
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 23, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 0, 0),
    gsDPLoadTile(7, 0, 0, (TEXTURE_WIDTH - 1) << G_TEXTURE_IMAGE_FRAC, (TEXTURE_HEIGHT_4K - 1) << G_TEXTURE_IMAGE_FRAC),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 23, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 4, 0, G_TX_CLAMP | G_TX_NOMIRROR, 8, 0),
    gsDPSetTileSize(0, 0, 0, (TEXTURE_WIDTH - 1) << G_TEXTURE_IMAGE_FRAC, (TEXTURE_HEIGHT_4K - 1) << G_TEXTURE_IMAGE_FRAC),
	gsSPEndDisplayList(),
};
ALIGNED16 static const Gfx bsm_menu_cutscene_image_7[] = {
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 23, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 0, 0),
    gsDPLoadTile(7, 0, 0, (TEXTURE_WIDTH - 1) << G_TEXTURE_IMAGE_FRAC, ((TEXTURE_HEIGHT - (TEXTURE_HEIGHT_4K * 7)) - 1) << G_TEXTURE_IMAGE_FRAC),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 23, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 4, 0, G_TX_CLAMP | G_TX_NOMIRROR, 8, 0),
    gsDPSetTileSize(0, 0, 0, (TEXTURE_WIDTH - 1) << G_TEXTURE_IMAGE_FRAC, ((TEXTURE_HEIGHT - (TEXTURE_HEIGHT_4K * 7)) - 1) << G_TEXTURE_IMAGE_FRAC),
	gsSPEndDisplayList(),
};

ALIGNED16 static const Gfx *menu_cutscene_tris[] = {
    bsm_menu_cutscene_tri_0,
    bsm_menu_cutscene_tri_1,
    bsm_menu_cutscene_tri_2,
    bsm_menu_cutscene_tri_3,
    bsm_menu_cutscene_tri_4,
    bsm_menu_cutscene_tri_5,
    bsm_menu_cutscene_tri_6,
    bsm_menu_cutscene_tri_7,
};
ALIGNED16 static const Gfx *menu_cutscene_images[] = {
    bsm_menu_cutscene_image_0,
    bsm_menu_cutscene_image_0,
    bsm_menu_cutscene_image_0,
    bsm_menu_cutscene_image_0,
    bsm_menu_cutscene_image_0,
    bsm_menu_cutscene_image_0,
    bsm_menu_cutscene_image_0,
    bsm_menu_cutscene_image_7,
};

// Geo to display the funny video
Gfx *geo_bsm_menu_video_scene(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *objectGraphNode = (struct Object *) gCurGraphNodeObject;

        if (
            objectGraphNode->behavior != segmented_to_virtual(bhvBSMMenuButtonOrStage) ||
            !obj_has_model(objectGraphNode, MODEL_BSM_MENU_STAGE) ||
            gSafeToLoadVideo != BSM_VIDEO_SAFE ||
            objectGraphNode->oBehParams2ndByte != bsmCourseIndex ||
            objectGraphNode->oAnimState != 0
        ) {
            return NULL;
        }

        struct GraphNodeGenerated *currentGraphNode = (struct GraphNodeGenerated *) node;
        s32 renderIndex = sTripleBufferIndex - 1;
        if (renderIndex < 0) {
            renderIndex = ARRAY_COUNT(bsmDMATextures) - 1;
        }

        SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, LAYER_OPAQUE);
        dlStart = alloc_display_list(sizeof(Gfx) * (8 * ARRAY_COUNT(menu_cutscene_tris) + 3));
        Gfx *dlHead = dlStart;

	    gSPDisplayList(dlHead++, bsm_menu_cutscene_dl_before);

        for (s32 i = 0; i < ARRAY_COUNT(menu_cutscene_tris); i++) {
            gDPTileSync(dlHead++);

            gDPSetTextureImage(dlHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, bsmDMAPaletteTextures[renderIndex]);
            gDPSetTile(dlHead++, 0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0);
            gDPLoadTLUTCmd(dlHead++, 5, (PALETTE_SIZE / sizeof(RGBA16)) - 1);

            gDPSetTextureImage(dlHead++, G_IM_FMT_CI, G_IM_SIZ_8b, TEXTURE_WIDTH, bsmDMATextures[renderIndex] + bsmDMAMisaligned[renderIndex] + (i * (TEXTURE_WIDTH*TEXTURE_HEIGHT_4K*sizeof(u8))));
            gSPDisplayList(dlHead++, menu_cutscene_images[i]);
            gSPDisplayList(dlHead++, menu_cutscene_tris[i]);
	        gDPPipeSync(dlHead++);
        }

	    gSPDisplayList(dlHead++, bsm_menu_cutscene_dl_after);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
};
