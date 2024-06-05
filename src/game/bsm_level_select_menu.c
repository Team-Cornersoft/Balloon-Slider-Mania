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
#include "hud.h"
#include "ingame_menu.h"
#include "level_update.h"
#include "object_helpers.h"
#include "object_list_processor.h"
#include "print.h"
#include "save_file.h"
#include "segment2.h"
#include "segment7.h"
#include "spawn_object.h"
#include "sm64.h"
#ifdef PUPPYPRINT
#include "puppyprint.h"
#endif

#define FRAMES_TO_CONTINUE 5
#define FRAMES_TO_WAIT_AFTER_FIRST 15
#define STICK_TRIGGER_ON 54.0f
#define STICK_TRIGGER_OFF 52.0f
#define STICK_UP (1 << 0)
#define STICK_DOWN (1 << 1)
#define STICK_LEFT (1 << 2)
#define STICK_RIGHT (1 << 3)
#define STICK_DIRECTIONS 4

enum BSMMenuLayoutBGState gBSMMenuLayoutBGState = BSM_MENU_LAYOUT_BG_MINIMAL;
enum BSMMenuSelectionTypes gSelectionShown = BSM_SELECTION_NONE;
enum BSMMenuGameplayMode gBSMGameplayMode = BSM_MENU_GAMEPLAY_MODE_MANIA;
u8 gBSMInitialized = FALSE;
u8 gUsingEliseModel = FALSE;
u8 gDisplayEliseMessage = FALSE;
u8 gDisplayGoldMarioMessage = FALSE;
u8 gDisplayWingMarioMessage = FALSE;

u8 bsmTrackSelectNarratorSpoken = FALSE;

static u32 bsmNarratorRankFList[] = {
    SOUND_NARRATION_BSM_RANK_F_0,
    SOUND_NARRATION_BSM_RANK_F_1,
    SOUND_NARRATION_BSM_RANK_F_2,
};
static u32 bsmNarratorRankDList[] = {
    SOUND_NARRATION_BSM_RANK_D_0,
    SOUND_NARRATION_BSM_RANK_D_1,
    SOUND_NARRATION_BSM_RANK_D_2,
};
static u32 bsmNarratorRankCList[] = {
    SOUND_NARRATION_BSM_RANK_C_0,
    SOUND_NARRATION_BSM_RANK_C_1,
    SOUND_NARRATION_BSM_RANK_C_2,
};
static u32 bsmNarratorRankBList[] = {
    SOUND_NARRATION_BSM_RANK_B_0,
    SOUND_NARRATION_BSM_RANK_B_1,
    SOUND_NARRATION_BSM_RANK_B_2,
};
static u32 bsmNarratorRankAList[] = {
    SOUND_NARRATION_BSM_RANK_A_0,
    SOUND_NARRATION_BSM_RANK_A_1,
    SOUND_NARRATION_BSM_RANK_A_2,
};
static u32 bsmNarratorRankSList[] = {
    SOUND_NARRATION_BSM_RANK_S_0,
    SOUND_NARRATION_BSM_RANK_S_1,
    SOUND_NARRATION_BSM_RANK_S_2,
};
static u32 bsmNarratorRankGList[] = {
    SOUND_NARRATION_BSM_RANK_G_0,
    SOUND_NARRATION_BSM_RANK_G_1,
    SOUND_NARRATION_BSM_RANK_G_2,
};
static u32 bsmNarratorVictoryList[] = {
    SOUND_NARRATION_BSM_VICTORY_0,
    SOUND_NARRATION_BSM_VICTORY_1,
    SOUND_NARRATION_BSM_VICTORY_2,
    SOUND_NARRATION_BSM_VICTORY_3,
};
static u32 bsmNarratorFailList[] = {
    SOUND_NARRATION_BSM_FAIL_0,
    SOUND_NARRATION_BSM_FAIL_1,
    SOUND_NARRATION_BSM_FAIL_2,
    SOUND_NARRATION_BSM_FAIL_3,
};
static u32 bsmNarratorItemList[] = {
    SOUND_NARRATION_BSM_ITEM_0,
    SOUND_NARRATION_BSM_ITEM_1,
    SOUND_NARRATION_BSM_ITEM_2,
    SOUND_NARRATION_BSM_ITEM_3,
    SOUND_NARRATION_BSM_ITEM_4,
};
static u32 bsmNarratorRedsList[] = {
    SOUND_NARRATION_BSM_REDS_0,
    SOUND_NARRATION_BSM_REDS_1,
    SOUND_NARRATION_BSM_REDS_2,
    SOUND_NARRATION_BSM_REDS_3,
};
static u32 bsmNarratorTrackselectList[] = {
    SOUND_NARRATION_BSM_TRACKSELECT_0,
    SOUND_NARRATION_BSM_TRACKSELECT_1,
    SOUND_NARRATION_BSM_TRACKSELECT_2,
    SOUND_NARRATION_BSM_TRACKSELECT_3,
};
static u32 bsmNarratorReadyList[] = {
    SOUND_NARRATION_BSM_READY_0,
    SOUND_NARRATION_BSM_READY_1,
    SOUND_NARRATION_BSM_READY_2,
};
static u32 bsmNarratorGoList[] = {
    SOUND_NARRATION_BSM_GO_0,
    SOUND_NARRATION_BSM_GO_1,
    SOUND_NARRATION_BSM_GO_2,
};
static u32 bsmNarratorPBTimeList[] = {
    SOUND_NARRATION_BSM_PB_TIME_0,
    SOUND_NARRATION_BSM_PB_TIME_1,
    SOUND_NARRATION_BSM_PB_TIME_2,
    SOUND_NARRATION_BSM_PB_TIME_3,
};
static u32 bsmNarratorManiaModeList[] = {
    SOUND_NARRATION_BSM_MANIA_MODE_0,
    SOUND_NARRATION_BSM_MANIA_MODE_1,
    SOUND_NARRATION_BSM_MANIA_MODE_2,
};
static u32 bsmNarratorTimeTrialsList[] = {
    SOUND_NARRATION_BSM_TIME_TRIALS_0,
    SOUND_NARRATION_BSM_TIME_TRIALS_1,
    SOUND_NARRATION_BSM_TIME_TRIALS_2,
};

struct BSMNarratorList gBSMNarratorRankF       = {bsmNarratorRankFList,       -1, ARRAY_COUNT(bsmNarratorRankFList)      };
struct BSMNarratorList gBSMNarratorRankD       = {bsmNarratorRankDList,       -1, ARRAY_COUNT(bsmNarratorRankDList)      };
struct BSMNarratorList gBSMNarratorRankC       = {bsmNarratorRankCList,       -1, ARRAY_COUNT(bsmNarratorRankCList)      };
struct BSMNarratorList gBSMNarratorRankB       = {bsmNarratorRankBList,       -1, ARRAY_COUNT(bsmNarratorRankBList)      };
struct BSMNarratorList gBSMNarratorRankA       = {bsmNarratorRankAList,       -1, ARRAY_COUNT(bsmNarratorRankAList)      };
struct BSMNarratorList gBSMNarratorRankS       = {bsmNarratorRankSList,       -1, ARRAY_COUNT(bsmNarratorRankSList)      };
struct BSMNarratorList gBSMNarratorRankG       = {bsmNarratorRankGList,       -1, ARRAY_COUNT(bsmNarratorRankGList)      };
struct BSMNarratorList gBSMNarratorVictory     = {bsmNarratorVictoryList,     -1, ARRAY_COUNT(bsmNarratorVictoryList)    };
struct BSMNarratorList gBSMNarratorFail        = {bsmNarratorFailList,        -1, ARRAY_COUNT(bsmNarratorFailList)       };
struct BSMNarratorList gBSMNarratorItem        = {bsmNarratorItemList,        -1, ARRAY_COUNT(bsmNarratorItemList)       };
struct BSMNarratorList gBSMNarratorReds        = {bsmNarratorRedsList,        -1, ARRAY_COUNT(bsmNarratorRedsList)       };
struct BSMNarratorList gBSMNarratorTrackselect = {bsmNarratorTrackselectList, -1, ARRAY_COUNT(bsmNarratorTrackselectList)};
struct BSMNarratorList gBSMNarratorReady       = {bsmNarratorReadyList,       -1, ARRAY_COUNT(bsmNarratorReadyList)      };
struct BSMNarratorList gBSMNarratorGo          = {bsmNarratorGoList,          -1, ARRAY_COUNT(bsmNarratorGoList)         };
struct BSMNarratorList gBSMNarratorPBTime      = {bsmNarratorPBTimeList,      -1, ARRAY_COUNT(bsmNarratorPBTimeList)     };
struct BSMNarratorList gBSMNarratorManiaMode   = {bsmNarratorManiaModeList,   -1, ARRAY_COUNT(bsmNarratorManiaModeList)  };
struct BSMNarratorList gBSMNarratorTimeTrials  = {bsmNarratorTimeTrialsList,  -1, ARRAY_COUNT(bsmNarratorTimeTrialsList) };

struct BSMStageProperties gBSMStageProperties[BSM_COURSE_COUNT] = {
    {.levelID = LEVEL_BOB, .baselineTime = 110 * 30, .developerTime = 2050, .courseName = "Snowy\nPeak"       , .courseNameNoNewline = "Snowy Peak"       },
    {.levelID = LEVEL_WF,  .baselineTime =  60 * 30, .developerTime = 1508, .courseName = "Aqueduct\nFlow"    , .courseNameNoNewline = "Aqueduct Flow"    },
    {.levelID = LEVEL_JRB, .baselineTime =  90 * 30, .developerTime = 1594, .courseName = "Fungi\nCanyon"     , .courseNameNoNewline = "Fungi Canyon"     },
    {.levelID = LEVEL_CCM, .baselineTime = 140 * 30, .developerTime = 2937, .courseName = "Starlight\nFest"   , .courseNameNoNewline = "Starlight Fest"   },
    {.levelID = LEVEL_BBH, .baselineTime =  95 * 30, .developerTime = 1710, .courseName = "Holiday\nPeak"     , .courseNameNoNewline = "Holiday Peak"     },
    {.levelID = LEVEL_HMC, .baselineTime = 110 * 30, .developerTime = 2190, .courseName = "Dragon\nFlow"      , .courseNameNoNewline = "Dragon Flow"      },
    {.levelID = LEVEL_LLL, .baselineTime =  75 * 30, .developerTime = 1739, .courseName = "Twilight\nCanyon"  , .courseNameNoNewline = "Twilight Canyon"  },
    {.levelID = LEVEL_SSL, .baselineTime = 120 * 30, .developerTime = 2730, .courseName = "Cyber\nFest"       , .courseNameNoNewline = "Cyber Fest"       },
    {.levelID = LEVEL_DDD, .baselineTime = 150 * 30, .developerTime = 3864, .courseName = "Cornersoft\nParade", .courseNameNoNewline = "Cornersoft Parade"},

};

struct Object *bsmMenuLevels[BSM_COURSE_COUNT];
struct Object *bsmMenuButtonTimeTrials;
struct Object *bsmMenuButtonStats;
struct Object *bsmMenuButtonCredits;

s32 gBSMSelectedButton = BSM_COURSE_1_SNOWY_PEAK;
struct BSMStatsShow gBSMShowStats;

static u16 warpTransitionOffsets[ARRAY_COUNT(gFBEWarpTransitionProps)];

static char strBuffer[128];
static u8 inputStickFlags;
static s8 stickHistory;

void play_narrator_sound_at_random(struct BSMNarratorList *list) {
    s32 soundCount = list->soundCount;
    s32 shouldSkipASound = (list->lastAccessed >= 0 && list->soundCount > 1);
    if (shouldSkipASound) {
        soundCount--;
    }
    s32 soundIndex = random_u16() % soundCount;

    if (shouldSkipASound && soundIndex >= list->lastAccessed) {
        soundIndex++;
    }

    play_sound(list->sfxArray[soundIndex], gGlobalSoundSource);
    list->lastAccessed = soundIndex;
}

struct Object *get_selcted_menu_object(u8 button) {
    if (button < BSM_COURSE_COUNT) {
        return bsmMenuLevels[button];
    }
    if (button == BSM_COURSE_COUNT + BSM_BUTTON_TIME_TRIALS) {
        return bsmMenuButtonTimeTrials;
    }
    if (button == BSM_COURSE_COUNT + BSM_BUTTON_STATS) {
        return bsmMenuButtonStats;
    }
    if (button == BSM_COURSE_COUNT + BSM_BUTTON_CREDITS) {
        return bsmMenuButtonCredits;
    }

    error("Attempted to get invalid menu button!");
    return NULL;
}

static void bsm_manager_render_stage_name(void) {
    for (s32 i = 0; i < BSM_COURSE_COUNT; i++) {
        struct Object *obj = bsmMenuLevels[i];

        if (
            obj_is_hidden(obj) ||
            obj->oBSMMenuLockObj ||
            obj->oBSMMenuStageCutscene
        ) {
            continue;
        }

        s32 x = (obj->oHomeX * 0.1f) + SCREEN_CENTER_X;
        s32 y = SCREEN_HEIGHT - (s32) (obj->oHomeY * 0.1f) - 10;

        if (get_selcted_menu_object(i)->oBSMMenuIsSelected) {
            sprintf(strBuffer, "<WAVE>%s<WAVE>", gBSMStageProperties[i].courseName);
        } else {
            sprintf(strBuffer, "%s", gBSMStageProperties[i].courseName);
        }
        
        print_set_envcolour(255, 255, 255, 255);
        print_small_text_buffered(x, y, strBuffer, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
    }
}

static void bsm_manager_render_stats(void) {
    const char *wave = "<WAVE>";
    const char *rainbow = "<RAINBOW>";
    struct BSMCourseData *bsmData = save_file_get_bsm_data(gCurrSaveFileNum - 1);

    for (s32 i = 0; i < BSM_COURSE_COUNT; i++) {
        struct Object *obj = bsmMenuLevels[i];

        if (
            obj_is_hidden(obj) ||
            obj->oBSMMenuLockObj ||
            obj->oBSMMenuStageCutscene
        ) {
            continue;
        }

        s32 x = (obj->oHomeX * 0.1f) + SCREEN_CENTER_X;
        s32 y = SCREEN_HEIGHT - (s32) (obj->oHomeY * 0.1f) - 4;

        if (gBSMGameplayMode == BSM_MENU_GAMEPLAY_MODE_TIME_TRIALS) {
            if (bsmData[i].bestTimeInFrames == 0) {
                print_set_envcolour(255, 255, 255, 255);
                if (get_selcted_menu_object(i)->oBSMMenuIsSelected) {
                    sprintf(strBuffer, "<WAVE>No Time<WAVE>");
                } else {
                    sprintf(strBuffer, "No Time");
                }
            } else {
                s32 milliseconds = ((bsmData[i].bestTimeInFrames % 30) * 100) / 30;
                s32 seconds = (bsmData[i].bestTimeInFrames / 30) % 60;
                s32 minutes = (bsmData[i].bestTimeInFrames / (30 * 60));

                if (minutes >= 10) {
                    minutes = 9;
                    seconds = 59;
                    milliseconds = 99;
                }

                u8 displayRainbow = bsm_beat_or_tie_dev_time(i, bsmData[i].bestTimeInFrames);
                u8 displayWave = get_selcted_menu_object(i)->oBSMMenuIsSelected;

                print_set_envcolour(255, 255, 0, 255);
                sprintf(strBuffer, "%s%s%d:%02d.%02d%s%s", displayRainbow ? rainbow : "", displayWave ? wave : "", minutes, seconds, milliseconds, displayWave ? wave : "", displayRainbow ? rainbow : "");
            }

            print_small_text_buffered(x, y, strBuffer, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
        } else {
            s32 yScore = y;
            if (bsmData[i].score == (u16) -1) {
                print_set_envcolour(255, 255, 255, 255);
                if (get_selcted_menu_object(i)->oBSMMenuIsSelected) {
                    print_set_envcolour(255, 255, 255, 255);
                    sprintf(strBuffer, "<WAVE>No Score<WAVE>");
                } else {
                    sprintf(strBuffer, "No Score");
                }
            } else {
                print_set_envcolour(255, 255, 95, 255);
                if (get_selcted_menu_object(i)->oBSMMenuIsSelected) {
                    sprintf(strBuffer, "<WAVE>%d<WAVE>", bsmData[i].score);
                } else {
                    sprintf(strBuffer, "%d", bsmData[i].score);
                }
            }

            print_small_text_buffered(x, yScore, strBuffer, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
        }
    }
}

static void bsm_manager_render_update(void) {
    if (gSelectionShown == BSM_SELECTION_NONE) {
        if (gBSMShowStats.isShowingStats) {
            bsm_manager_render_stats();
        } else {
            bsm_manager_render_stage_name();
        }
    }
}

static void locate_all_button_objects(void) {
    uintptr_t *behaviorAddr = segmented_to_virtual(bhvBSMMenuButtonOrStage);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;

    // Clear out old object references
    for (s32 i = 0; i < BSM_COURSE_COUNT; i++) {
        bsmMenuLevels[i] = NULL;
    }
    bsmMenuButtonTimeTrials = NULL;
    bsmMenuButtonStats = NULL;
    bsmMenuButtonCredits = NULL;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr
            && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
        ) {
            if (obj_has_model(obj, MODEL_BSM_MENU_STAGE)) {
                if (obj->oBehParams2ndByte < BSM_COURSE_COUNT) {
                    bsmMenuLevels[obj->oBehParams2ndByte] = obj;
                }
            } else if (obj_has_model(obj, MODEL_BSM_MENU_BUTTON)) {
                if (obj->oBehParams2ndByte == BSM_BUTTON_TIME_TRIALS) { // Time Trials
                    bsmMenuButtonTimeTrials = obj;
                } else if (obj->oBehParams2ndByte == BSM_BUTTON_STATS) { // Stats
                    bsmMenuButtonStats = obj;
                } else if (obj->oBehParams2ndByte == BSM_BUTTON_CREDITS) { // Credits
                    bsmMenuButtonCredits = obj;
                }
            }
        }

        obj = (struct Object *) obj->header.next;
    }

    // Confirm things were set correctly, otherwise things break and go bad
    for (s32 i = 0; i < BSM_COURSE_COUNT; i++) {
        aggress(bsmMenuLevels[i] != NULL, "Missing BSM stage object(s)!");
    }
    aggress(bsmMenuButtonTimeTrials != NULL, "Missing BSM time trials object!");
    aggress(bsmMenuButtonStats != NULL, "Missing BSM stats object!");
    aggress(bsmMenuButtonCredits != NULL, "Missing BSM credits object!");
}

void bhv_bsm_menu_button_manager_update_selected_button(void) {
    for (s32 i = 0; i < BSM_COURSE_COUNT; i++) {
        bsmMenuLevels[i]->oBSMMenuIsSelected = FALSE;
    }
    bsmMenuButtonTimeTrials->oBSMMenuIsSelected = FALSE;
    bsmMenuButtonStats->oBSMMenuIsSelected = FALSE;
    bsmMenuButtonCredits->oBSMMenuIsSelected = FALSE;

    for (s32 i = 0; i < BSM_COURSE_COUNT; i++) {
        if (bsmMenuLevels[i]->oBSMMenuStageCutscene) {
            return;
        }
    }

    get_selcted_menu_object(gBSMSelectedButton)->oBSMMenuIsSelected = TRUE;
}

static void attempt_selection_move(void) {
    s32 buttonLast = gBSMSelectedButton;
    
    for (s32 i = 0; i < BSM_COURSE_COUNT; i++) {
        if (bsmMenuLevels[i]->oBSMMenuStageCutscene) {
            inputStickFlags = 0;
            stickHistory = 0;
            return;
        }
    }

    // Check for change in stick inputs
    if (gPlayer1Controller->rawStickY <= -STICK_TRIGGER_ON || gPlayer1Controller->buttonDown & D_JPAD) {
        inputStickFlags |= STICK_DOWN;
    } else if (gPlayer1Controller->rawStickY > -STICK_TRIGGER_OFF) {
        inputStickFlags &= ~STICK_DOWN;
    }

    if (gPlayer1Controller->rawStickY >= STICK_TRIGGER_ON || gPlayer1Controller->buttonDown & U_JPAD) {
        inputStickFlags |= STICK_UP;
    } else if (gPlayer1Controller->rawStickY < STICK_TRIGGER_OFF) {
        inputStickFlags &= ~STICK_UP;
    }

    if (gPlayer1Controller->rawStickX <= -STICK_TRIGGER_ON || gPlayer1Controller->buttonDown & L_JPAD) {
        inputStickFlags |= STICK_LEFT;
    } else if (gPlayer1Controller->rawStickX > -STICK_TRIGGER_OFF) {
        inputStickFlags &= ~STICK_LEFT;
    }

    if (gPlayer1Controller->rawStickX >= STICK_TRIGGER_ON || gPlayer1Controller->buttonDown & R_JPAD) {
        inputStickFlags |= STICK_RIGHT;
    } else if (gPlayer1Controller->rawStickX < STICK_TRIGGER_OFF) {
        inputStickFlags &= ~STICK_RIGHT;
    }

    u8 newFlags = 0;
    u8 moveMade = FALSE;

    u8 anyInputsHeld = FALSE;
    // Check whether to progress held inputs
    for (u32 i = 0; i < STICK_DIRECTIONS; i++) {
        if (!(inputStickFlags & (1 << i))) {
            continue;
        }
    
        anyInputsHeld = TRUE;
        if (stickHistory == 0) {
            newFlags |= (1 << i);
        } else if (stickHistory >= FRAMES_TO_WAIT_AFTER_FIRST && ((stickHistory - FRAMES_TO_WAIT_AFTER_FIRST) % FRAMES_TO_CONTINUE) == 0) {
            newFlags |= (1 << i);
            stickHistory = FRAMES_TO_WAIT_AFTER_FIRST;
        }
    }

    if (!anyInputsHeld) {
        stickHistory = 0;
    } else {
        stickHistory++;
    }

    // Some hardcoded code smells or something :D
    for (s32 safety = 7; safety >= 0; safety--) {
        if (newFlags & STICK_UP) {
            moveMade = TRUE;
            switch (gBSMSelectedButton) {
                case (BSM_COURSE_COUNT + BSM_BUTTON_TIME_TRIALS):
                    gBSMSelectedButton = BSM_COURSE_9_CORNERSOFT_PARADE;
                    break;
                case (BSM_COURSE_COUNT + BSM_BUTTON_STATS):
                    gBSMSelectedButton = BSM_COURSE_COUNT + BSM_BUTTON_TIME_TRIALS;
                    break;
                case (BSM_COURSE_COUNT + BSM_BUTTON_CREDITS):
                    gBSMSelectedButton = BSM_COURSE_COUNT + BSM_BUTTON_STATS;
                    break;
                case BSM_COURSE_9_CORNERSOFT_PARADE:
                    gBSMSelectedButton = BSM_COURSE_COUNT + BSM_BUTTON_STATS;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_1_SNOWY_PEAK:
                    gBSMSelectedButton = (BSM_COURSE_ROW_1_END + gBSMSelectedButton) - 1;
                    break;
                case BSM_COURSE_2_LAVA_ISLE:
                case BSM_COURSE_3_FUNGI_CANYON:
                case BSM_COURSE_4_STARLIGHT_FEST:
                    gBSMSelectedButton--;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_5_HOLIDAY_PEAK:
                    gBSMSelectedButton = (gBSMSelectedButton + (BSM_COURSE_ROW_2_END - BSM_COURSE_ROW_1_END)) - 1;
                    break;
                case BSM_COURSE_6_SCORCH_ISLE:
                case BSM_COURSE_7_SPORE_CANYON:
                case BSM_COURSE_8_CYBER_FEST:
                    gBSMSelectedButton--;
                    break;
                /////////////////////////////////////////////////////////////////////////
                default:
                    assert(FALSE, "Missed case with menu button navigation!");
            }
        } else if (newFlags & STICK_DOWN) {
            moveMade = TRUE;
            switch (gBSMSelectedButton) {
                case (BSM_COURSE_COUNT + BSM_BUTTON_TIME_TRIALS):
                    gBSMSelectedButton = BSM_COURSE_COUNT + BSM_BUTTON_STATS;
                    break;
                case (BSM_COURSE_COUNT + BSM_BUTTON_STATS):
                    gBSMSelectedButton = BSM_COURSE_9_CORNERSOFT_PARADE;
                    break;
                case (BSM_COURSE_COUNT + BSM_BUTTON_CREDITS):
                    gBSMSelectedButton = BSM_COURSE_9_CORNERSOFT_PARADE;
                    break;
                case BSM_COURSE_9_CORNERSOFT_PARADE:
                    gBSMSelectedButton = BSM_COURSE_COUNT + BSM_BUTTON_TIME_TRIALS;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_1_SNOWY_PEAK:
                case BSM_COURSE_2_LAVA_ISLE:
                case BSM_COURSE_3_FUNGI_CANYON:
                    gBSMSelectedButton++;
                    break;
                case BSM_COURSE_4_STARLIGHT_FEST:
                    gBSMSelectedButton = (gBSMSelectedButton + 1) - BSM_COURSE_ROW_1_END;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_5_HOLIDAY_PEAK:
                case BSM_COURSE_6_SCORCH_ISLE:
                case BSM_COURSE_7_SPORE_CANYON:
                    gBSMSelectedButton++;
                    break;
                case BSM_COURSE_8_CYBER_FEST:
                    gBSMSelectedButton = (gBSMSelectedButton + 1) - (BSM_COURSE_ROW_2_END - BSM_COURSE_ROW_1_END);
                    break;
                /////////////////////////////////////////////////////////////////////////
                default:
                    assert(FALSE, "Missed case with menu button navigation!");
            }
        } else if (newFlags & STICK_LEFT) {
            moveMade = TRUE;
            switch (gBSMSelectedButton) {
                case (BSM_COURSE_COUNT + BSM_BUTTON_TIME_TRIALS):
                    gBSMSelectedButton = BSM_COURSE_6_SCORCH_ISLE;
                    break;
                case (BSM_COURSE_COUNT + BSM_BUTTON_STATS):
                    gBSMSelectedButton = BSM_COURSE_7_SPORE_CANYON;
                    break;
                case (BSM_COURSE_COUNT + BSM_BUTTON_CREDITS):
                    gBSMSelectedButton = BSM_COURSE_7_SPORE_CANYON;
                    break;
                case BSM_COURSE_9_CORNERSOFT_PARADE:
                    gBSMSelectedButton = BSM_COURSE_8_CYBER_FEST;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_1_SNOWY_PEAK:
                case BSM_COURSE_2_LAVA_ISLE:
                    gBSMSelectedButton = BSM_COURSE_COUNT + BSM_BUTTON_TIME_TRIALS;
                    break;
                case BSM_COURSE_3_FUNGI_CANYON:
                    gBSMSelectedButton = BSM_COURSE_COUNT + BSM_BUTTON_STATS;
                    break;
                case BSM_COURSE_4_STARLIGHT_FEST:
                    gBSMSelectedButton = BSM_COURSE_9_CORNERSOFT_PARADE;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_5_HOLIDAY_PEAK:
                case BSM_COURSE_6_SCORCH_ISLE:
                case BSM_COURSE_7_SPORE_CANYON:
                case BSM_COURSE_8_CYBER_FEST:
                    gBSMSelectedButton -= (BSM_COURSE_ROW_2_END - BSM_COURSE_ROW_1_END);
                    break;
                /////////////////////////////////////////////////////////////////////////
                default:
                    assert(FALSE, "Missed case with menu button navigation!");
            }
        } else if (newFlags & STICK_RIGHT) {
            moveMade = TRUE;
            switch (gBSMSelectedButton) {
                case (BSM_COURSE_COUNT + BSM_BUTTON_TIME_TRIALS):
                    gBSMSelectedButton = BSM_COURSE_2_LAVA_ISLE;
                    break;
                case (BSM_COURSE_COUNT + BSM_BUTTON_STATS):
                    gBSMSelectedButton = BSM_COURSE_3_FUNGI_CANYON;
                    break;
                case (BSM_COURSE_COUNT + BSM_BUTTON_CREDITS):
                    gBSMSelectedButton = BSM_COURSE_3_FUNGI_CANYON;
                    break;
                case BSM_COURSE_9_CORNERSOFT_PARADE:
                    gBSMSelectedButton = BSM_COURSE_4_STARLIGHT_FEST;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_1_SNOWY_PEAK:
                case BSM_COURSE_2_LAVA_ISLE:
                case BSM_COURSE_3_FUNGI_CANYON:
                case BSM_COURSE_4_STARLIGHT_FEST:
                    gBSMSelectedButton += BSM_COURSE_ROW_1_END;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_5_HOLIDAY_PEAK:
                case BSM_COURSE_6_SCORCH_ISLE:
                    gBSMSelectedButton = BSM_COURSE_COUNT + BSM_BUTTON_TIME_TRIALS;
                    break;
                case BSM_COURSE_7_SPORE_CANYON:
                    gBSMSelectedButton = BSM_COURSE_COUNT + BSM_BUTTON_STATS;
                    break;
                case BSM_COURSE_8_CYBER_FEST:
                    gBSMSelectedButton = BSM_COURSE_9_CORNERSOFT_PARADE;
                    break;
                /////////////////////////////////////////////////////////////////////////
                default:
                    assert(FALSE, "Missed case with menu button navigation!");
            }
        }

        // Landed on hidden object; iterate a second time
        if (obj_is_hidden(get_selcted_menu_object(gBSMSelectedButton))) {
            if (safety == 0) {
                gBSMSelectedButton = BSM_COURSE_1_SNOWY_PEAK;
            }
            continue;
        }

        break;
    }

    if (!moveMade)
        return;

    if (buttonLast != gBSMSelectedButton) {
        play_sound(SOUND_EXTRA1_BSM_MENU_CHANGE_SELECTION, gGlobalSoundSource);
    }
}

void bhv_bsm_menu_button_manager_init(void) {
    inputStickFlags = 0;
    stickHistory = 0;
    gBSMShowStats.isShowingStats = FALSE;
    locate_all_button_objects();
    init_image_screen_press_button(0, 0);
    gBSMInitialized = TRUE;
    bsmTrackSelectNarratorSpoken = FALSE;
}

void bhv_bsm_menu_button_manager_loop(void) {
    // Wait a little before processing stuff
    if (o->oTimer < 5) {
        bsm_manager_render_update();
        return;
    }

    if (!bsmTrackSelectNarratorSpoken) {
        if (gBSMGameplayMode == BSM_MENU_GAMEPLAY_MODE_TIME_TRIALS) {
            play_narrator_sound_at_random(&gBSMNarratorTimeTrials);
        } else {
            if (gBSMNarratorTrackselect.lastAccessed < 0) {
                // Don't randomize first playback
                play_sound(gBSMNarratorTrackselect.sfxArray[0], gGlobalSoundSource);
                gBSMNarratorTrackselect.lastAccessed = 0;
            } else {
                play_narrator_sound_at_random(&gBSMNarratorTrackselect);
            }
        }
        bsmTrackSelectNarratorSpoken = TRUE;
    }

    random_u16(); // Progress the RNG

    for (s32 i = 0; i < BSM_COURSE_COUNT; i++) {
        if (bsmMenuLevels[i]->oBSMMenuStageCutscene) {
            inputStickFlags = 0;
            stickHistory = 0;
            bsm_manager_render_update();
            return;
        }
    }

    s32 soundToPlay = NO_SOUND;
    if (gPlayer1Controller->buttonPressed & (A_BUTTON | B_BUTTON | START_BUTTON)) {
        if (gSelectionShown == BSM_SELECTION_NONE) {
            struct Object *obj = get_selcted_menu_object(gBSMSelectedButton);
            soundToPlay = SOUND_MENU_CLICK_FILE_SELECT;

            switch (gBSMSelectedButton) {
                case (BSM_BUTTON_TIME_TRIALS + BSM_COURSE_COUNT):
                    if (gBSMGameplayMode == BSM_MENU_GAMEPLAY_MODE_TIME_TRIALS) {
                        gBSMGameplayMode = BSM_MENU_GAMEPLAY_MODE_MANIA;
                        play_narrator_sound_at_random(&gBSMNarratorManiaMode);
                    } else {
                        gBSMGameplayMode = BSM_MENU_GAMEPLAY_MODE_TIME_TRIALS;
                        play_narrator_sound_at_random(&gBSMNarratorTimeTrials);
                    }
                    break;
                case (BSM_BUTTON_STATS + BSM_COURSE_COUNT):
                    gBSMShowStats.isShowingStats ^= TRUE;
                    break;
                case (BSM_BUTTON_CREDITS + BSM_COURSE_COUNT):
                    gSelectionShown = BSM_SELECTION_CREDITS;
                    break;
                default:
                    if (obj->oBSMMenuLockObj != NULL) {
                        soundToPlay = SOUND_MENU_CAMERA_BUZZ;
                    } else {
                        if (gBSMShowStats.isShowingStats) {
                            gSelectionShown = BSM_SELECTION_DETAILED_STATS;
                            gBSMShowStats.courseId = gBSMSelectedButton;
                        } else {
                            u16 rand, swap;
                            u16 *wProps = &gFBEWarpTransitionProps[0][0];
                            
                            // Initialize array
                            for (s32 i = 0; i < ARRAY_COUNT(warpTransitionOffsets); i++) {
                                warpTransitionOffsets[i] =  i * ARRAY_COUNT(gFBEWarpTransitionProps[0]);
                            }

                            // Randomize array
                            for (s32 i = ARRAY_COUNT(warpTransitionOffsets) - 1; i >= 0; i--) {
                                rand = random_u16() % (i + 1);
                                swap = warpTransitionOffsets[i];
                                warpTransitionOffsets[i] = warpTransitionOffsets[rand];
                                warpTransitionOffsets[rand] = swap;
                            }

                            // Randomize FBE transitions based on randomized array order because random_u16 sucks and is semi-deterministic and stuff
                            for (s32 i = 0; i < ARRAY_COUNT(gFBEWarpTransitionProps); i++) {
                                rand = random_u16();
                                wProps[warpTransitionOffsets[i]] = rand >> 15;
                                wProps[warpTransitionOffsets[i]+1] = rand % 900;
                            }

                            gSelectionShown = BSM_SELECTION_STAGE_START_FIRST + gBSMSelectedButton;
                        }
                    }
                    break;
            }

            obj->oBSMMenuPressed = 2; // Frame animation counter
        } else {
            switch (gSelectionShown) {
                case BSM_SELECTION_CREDITS:
                    gSelectionShown = BSM_SELECTION_NONE;
                    init_image_screen_press_button(0, 0);
                    break;
                case BSM_SELECTION_DETAILED_STATS:
                    gSelectionShown = BSM_SELECTION_NONE;
                    init_image_screen_press_button(0, 0);
                    break;
                default:
                    break;
            }
        }
    }

    if (soundToPlay != NO_SOUND) {
        play_sound(soundToPlay, gGlobalSoundSource);
    }

    if (gSelectionShown == BSM_SELECTION_NONE) {
        attempt_selection_move();
    }

    // This should be at the very bottom
    bhv_bsm_menu_button_manager_update_selected_button();
    bsm_manager_render_update();
}

Gfx *geo_bsm_switch_gameplay_mode(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

        switchCase->selectedCase = gBSMGameplayMode;
        
        if (switchCase->selectedCase >= BSM_MENU_GAMEPLAY_MODE_COUNT) {
            switchCase->selectedCase = 0;
        }
    }

    return NULL;
}

#define Z_POS_OFFSET 1200
#define Z_FOC_OFFSET 0
#define Z_OFFSET_MOD -900
Gfx *geo_bsm_level_select_camera(s32 state, struct GraphNode *node, UNUSED void *context) {
    if (state == GEO_CONTEXT_RENDER) {
        struct GraphNodeCamera *cameraNode = (struct GraphNodeCamera *) node->next;

        if (!cameraNode) {
            return NULL;
        }

        f32 xOffset = BSM_MENU_CAMERA_LAYOUT_FIRST + (gBSMMenuLayoutBGState * BSM_MENU_CAMERA_LAYOUT_INCREMENT);

        cameraNode->pos[0] = xOffset;
        cameraNode->focus[0] = xOffset;

        cameraNode->pos[2] = Z_POS_OFFSET;
        cameraNode->focus[2] = Z_FOC_OFFSET;

        if (gSelectionShown != BSM_SELECTION_NONE && gSelectionShown < BSM_SELECTION_STAGE_START_FIRST) {
            cameraNode->pos[2] = Z_POS_OFFSET + Z_OFFSET_MOD;
            cameraNode->focus[2] = Z_FOC_OFFSET + Z_OFFSET_MOD;
        }

#ifdef DEBUG_LEVEL_SELECT
        if (gPlayer1Controller->buttonPressed & L_TRIG) {
            gBSMMenuLayoutBGState = (gBSMMenuLayoutBGState + 1) % BSM_MENU_LAYOUT_BG_COUNT;
        }
#endif
    }

    return NULL;
}

#define TRANSLATE_OFFSET 2400
Gfx *geo_bsm_make_way_for_credits(s32 state, struct GraphNode *node, UNUSED void *context) {
    if (state == GEO_CONTEXT_RENDER) {
        struct GraphNodeTranslationRotation *translationNode = (struct GraphNodeTranslationRotation *) node->next;

        if (!translationNode) {
            return NULL;
        }

        translationNode->translation[1] = 0;

        if (gSelectionShown != BSM_SELECTION_NONE && gSelectionShown < BSM_SELECTION_STAGE_START_FIRST) {
            translationNode->translation[1] += TRANSLATE_OFFSET;

            renderPressA = TRUE;
            pressAFrames++;
        }
    }

    return NULL;
}
