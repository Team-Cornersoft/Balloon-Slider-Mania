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
    [BSM_COURSE_8_CYBER_FEST]        = 1950,
    [BSM_COURSE_9_CORNERSOFT_PARADE] = 2405,
};

static const u16 BSMTimeTrialsRanks[BSM_COURSE_COUNT][BSM_NUM_MEDALS] = {
/*                                       Bronze    Silver     Gold      Star    */
    [BSM_COURSE_1_SNOWY_PEAK]        = { 84 * 30,  81 * 30,  78 * 30,  75 * 30},
    [BSM_COURSE_2_LAVA_ISLE]         = { 57 * 30,  55 * 30,  53 * 30,  52 * 30},
    [BSM_COURSE_3_FUNGI_CANYON]      = { 72 * 30,  64 * 30,  58 * 30,  55 * 30},
    [BSM_COURSE_4_STARLIGHT_FEST]    = {116 * 30, 110 * 30, 106 * 30, 103 * 30},
    [BSM_COURSE_5_HOLIDAY_PEAK]      = { 79 * 30,  72 * 30,  67 * 30,  63 * 30},
    [BSM_COURSE_6_SCORCH_ISLE]       = {104 * 30, 101 * 30,  98 * 30,  95 * 30},
    [BSM_COURSE_7_SPORE_CANYON]      = { 68 * 30,  65 * 30,  63 * 30,  61 * 30},
    [BSM_COURSE_8_CYBER_FEST]        = {104 * 30, 101 * 30,  98 * 30,  96 * 30},
    [BSM_COURSE_9_CORNERSOFT_PARADE] = {140 * 30, 135 * 30, 132 * 30, 130 * 30},
};

void play_narrator_sound_at_random_by_rank_id(u8 rankIndex) {
    if (rankIndex >= BSM_NUM_RANKS) {
        return;
    }

    play_narrator_sound_at_random(rankNarratorLists[rankIndex]);
}

void play_narrator_sound_for_time_trials(s32 bsmCourse, s32 newMedal, s32 oldMedal, s32 newTime, s32 oldTime) {
    // If no PB or medal isn't real, early return.
    if (newMedal >= BSM_NUM_MEDALS || oldTime < newTime) {
        return;
    }

    s32 devTime = get_bsm_tt_dev_time_requirement(bsmCourse);

    // If beat dev time for first time, play dev time sound.
    if (devTime < oldTime && devTime >= newTime) {
        play_sound(SOUND_NARRATION_BSM_DEV_TIME, gGlobalSoundSource);
        return;
    }

    // If earning a new medal for first time, play appropriate medal sound.
    if (newMedal >= 0 && newMedal > oldMedal) {
        play_sound(SOUND_NARRATION_BSM_BRONZE_MEDAL + (newMedal << SOUNDARGS_SHIFT_SOUNDID), gGlobalSoundSource);
        return;
    }

    // By process of elimination, this was a PB with no medal promotion.
    play_narrator_sound_at_random(&gBSMNarratorPBTime);
}

s32 get_bsm_rank_requirement(s32 courseNum, s32 rank) {
    return (BSMGRanks[courseNum] * (1.0f - (G_RANK_MULT * ((BSM_NUM_RANKS - 1) - rank))));
}

s32 get_bsm_tt_medal_requirement(s32 courseNum, s32 medal) {
    return BSMTimeTrialsRanks[courseNum][medal];
}

s32 get_bsm_tt_dev_time_requirement(s32 courseNum) {
    return gBSMStageProperties[courseNum].developerTime;
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
    if (time <= 0) {
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

s32 bsm_beat_or_tie_dev_time(s32 courseNum, s32 time) {
    return (time > 0 && (time <= get_bsm_tt_dev_time_requirement(courseNum))); // Tie-inclusive for developer time (<= instead of <)
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
