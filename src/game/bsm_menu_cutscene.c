#include <PR/ultratypes.h>
#include <PR/gbi.h>

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

// TODO: NOTE: Make sure DMAs are complete before clearing level!

#define TEXTURE_WIDTH  178 // 74 * 1.2 * 2, round up
#define TEXTURE_HEIGHT 82  // 34 * 1.2 * 2, round up
#define TEXTURE_HEIGHT_4K 11
#define TEXTURE_COUNT 8

struct BSMDMAImageProperties {
    u32 frameStart;
    u32 frameLoopStart;
    u32 frameTotal;
};

enum BSMVideoSafetyStates {
    BSM_VIDEO_UNALLOCATED,
    BSM_VIDEO_UNSAFE,
    BSM_VIDEO_ACTIVE_DMA,
    BSM_VIDEO_SAFE,
};

struct BSMDMAImageProperties bsmDMAProps[BSM_COURSE_COUNT] = {
    [BSM_COURSE_1_SNOWY_PEAK]        = {.frameStart = 0, .frameLoopStart = 0, .frameTotal = 5},
    [BSM_COURSE_2_LAVA_ISLE]         = {.frameStart = 1, .frameLoopStart = 1, .frameTotal = 1},
    [BSM_COURSE_3_FUNGI_CANYON]      = {.frameStart = 2, .frameLoopStart = 2, .frameTotal = 1},
    [BSM_COURSE_4_STARLIGHT_FEST]    = {.frameStart = 3, .frameLoopStart = 3, .frameTotal = 1},
    [BSM_COURSE_5_HOLIDAY_PEAK]      = {.frameStart = 4, .frameLoopStart = 4, .frameTotal = 1},
    [BSM_COURSE_6_SCORCH_ISLE]       = {.frameStart = 5, .frameLoopStart = 5, .frameTotal = 1},
    [BSM_COURSE_7_SPORE_CANYON]      = {.frameStart = 6, .frameLoopStart = 6, .frameTotal = 1},
    [BSM_COURSE_8_CYBER_FEST]        = {.frameStart = 7, .frameLoopStart = 7, .frameTotal = 1},
    [BSM_COURSE_9_CORNERSOFT_PARADE] = {.frameStart = 8, .frameLoopStart = 8, .frameTotal = 1},
};

// NOTE: This has acceptable alignment, but should otherwise be taken into consideration with DMA usage.
#define TEXTURE_SIZE (TEXTURE_WIDTH * TEXTURE_HEIGHT * sizeof(RGBA16))

OSIoMesg bsmMenuImageDMAIoMesg[TEXTURE_COUNT];
OSMesg bsmMenuImageDMAReceivedMesg[TEXTURE_COUNT];
OSMesgQueue bsmMenuImageDMAQueue;

u8 gSafeToLoadVideo = BSM_VIDEO_UNALLOCATED;
u8 sDoubleBufferIndex = 0;
u8 sBSMWaitFrames = BSM_VIDEO_FRAMES_TO_WAIT;
u8 hasInitializedMessageQueue = FALSE;
s32 sImageDMACount = 0;

Texture *bsmDMATextures[2];
u8 bsmDMAMisaligned[2];

u32 bsmImageFrame = 0;
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
}

static void dma_read_image_at_offset(u8 *dest, u8 *relativeAddr) {
    dma_read_image_noblock(dest, (u8 *) ((size_t) relativeAddr + (size_t) _dmaDataSegmentRomStart), (u8 *) ((size_t) relativeAddr + TEXTURE_SIZE + (size_t) _dmaDataSegmentRomStart));
}

static void dma_bsm_frame(u32 imageIndex) {
    Texture *relativeAddr = (Texture *) (imageIndex * TEXTURE_SIZE);
    Texture *dest = bsmDMATextures[sDoubleBufferIndex];
    bsmDMAMisaligned[sDoubleBufferIndex] = (0x10 - ((size_t) relativeAddr & 0xF)) & 0xF;
    sDoubleBufferIndex ^= 1;

    dma_read_image_at_offset(dest, (u8 *) ((size_t) relativeAddr & ~0xF));
}

static void add_menu_frame(void) {
    if (bsmCourseIndex < BSM_COURSE_COUNT) {
        bsmImageFrame++;
        if (bsmImageFrame >= (bsmDMAProps[bsmCourseIndex].frameStart + bsmDMAProps[bsmCourseIndex].frameTotal)) {
            bsmImageFrame = bsmDMAProps[bsmCourseIndex].frameLoopStart;
        }
    }
}

s32 init_menu_video_buffers(UNUSED s16 arg0, UNUSED s32 arg1) {
    gSafeToLoadVideo = BSM_VIDEO_UNALLOCATED;
    bsmImageFrame = 0;
    bsmCourseIndex = BSM_COURSE_1_SNOWY_PEAK;
    sDoubleBufferIndex = 0;
    sBSMWaitFrames = BSM_VIDEO_FRAMES_TO_WAIT;

    u8 *memaddr = main_pool_alloc((ALIGN16(TEXTURE_SIZE) + 16) * ARRAY_COUNT(bsmDMATextures), MEMORY_POOL_LEFT);
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
    bsmDMATextures[0] = &memaddr[0];
    bsmDMATextures[1] = &memaddr[ALIGN16(TEXTURE_SIZE) + 16];
    bsmDMAMisaligned[0] = FALSE;
    bsmDMAMisaligned[1] = FALSE;

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
            bsmImageFrame = bsmDMAProps[bsmCourseIndex].frameStart;
            gSafeToLoadVideo = BSM_VIDEO_ACTIVE_DMA;
        }
    } else {
        gSafeToLoadVideo = BSM_VIDEO_SAFE;
        add_menu_frame();
    }

    dma_bsm_frame(bsmImageFrame);

    return TRUE;
}

s32 check_image_dma_complete(UNUSED s16 arg0, UNUSED s32 arg1) {
    while (sImageDMACount != 0 && osRecvMesg(&bsmMenuImageDMAQueue, NULL, OS_MESG_NOBLOCK) == 0) {
        sImageDMACount--;
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
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPTexture(65535, 65535, 0, 0, 1),
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
	gsSPEndDisplayList(),
};
ALIGNED16 static const Gfx bsm_menu_cutscene_image_0[] = {
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 45, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 0, 0),
    gsDPLoadTile(7, 0, 0, (TEXTURE_WIDTH - 1) << G_TEXTURE_IMAGE_FRAC, (TEXTURE_HEIGHT_4K - 1) << G_TEXTURE_IMAGE_FRAC),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 45, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 4, 0, G_TX_CLAMP | G_TX_NOMIRROR, 8, 0),
    gsDPSetTileSize(0, 0, 0, (TEXTURE_WIDTH - 1) << G_TEXTURE_IMAGE_FRAC, (TEXTURE_HEIGHT_4K - 1) << G_TEXTURE_IMAGE_FRAC),
	gsSPEndDisplayList(),
};
ALIGNED16 static const Gfx bsm_menu_cutscene_image_7[] = {
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 45, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 0, 0),
    gsDPLoadTile(7, 0, 0, (TEXTURE_WIDTH - 1) << G_TEXTURE_IMAGE_FRAC, ((TEXTURE_HEIGHT - (TEXTURE_HEIGHT_4K * 7)) - 1) << G_TEXTURE_IMAGE_FRAC),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 45, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 4, 0, G_TX_CLAMP | G_TX_NOMIRROR, 8, 0),
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
        struct GraphNodeGenerated *currentGraphNode = (struct GraphNodeGenerated *) node;

        if (
            objectGraphNode->behavior != segmented_to_virtual(bhvBSMMenuButtonOrStage) ||
            !obj_has_model(objectGraphNode, MODEL_BSM_MENU_STAGE) ||
            gSafeToLoadVideo != BSM_VIDEO_SAFE ||
            objectGraphNode->oBehParams2ndByte != bsmCourseIndex ||
            objectGraphNode->oAnimState != 0
        ) {
            return NULL;
        }

        SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, LAYER_OPAQUE);
        dlStart = alloc_display_list(sizeof(Gfx) * (5 * ARRAY_COUNT(menu_cutscene_tris) + 3));
        Gfx *dlHead = dlStart;

	    gSPDisplayList(dlHead++, bsm_menu_cutscene_dl_before);

        for (s32 i = 0; i < ARRAY_COUNT(menu_cutscene_tris); i++) {
            gDPTileSync(dlHead++);
            gDPSetTextureImage(dlHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, TEXTURE_WIDTH, bsmDMATextures[sDoubleBufferIndex] + bsmDMAMisaligned[sDoubleBufferIndex] + (i * (TEXTURE_WIDTH*TEXTURE_HEIGHT_4K*sizeof(RGBA16))));
            gSPDisplayList(dlHead++, menu_cutscene_images[i]);
            gSPDisplayList(dlHead++, menu_cutscene_tris[i]);
	        gDPPipeSync(dlHead++);
        }

	    gSPDisplayList(dlHead++, bsm_menu_cutscene_dl_after);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
};