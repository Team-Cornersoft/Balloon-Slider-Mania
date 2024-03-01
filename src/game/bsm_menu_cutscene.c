#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "behavior_data.h"
#include "audio/external.h"
#include "engine/graph_node.h"
#include "engine/math_util.h"
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

#define TEXTURE_WIDTH  182 // 74 * 1.2 * 2, round up
#define TEXTURE_HEIGHT 82  // 34 * 1.2 * 2, round up

struct BSMDMAImageProperties {
    u32 frameStart;
    u32 frameLoopStart;
    u32 frameTotal;
};

enum BSMVideoSafetyStates {
    BSM_VIDEO_UNSAFE,
    BSM_VIDEO_ACTIVE_DMA,
    BSM_VIDEO_SAFE,
};

struct BSMDMAImageProperties bsmDMAProps[BSM_COURSE_COUNT] = {
    [BSM_COURSE_1_SNOWY_PEAK]        = {.frameStart = 0, .frameLoopStart = 0, .frameTotal = 1},
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

OSIoMesg bsmMenuImageDMAIoMesg;
OSMesg bsmMenuImageDMAReceivedMesg;
OSMesgQueue bsmMenuImageDMAQueue;

u8 gSafeToLoadVideo = BSM_VIDEO_UNSAFE;
u8 sDoubleBufferIndex = 0;
u8 sBSMWaitFrames = BSM_VIDEO_FRAMES_TO_WAIT;
s32 sImageDMACount = 0;

Texture *bsmDMATextures[2];

u32 bsmImageFrame = 0;
s32 bsmCourseIndex = BSM_COURSE_1_SNOWY_PEAK;

static void dma_read_image_noblock(u8 *dest, u8 *srcStart, u8 *srcEnd) {
    u32 size = ALIGN16(srcEnd - srcStart);

    osInvalDCache(dest, size);
    while (size != 0) {
        u32 copySize = (size >= 0x1000) ? 0x1000 : size;

        osPiStartDma(&bsmMenuImageDMAIoMesg, OS_MESG_PRI_NORMAL, OS_READ, (uintptr_t) srcStart, dest, copySize,
                     &bsmMenuImageDMAQueue);

        dest += copySize;
        srcStart += copySize;
        size -= copySize;
        sImageDMACount++;
    }
}

static void dma_read_image_at_offset(u8 *dest, u8 *relativeAddr) {
    dma_read_image_noblock(dest, (u8 *) ((size_t) relativeAddr + (size_t) _dmaDataSegmentRomStart), (u8 *) ((size_t) relativeAddr + TEXTURE_SIZE + (size_t) _dmaDataSegmentRomStart));
}

static void dma_bsm_frame(u32 imageIndex) {
    Texture *relativeAddr = (Texture *) (imageIndex * TEXTURE_SIZE);
    Texture *dest = bsmDMATextures[sDoubleBufferIndex];
    sDoubleBufferIndex ^= 1;

    dma_read_image_at_offset(dest, relativeAddr);
}

static void add_menu_frame(void) {
    if (bsmCourseIndex < BSM_COURSE_COUNT) {
        bsmImageFrame++;
        if (bsmImageFrame >= (bsmDMAProps[bsmCourseIndex].frameStart + bsmDMAProps[bsmCourseIndex].frameTotal)) {
            bsmImageFrame = bsmDMAProps[bsmCourseIndex].frameLoopStart;
        }
    }

    if (sBSMWaitFrames > 0) {
        sBSMWaitFrames--;
    }
}

s32 init_menu_video_buffers(UNUSED s16 arg0, UNUSED s32 arg1) {
    gSafeToLoadVideo = BSM_VIDEO_UNSAFE;
    bsmImageFrame = 0;
    bsmCourseIndex = BSM_COURSE_1_SNOWY_PEAK;
    sDoubleBufferIndex = 0;
    sBSMWaitFrames = BSM_VIDEO_FRAMES_TO_WAIT;

    u8 *memaddr = main_pool_alloc(TEXTURE_SIZE * ARRAY_COUNT(bsmDMATextures), MEMORY_POOL_LEFT);
    if (memaddr == NULL) {
        assert(FALSE, "Out of memory! :(");
        return TRUE;
    }

    bsmDMATextures[0] = &memaddr[0];
    bsmDMATextures[1] = &memaddr[TEXTURE_SIZE];

    return TRUE;
}

s32 update_menu_video_buffers(UNUSED s16 arg0, UNUSED s32 arg1) {
    if (gBSMSelectedButton != bsmCourseIndex) {
        gSafeToLoadVideo = BSM_VIDEO_UNSAFE;
        sBSMWaitFrames = BSM_VIDEO_FRAMES_TO_WAIT;
    }

    if (!check_image_dma_complete(0, 0)) {
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
        bsmImageFrame++;
        add_menu_frame();
    }

    dma_bsm_frame(bsmImageFrame);

    return TRUE;
}

s32 check_image_dma_complete(UNUSED s16 arg0, UNUSED s32 arg1) {
    while(sImageDMACount != 0 && osRecvMesg(&bsmMenuImageDMAQueue, NULL, OS_MESG_NOBLOCK) == 0) {
        sImageDMACount--;
    }

    return (sImageDMACount == 0);
}

// TODO:
Gfx *geo_bsm_menu_video_scene(s32 callContext, UNUSED struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *objectGraphNode = (struct Object *) gCurGraphNodeObject;

        if (
            objectGraphNode->behavior != segmented_to_virtual(bhvBSMMenuButtonOrStage) ||
            !obj_has_model(objectGraphNode, MODEL_BSM_MENU_STAGE) ||
            gSafeToLoadVideo != BSM_VIDEO_SAFE ||
            objectGraphNode->oBehParams2ndByte != bsmCourseIndex
        ) {
            return NULL;
        }

        UNUSED Texture *txtr = bsmDMATextures[sDoubleBufferIndex];

        // TODO: load DL and stuff
    }

    return dlStart;
};
