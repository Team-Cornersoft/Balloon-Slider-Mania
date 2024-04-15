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
    BSM_SELECTION_DETAILED_STATS,
    BSM_SELECTION_STAGE_START_FIRST, // Must be last
};

struct BSMStageProperties {
    u8 levelID;                // Level ID tied to course
    s32 baselineTime;          // Average time expected to complete the course
    s32 developerTime;         // Fastest developer time
    char *courseName;          // Name of the BSM Course
    char *courseNameNoNewline; // Name of the BSM Course, without newlines
};

#define BSM_VIDEO_FRAMES_TO_WAIT 15

enum BSMVideoSafetyStates {
    BSM_VIDEO_UNALLOCATED,
    BSM_VIDEO_UNSAFE,
    BSM_VIDEO_ACTIVE_DMA,
    BSM_VIDEO_SAFE,
};

struct BSMNarratorList {
    u32 *sfxArray;
    s32 lastAccessed;
    s32 soundCount;
};

struct BSMStatsShow {
    u8 isShowingStats;
    u8 courseId;
};

extern struct BSMNarratorList gBSMNarratorRankF;
extern struct BSMNarratorList gBSMNarratorRankD;
extern struct BSMNarratorList gBSMNarratorRankC;
extern struct BSMNarratorList gBSMNarratorRankB;
extern struct BSMNarratorList gBSMNarratorRankA;
extern struct BSMNarratorList gBSMNarratorRankS;
extern struct BSMNarratorList gBSMNarratorRankG;
extern struct BSMNarratorList gBSMNarratorVictory;
extern struct BSMNarratorList gBSMNarratorFail;
extern struct BSMNarratorList gBSMNarratorItem;
extern struct BSMNarratorList gBSMNarratorReds;
extern struct BSMNarratorList gBSMNarratorTrackselect;
extern struct BSMNarratorList gBSMNarratorReady;
extern struct BSMNarratorList gBSMNarratorGo;
extern struct BSMNarratorList gBSMNarratorPBTime;
extern struct BSMNarratorList gBSMNarratorDevTime;
extern struct BSMNarratorList gBSMNarratorGoodTime;
extern struct BSMStatsShow gBSMShowStats;

extern s32 gBSMSelectedButton;
extern enum BSMMenuLayoutBGState gBSMMenuLayoutBGState;
extern enum BSMMenuSelectionTypes gSelectionShown;
extern u8 gBSMInitialized;
extern u8 gUsingEliseModel;
extern u8 gDisplayEliseMessage;
extern struct BSMStageProperties gBSMStageProperties[BSM_COURSE_COUNT];
extern struct Object *bsmMenuLevels[BSM_COURSE_COUNT];

extern u8 gSafeToLoadVideo;

#define BSM_MENU_CAMERA_LAYOUT_FIRST -6000.0f
#define BSM_MENU_CAMERA_LAYOUT_INCREMENT 6000.0f
#define BSM_MENU_CAMERA_LAYOUT_OFFSET (BSM_MENU_CAMERA_LAYOUT_FIRST + (gBSMMenuLayoutBGState * BSM_MENU_CAMERA_LAYOUT_INCREMENT))

s32 init_menu_video_buffers(UNUSED s16 arg0, UNUSED s32 arg1);
s32 update_menu_video_buffers(UNUSED s16 arg0, UNUSED s32 arg1);
s32 check_image_dma_complete(UNUSED s16 arg0, UNUSED s32 arg1);
s32 get_bsm_rank_requirement(s32 courseNum, s32 rank);
s32 calculate_bsm_rank(s32 courseNum, s32 score);
void play_narrator_sound_at_random(struct BSMNarratorList *list);
void play_narrator_sound_at_random_by_rank_id(u8 rankIndex);

struct Object *get_selcted_menu_object(u8 button);

Gfx *geo_bsm_menu_video_scene(s32 callContext, struct GraphNode *node, UNUSED void *context);
Gfx *geo_bsm_level_select_camera(s32 state, struct GraphNode *node, UNUSED void *context);
Gfx *geo_bsm_make_way_for_credits(s32 state, struct GraphNode *node, UNUSED void *context);

#endif // BSM_LEVEL_SELECT_MENU_H
