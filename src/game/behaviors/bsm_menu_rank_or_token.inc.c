#include "game/bsm_level_select_menu.h"
#include "game/save_file.h"

static const u16 BSMRankMinimumScores[BSM_COURSE_COUNT][6] = {
/*                                        D     C     B     A     S     G    */
    [BSM_COURSE_1_SNOWY_PEAK]        = {1960, 2128, 2296, 2464, 2632, 2800}, // G * (1.0 - 0.06n)
    [BSM_COURSE_2_LAVA_ISLE]         = {1340, 1480, 1600, 1700, 1780, 1840}, // G - (40 + 20n)
    [BSM_COURSE_3_FUNGI_CANYON]      = {1344, 1505, 1667, 1828, 1989, 2150}, // G * (1.0 - 0.075n)
    [BSM_COURSE_4_STARLIGHT_FEST]    = {1435, 1558, 1681, 1804, 1927, 2050}, // G * (1.0 - 0.06n)
    [BSM_COURSE_5_HOLIDAY_PEAK]      = { 100,  200,  300,  400,  500, 1000},
    [BSM_COURSE_6_SCORCH_ISLE]       = { 100,  200,  300,  400,  500, 1000},
    [BSM_COURSE_7_SPORE_CANYON]      = { 100,  200,  300,  400,  500, 1000},
    [BSM_COURSE_8_CYBER_FEST]        = { 100,  200,  300,  400,  500, 1000},
    [BSM_COURSE_9_CORNERSOFT_PARADE] = { 100,  200,  300,  400,  500, 1000},
};

s32 calculate_bsm_rank(s32 courseNum, s32 score) {
    u8 rank = 0;

    if (score == (u16) -1) {
        return -1;
    }

    for (s32 i = 0; i < ARRAY_COUNT(BSMRankMinimumScores[0]); i++) {
        if (score < BSMRankMinimumScores[courseNum][i]) {
            break;
        }

        rank++;
    }

    return rank;
}

void bhv_bsm_menu_rank_or_token_init(void) {
    if (cur_obj_has_model(MODEL_BSM_MENU_RANK)) {
        struct BSMCourseData *bsmData = save_file_get_bsm_data(gCurrSaveFileNum - 1);
        s32 buttonId = o->parentObj->oBehParams2ndByte;
        s32 rank = calculate_bsm_rank(buttonId, bsmData[buttonId].score);

        if (rank < 0) {
            obj_mark_for_deletion(o);
        }

        o->oAnimState = rank;
    }
}

void bhv_bsm_menu_rank_or_token_loop(void) {
    
}

void bhv_bsm_retry_menu_rank_init(void) {
    s32 rank = calculate_bsm_rank(gBSMLastCourse, gBSMScoreCount);

    if (rank < 0) {
        obj_mark_for_deletion(o);
    }

    o->oAnimState = rank;
}

void bhv_bsm_retry_menu_rank_loop(void) {

}
