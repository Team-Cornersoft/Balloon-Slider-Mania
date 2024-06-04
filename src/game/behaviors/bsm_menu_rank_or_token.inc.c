#include "game/bsm_level_select_menu.h"
#include "game/save_file.h"

struct BSMNarratorList *rankNarratorLists[BSM_NUM_RANKS] = {
    &gBSMNarratorRankF,
    &gBSMNarratorRankD,
    &gBSMNarratorRankC,
    &gBSMNarratorRankB,
    &gBSMNarratorRankA,
    &gBSMNarratorRankS,
    &gBSMNarratorRankG,
};

// static const u16 BSMRankMinimumScores[BSM_COURSE_COUNT][BSM_NUM_RANKS-1] = {
// /*                                        D     C     B     A     S     G    */
//     [BSM_COURSE_1_SNOWY_PEAK]        = {1680, 1904, 2128, 2352, 2576, 2800}, // G * (1.0 - 0.08n)
//     [BSM_COURSE_2_LAVA_ISLE]         = {1104, 1252, 1399, 1546, 1693, 1840}, // G - (1.0 - 0.08n)
//     [BSM_COURSE_3_FUNGI_CANYON]      = {1290, 1462, 1634, 1806, 1978, 2150}, // G * (1.0 - 0.08n)
//     [BSM_COURSE_4_STARLIGHT_FEST]    = {1435, 1558, 1681, 1804, 1927, 2050}, // G * (1.0 - 0.08n)
//     [BSM_COURSE_5_HOLIDAY_PEAK]      = { 100,  200,  300,  400,  500, 1000},
//     [BSM_COURSE_6_SCORCH_ISLE]       = { 100,  200,  300,  400,  500, 1000},
//     [BSM_COURSE_7_SPORE_CANYON]      = { 100,  200,  300,  400,  500, 1000},
//     [BSM_COURSE_8_CYBER_FEST]        = { 100,  200,  300,  400,  500, 1000},
//     [BSM_COURSE_9_CORNERSOFT_PARADE] = { 100,  200,  300,  400,  500, 1000},
// };

// s32 calculate_bsm_rank(s32 courseNum, s32 score) {
//     u8 rank = 0;

//     if (score == (u16) -1) {
//         return -1;
//     }

//     for (s32 i = 0; i < ARRAY_COUNT(BSMRankMinimumScores[0]); i++) {
//         if (score < BSMRankMinimumScores[courseNum][i]) {
//             break;
//         }

//         rank++;
//     }

//     return rank;
// }

#define G_RANK_MULT 0.1f

static const u16 BSMGRanks[BSM_COURSE_COUNT] = {
    [BSM_COURSE_1_SNOWY_PEAK]        = 2760,
    [BSM_COURSE_2_LAVA_ISLE]         = 1815,
    [BSM_COURSE_3_FUNGI_CANYON]      = 2085,
    [BSM_COURSE_4_STARLIGHT_FEST]    = 2020,
    [BSM_COURSE_5_HOLIDAY_PEAK]      = 2075,
    [BSM_COURSE_6_SCORCH_ISLE]       = 1890,
    [BSM_COURSE_7_SPORE_CANYON]      = 1790,
    [BSM_COURSE_8_CYBER_FEST]        = 1945,
    [BSM_COURSE_9_CORNERSOFT_PARADE] = 2405,
};

static const u16 BSMTimeTrialsRanks[BSM_COURSE_COUNT][BSM_NUM_MEDALS] = {
/*                                       Br    Sv    Gd    St    */
    [BSM_COURSE_1_SNOWY_PEAK]        = {9999, 9998, 9997, 2071},
    [BSM_COURSE_2_LAVA_ISLE]         = {9999, 9998, 9997, 1521},
    [BSM_COURSE_3_FUNGI_CANYON]      = {9999, 9998, 9997, 1668},
    [BSM_COURSE_4_STARLIGHT_FEST]    = {9999, 9998, 9997, 2746},
    [BSM_COURSE_5_HOLIDAY_PEAK]      = {9999, 9998, 9997, 1743},
    [BSM_COURSE_6_SCORCH_ISLE]       = {9999, 9998, 9997, 2559},
    [BSM_COURSE_7_SPORE_CANYON]      = {9999, 9998, 9997, 1886},
    [BSM_COURSE_8_CYBER_FEST]        = {9999, 9998, 9997, 2805},
    [BSM_COURSE_9_CORNERSOFT_PARADE] = {9999, 9998, 9997, 3873},
};

void play_narrator_sound_at_random_by_rank_id(u8 rankIndex) {
    if (rankIndex >= BSM_NUM_RANKS) {
        return;
    }

    play_narrator_sound_at_random(rankNarratorLists[rankIndex]);
}

s32 get_bsm_rank_requirement(s32 courseNum, s32 rank) {
    return (BSMGRanks[courseNum] * (1.0f - (G_RANK_MULT * ((BSM_NUM_RANKS - 1) - rank))));
}

s32 get_bsm_tt_medal_requirement(s32 courseNum, s32 medal) {
    return BSMTimeTrialsRanks[courseNum][medal];
}

s32 calculate_bsm_rank(s32 courseNum, s32 score) {
    s8 rank = BSM_NUM_RANKS - 1;
    if (score == (u16) -1) {
        return -1;
    }
    
    while (rank > 0) { // Lowest rank is F, which exists as an object (thus >)
        if ((f32) score >= get_bsm_rank_requirement(courseNum, rank)) {
            break;
        }

        rank--;
    }

    return rank;
}

s32 calculate_bsm_tt_medal(s32 courseNum, s32 time) {
    s8 medal = BSM_NUM_MEDALS - 1;
    if (time == 0) {
        return -1;
    }
    
    while (medal >= 0) { // Lowest medal is nothing, which does not exist as an object (thus >=)
        if ((f32) time <= get_bsm_tt_medal_requirement(courseNum, medal)) {
            break;
        }

        medal--;
    }

    return medal;
}

void bhv_bsm_menu_rank_or_token_init(void) {
    if (cur_obj_has_model(MODEL_BSM_MENU_RANK)) {
        struct BSMCourseData *bsmData = save_file_get_bsm_data(gCurrSaveFileNum - 1);
        s32 buttonId = o->parentObj->oBehParams2ndByte;
        s32 rank = calculate_bsm_rank(buttonId, bsmData[buttonId].score);

        if (rank < 0) {
            obj_mark_for_deletion(o);
        } else {
            o->oAnimState = rank;
        }
    }

    if (cur_obj_has_model(MODEL_BSM_MENU_TT_MEDAL)) {
        struct BSMCourseData *bsmData = save_file_get_bsm_data(gCurrSaveFileNum - 1);
        s32 buttonId = o->parentObj->oBehParams2ndByte;
        s32 medal = calculate_bsm_tt_medal(buttonId, bsmData[buttonId].bestTimeInFrames);

        if (medal < 0) {
            obj_mark_for_deletion(o);
        } else {
            o->oAnimState = medal;
        }
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
