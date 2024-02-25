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

struct StageProperties {
    u8 levelID;
    char *courseName;
};

enum BSMMenuLayoutBGState gBSMMenuLayoutBGState = BSM_MENU_LAYOUT_BG_MINIMAL;

struct Object *bsmMenuLevels[BSM_COURSE_COUNT];
struct Object *bsmMenuButtonStats;
struct Object *bsmMenuButtonCredits;

static s32 selectedButton = BSM_COURSE_1_SNOWY_PEAK;
static enum BSMMenuSelectionTypes selectionShown = BSM_SELECTION_NONE;

static char strBuffer[128];
static u8 inputStickFlags;
static s8 stickHistory;

static struct StageProperties stageProperties[BSM_COURSE_COUNT] = {
    LEVEL_BOB, "Snowy\nPeak",
    LEVEL_WF,  "Lava\nIsle",
    LEVEL_JRB, "Fungi\nCanyon",
    LEVEL_CCM, "Starlight\nFest",
    LEVEL_BBH, "Holiday\nPeak",
    LEVEL_HMC, "Scorch\nIsle",
    LEVEL_LLL, "Spore\nCanyon",
    LEVEL_SSL, "Cyber\nFest",
    LEVEL_DDD, "Cornersoft\nSecret",
};

static char *creditsStr = {
"\
<COL_FF5F5FFF> ArcticJaguar725<COL_--------> \n\
Programming, Music\n\
\n\
<COL_5FFF5FFF> Mel<COL_--------> \n\
Courses, Models\n\
\n\
<COL_5F5FFFFF> Tools Used<COL_--------> \n\
HackerSM64, fast64\
"
};

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

        if (selectedButton == i) {
            sprintf(strBuffer, "<WAVE>%s<WAVE>", stageProperties[i].courseName);
        } else {
            sprintf(strBuffer, "%s", stageProperties[i].courseName);
        }
        
        print_set_envcolour(255, 255, 255, 255);
        print_small_text_buffered(x, y, strBuffer, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
    }
}

static void bsm_manager_render_stats(void) {
    struct BSMCourseData *bsmData = save_file_get_bsm_data(gCurrSaveFileNum);

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
        s32 y1 = SCREEN_HEIGHT - (s32) (obj->oHomeY * 0.1f) - 11;
        s32 y2 = y1 + 14;

        if (bsmData[i].bestTimeInFrames == 0) {
            sprintf(strBuffer, "No Time");
        } else {
            s32 milliseconds = ((bsmData[i].bestTimeInFrames % 30) * 1000) / 30;
            s32 seconds = (bsmData[i].bestTimeInFrames / 30) % 60;
            s32 minutes = (bsmData[i].bestTimeInFrames / (30 * 60));

            if (minutes >= 10) {
                minutes = 9;
                seconds = 59;
                milliseconds = 999;
            }
            sprintf(strBuffer, "%d:%02d.%03d", minutes, seconds, milliseconds);
        }
        
        print_set_envcolour(255, 255, 255, 255);
        print_small_text_buffered(x, y1, strBuffer, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);

        if (bsmData[i].score == (u16) -1) {
            sprintf(strBuffer, "No Score");
        } else {
            sprintf(strBuffer, "%d", bsmData[i].score);
        }
        print_set_envcolour(255, 255, 255, 255);
        print_small_text_buffered(x, y2, strBuffer, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
    }
}

static void bsm_manager_render_credits(void) {
    print_set_envcolour(255, 255, 255, 255);
    print_small_text_buffered(SCREEN_CENTER_X, SCREEN_HEIGHT * 1 / 4 + 12, creditsStr, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA | (1 << 7) /*Stupid hack to render deferred black box*/);
}

static void bsm_manager_render_update(void) {
    if (
        !obj_is_hidden(bsmMenuLevels[8]) && 
        bsmMenuLevels[BSM_COURSE_9_TCS_CELEBRATION]->oBSMMenuLockObj && 
        !bsmMenuLevels[BSM_COURSE_9_TCS_CELEBRATION]->oBSMMenuStageCutscene
    ) {
        print_set_envcolour(255, 255, 255, 255);
        print_small_text_buffered((s32) (bsmMenuLevels[BSM_COURSE_9_TCS_CELEBRATION]->oHomeX * 0.1f) + SCREEN_CENTER_X + 1,
            SCREEN_HEIGHT - (s32) (bsmMenuLevels[BSM_COURSE_9_TCS_CELEBRATION]->oHomeY * 0.1f) - 4, "x 8", PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
    }

    if (selectionShown != BSM_SELECTION_NONE) {
        if (selectedButton == BSM_COURSE_COUNT + BSM_BUTTON_CREDITS) {
            bsm_manager_render_credits();
        } else if (selectedButton == BSM_COURSE_COUNT + BSM_BUTTON_STATS) {
            bsm_manager_render_stats();
        }
    } else {
        bsm_manager_render_stage_name();
    }
}

static struct Object *get_selcted_menu_object(u8 button) {
    if (button < BSM_COURSE_COUNT) {
        return bsmMenuLevels[button];
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

static void locate_all_button_objects(void) {
    uintptr_t *behaviorAddr = segmented_to_virtual(bhvBSMMenuButtonOrStage);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;

    // Clear out old object references
    for (s32 i = 0; i < BSM_COURSE_COUNT; i++) {
        bsmMenuLevels[i] = NULL;
    }
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
                if (obj->oBehParams2ndByte == BSM_BUTTON_STATS) { // Stats
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
    aggress(bsmMenuButtonStats != NULL, "Missing BSM stats object!");
    aggress(bsmMenuButtonCredits != NULL, "Missing BSM credits object!");
}

void bhv_bsm_menu_button_manager_update_selected_button(void) {
    for (s32 i = 0; i < BSM_COURSE_COUNT; i++) {
        bsmMenuLevels[i]->oBSMMenuIsSelected = FALSE;
    }
    bsmMenuButtonStats->oBSMMenuIsSelected = FALSE;
    bsmMenuButtonCredits->oBSMMenuIsSelected = FALSE;

    get_selcted_menu_object(selectedButton)->oBSMMenuIsSelected = TRUE;
}

static void attempt_selection_move(void) {
    s32 buttonLast = selectedButton;
    
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
            switch (selectedButton) {
                case (BSM_COURSE_COUNT + BSM_BUTTON_STATS):
                    selectedButton = BSM_COURSE_9_TCS_CELEBRATION;
                    break;
                case (BSM_COURSE_COUNT + BSM_BUTTON_CREDITS):
                    selectedButton = BSM_COURSE_COUNT + BSM_BUTTON_STATS;
                    break;
                case BSM_COURSE_9_TCS_CELEBRATION:
                    selectedButton = BSM_COURSE_COUNT + BSM_BUTTON_CREDITS;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_1_SNOWY_PEAK:
                    selectedButton = (BSM_COURSE_ROW_1_END + selectedButton) - 1;
                    break;
                case BSM_COURSE_2_LAVA_ISLE:
                case BSM_COURSE_3_FUNGI_CANYON:
                case BSM_COURSE_4_STARLIGHT_FEST:
                    selectedButton--;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_5_HOLIDAY_PEAK:
                    selectedButton = (selectedButton + (BSM_COURSE_ROW_2_END - BSM_COURSE_ROW_1_END)) - 1;
                    break;
                case BSM_COURSE_6_SCORCH_ISLE:
                case BSM_COURSE_7_SPORE_CANYON:
                case BSM_COURSE_8_CYBER_FEST:
                    selectedButton--;
                    break;
                /////////////////////////////////////////////////////////////////////////
                default:
                    assert(FALSE, "Missed case with menu button navigation!");
            }
        } else if (newFlags & STICK_DOWN) {
            moveMade = TRUE;
            switch (selectedButton) {
                case (BSM_COURSE_COUNT + BSM_BUTTON_STATS):
                    selectedButton = BSM_COURSE_COUNT + BSM_BUTTON_CREDITS;
                    break;
                case (BSM_COURSE_COUNT + BSM_BUTTON_CREDITS):
                    selectedButton = BSM_COURSE_9_TCS_CELEBRATION;
                    break;
                case BSM_COURSE_9_TCS_CELEBRATION:
                    selectedButton = BSM_COURSE_COUNT + BSM_BUTTON_STATS;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_1_SNOWY_PEAK:
                case BSM_COURSE_2_LAVA_ISLE:
                case BSM_COURSE_3_FUNGI_CANYON:
                    selectedButton++;
                    break;
                case BSM_COURSE_4_STARLIGHT_FEST:
                    selectedButton = (selectedButton + 1) - BSM_COURSE_ROW_1_END;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_5_HOLIDAY_PEAK:
                case BSM_COURSE_6_SCORCH_ISLE:
                case BSM_COURSE_7_SPORE_CANYON:
                    selectedButton++;
                    break;
                case BSM_COURSE_8_CYBER_FEST:
                    selectedButton = (selectedButton + 1) - (BSM_COURSE_ROW_2_END - BSM_COURSE_ROW_1_END);
                    break;
                /////////////////////////////////////////////////////////////////////////
                default:
                    assert(FALSE, "Missed case with menu button navigation!");
            }
        } else if (newFlags & STICK_LEFT) {
            moveMade = TRUE;
            switch (selectedButton) {
                case (BSM_COURSE_COUNT + BSM_BUTTON_STATS):
                    selectedButton = BSM_COURSE_6_SCORCH_ISLE;
                    break;
                case (BSM_COURSE_COUNT + BSM_BUTTON_CREDITS):
                    selectedButton = BSM_COURSE_7_SPORE_CANYON;
                    break;
                case BSM_COURSE_9_TCS_CELEBRATION:
                    selectedButton = BSM_COURSE_8_CYBER_FEST;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_1_SNOWY_PEAK:
                case BSM_COURSE_2_LAVA_ISLE:
                    selectedButton = BSM_COURSE_COUNT + BSM_BUTTON_STATS;
                    break;
                case BSM_COURSE_3_FUNGI_CANYON:
                    selectedButton = BSM_COURSE_COUNT + BSM_BUTTON_CREDITS;
                    break;
                case BSM_COURSE_4_STARLIGHT_FEST:
                    selectedButton = BSM_COURSE_9_TCS_CELEBRATION;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_5_HOLIDAY_PEAK:
                case BSM_COURSE_6_SCORCH_ISLE:
                case BSM_COURSE_7_SPORE_CANYON:
                case BSM_COURSE_8_CYBER_FEST:
                    selectedButton -= (BSM_COURSE_ROW_2_END - BSM_COURSE_ROW_1_END);
                    break;
                /////////////////////////////////////////////////////////////////////////
                default:
                    assert(FALSE, "Missed case with menu button navigation!");
            }
        } else if (newFlags & STICK_RIGHT) {
            moveMade = TRUE;
            switch (selectedButton) {
                case (BSM_COURSE_COUNT + BSM_BUTTON_STATS):
                    selectedButton = BSM_COURSE_2_LAVA_ISLE;
                    break;
                case (BSM_COURSE_COUNT + BSM_BUTTON_CREDITS):
                    selectedButton = BSM_COURSE_3_FUNGI_CANYON;
                    break;
                case BSM_COURSE_9_TCS_CELEBRATION:
                    selectedButton = BSM_COURSE_4_STARLIGHT_FEST;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_1_SNOWY_PEAK:
                case BSM_COURSE_2_LAVA_ISLE:
                case BSM_COURSE_3_FUNGI_CANYON:
                case BSM_COURSE_4_STARLIGHT_FEST:
                    selectedButton += BSM_COURSE_ROW_1_END;
                    break;
                /////////////////////////////////////////////////////////////////////////
                case BSM_COURSE_5_HOLIDAY_PEAK:
                case BSM_COURSE_6_SCORCH_ISLE:
                    selectedButton = BSM_COURSE_COUNT + BSM_BUTTON_STATS;
                    break;
                case BSM_COURSE_7_SPORE_CANYON:
                    selectedButton = BSM_COURSE_COUNT + BSM_BUTTON_CREDITS;
                    break;
                case BSM_COURSE_8_CYBER_FEST:
                    selectedButton = BSM_COURSE_9_TCS_CELEBRATION;
                    break;
                /////////////////////////////////////////////////////////////////////////
                default:
                    assert(FALSE, "Missed case with menu button navigation!");
            }
        }

        // Landed on hidden object; iterate a second time
        if (obj_is_hidden(get_selcted_menu_object(selectedButton))) {
            if (safety == 0) {
                selectedButton = BSM_COURSE_1_SNOWY_PEAK;
            }
            continue;
        }

        break;
    }

    if (!moveMade)
        return;

    if (buttonLast != selectedButton) {
        play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource);
    }
}

void bhv_bsm_menu_button_manager_init(void) {
    inputStickFlags = 0;
    stickHistory = 0;
    locate_all_button_objects();
    bhv_bsm_menu_button_manager_update_selected_button();
}

void bhv_bsm_menu_button_manager_loop(void) {
    // Wait a little before processing stuff
    if (o->oTimer < 10) {
        bsm_manager_render_update();
        return;
    }

    if (gPlayer1Controller->buttonPressed & (A_BUTTON | START_BUTTON)) {
        if (selectionShown == BSM_SELECTION_NONE) {
            switch (selectionShown) {
                case BSM_BUTTON_STATS:
                    selectionShown = BSM_SELECTION_STATS;
                    break;
                case BSM_BUTTON_CREDITS:
                    selectionShown = BSM_SELECTION_CREDITS;
                    break;
                default:
                    selectionShown = BSM_SELECTION_STAGE_START_FIRST;
                    break;
            }
        } else {
            switch (selectionShown) {
                case BSM_SELECTION_STATS:
                case BSM_SELECTION_CREDITS:
                    selectionShown = BSM_SELECTION_NONE;
                    break;
                default:
                    break;
            }
        }
    }

    if (selectionShown == BSM_SELECTION_NONE) {
        attempt_selection_move();
    }

    // This should be at the very bottom
    bhv_bsm_menu_button_manager_update_selected_button();
    bsm_manager_render_update();
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

        // TODO: remove
        if (gPlayer1Controller->buttonPressed & L_TRIG) {
            gBSMMenuLayoutBGState = (gBSMMenuLayoutBGState + 1) % BSM_MENU_LAYOUT_BG_COUNT;
        }

        cameraNode->pos[0] = xOffset;
        cameraNode->focus[0] = xOffset;

        cameraNode->pos[2] = Z_POS_OFFSET;
        cameraNode->focus[2] = Z_FOC_OFFSET;

        if (selectionShown != BSM_SELECTION_NONE && selectedButton == BSM_COURSE_COUNT + BSM_BUTTON_CREDITS) {
            cameraNode->pos[2] = Z_POS_OFFSET + Z_OFFSET_MOD;
            cameraNode->focus[2] = Z_FOC_OFFSET + Z_OFFSET_MOD;
        }

        // TODO: remove
        print_small_text_buffered(SCREEN_CENTER_X, SCREEN_HEIGHT - 14, "<RAINBOW>Press L to swap perspective<RAINBOW>", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
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

        if (selectionShown != BSM_SELECTION_NONE && selectedButton == BSM_COURSE_COUNT + BSM_BUTTON_CREDITS) {
            translationNode->translation[1] += TRANSLATE_OFFSET;
        }
    }

    return NULL;
}
