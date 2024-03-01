#ifndef BSM_LEVEL_SELECT_MENU_H
#define BSM_LEVEL_SELECT_MENU_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "types.h"
#include "engine/graph_node.h"

enum BSMMenuLayoutBGState {
    BSM_MENU_LAYOUT_BG_MINIMAL,
    BSM_MENU_LAYOUT_BG_STANDARD,
    BSM_MENU_LAYOUT_BG_BONUS,

    BSM_MENU_LAYOUT_BG_COUNT
};

enum BSMCourses {
    BSM_COURSE_1_SNOWY_PEAK,
    BSM_COURSE_2_LAVA_ISLE,
    BSM_COURSE_3_FUNGI_CANYON,
    BSM_COURSE_4_STARLIGHT_FEST,
    BSM_COURSE_ROW_1_END,

    BSM_COURSE_5_HOLIDAY_PEAK = BSM_COURSE_ROW_1_END,
    BSM_COURSE_6_SCORCH_ISLE,
    BSM_COURSE_7_SPORE_CANYON,
    BSM_COURSE_8_CYBER_FEST,
    BSM_COURSE_ROW_2_END,
    
    BSM_COURSE_9_CORNERSOFT_PARADE = BSM_COURSE_ROW_2_END,

    BSM_COURSE_COUNT,
};

enum BSMMenuButtons {
    BSM_BUTTON_STATS,
    BSM_BUTTON_CREDITS,

    BSM_BUTTON_COUNT,
};

enum BSMMenuSelectionTypes {
    BSM_SELECTION_NONE,
    BSM_SELECTION_CREDITS,
    BSM_SELECTION_STAGE_START_FIRST,
};

struct BSMStageProperties {
    u8 levelID;
    char *courseName;
};

#define BSM_VIDEO_FRAMES_TO_WAIT 15

extern s32 gBSMSelectedButton;
extern enum BSMMenuLayoutBGState gBSMMenuLayoutBGState;
extern enum BSMMenuSelectionTypes gSelectionShown;
extern struct BSMStageProperties gBSMStageProperties[BSM_COURSE_COUNT];

#define BSM_MENU_CAMERA_LAYOUT_FIRST -6000.0f
#define BSM_MENU_CAMERA_LAYOUT_INCREMENT 6000.0f
#define BSM_MENU_CAMERA_LAYOUT_OFFSET (BSM_MENU_CAMERA_LAYOUT_FIRST + (gBSMMenuLayoutBGState * BSM_MENU_CAMERA_LAYOUT_INCREMENT))

s32 init_menu_video_buffers(UNUSED s16 arg0, UNUSED s32 arg1);
s32 update_menu_video_buffers(UNUSED s16 arg0, UNUSED s32 arg1);
s32 check_image_dma_complete(UNUSED s16 arg0, UNUSED s32 arg1);

Gfx *geo_bsm_menu_video_scene(s32 callContext, struct GraphNode *node, UNUSED void *context);
Gfx *geo_bsm_level_select_camera(s32 state, struct GraphNode *node, UNUSED void *context);
Gfx *geo_bsm_make_way_for_credits(s32 state, struct GraphNode *node, UNUSED void *context);

#endif // BSM_LEVEL_SELECT_MENU_H
