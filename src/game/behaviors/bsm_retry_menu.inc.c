#include "game/print.h"

const char rankText[] = "RANK: ";

void bhv_bsm_retry_menu_init(void) {
    s32 x = -8 - 16 - 12;
    s32 selectionObjY = (SCREEN_CENTER_Y - 70 + 8);
    s32 i = 0;

    while (rankText[i] != '\0') {
        x -= get_clown_font_left_kerning(char_to_glyph_index(rankText[i]));
        x += get_clown_font_right_kerning(char_to_glyph_index(rankText[i]));
        i++;
    }


    if (gBSMGameplayMode == BSM_MENU_GAMEPLAY_MODE_TIME_TRIALS) {
        selectionObjY += 32;
    } else {
        o->oBSMRetryMenuRankObj = spawn_object_abs_with_rot(o, 0, MODEL_BSM_MENU_RANK, bhvBSMRetryMenuRank,
            x * 10, (SCREEN_CENTER_Y - 16 + 9) * 10, 0, 
            0, 0, 0);

        vec3f_copy(&o->oBSMRetryMenuRankObj->oHomeVec, &o->oBSMRetryMenuRankObj->oPosVec); // Set home
    }

    struct Object *obj = spawn_object_abs_with_rot(o, 0, MODEL_BSM_RETRY_MENU_RETRY, bhvBSMRetryMenuSelection,
        -54 * 10, selectionObjY * 10, 0, 
        0, 0, 0);
    if (obj) {
        obj->oBehParams2ndByte = 0;
        obj->oBehParams = 0 << 16;
    }

    obj = spawn_object_abs_with_rot(o, 0, MODEL_BSM_RETRY_MENU_QUIT, bhvBSMRetryMenuSelection,
        54 * 10, selectionObjY * 10, 0, 
        0, 0, 0);
    if (obj) {
        obj->oBehParams2ndByte = 1;
        obj->oBehParams = 1 << 16;
    }
}

#define STICK_TRIGGER_ON 54.0f
#define STICK_TRIGGER_OFF 52.0f
#define NUM_RETRY_OPTIONS 2
void bhv_bsm_retry_menu_loop(void) {
    char buf[32];
    gClownFontColor[0] = 255;
    gClownFontColor[1] = 255;
    gClownFontColor[2] = 255;

    if (o->oBSMRetryMenuButtonPressed > 0) {
        o->oBSMRetryMenuButtonPressed--;
    }

    if (gBSMGameplayMode == BSM_MENU_GAMEPLAY_MODE_TIME_TRIALS) {
        print_text_centered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 22, "TOO BAD!");
    } else {
        print_text_centered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 54, "TOO BAD!");

        sprintf(buf, "SCORE: %d", gBSMScoreCount);
        print_text_centered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 12, buf);

        print_text_centered(SCREEN_CENTER_X - 8, SCREEN_CENTER_Y - 16, rankText);
    }

    if (o->oAction == 0) {
        if (o->oTimer == 5) {
            play_narrator_sound_at_random(&gBSMNarratorFail);
        }

        if (o->oTimer < 10) {
            gClownFontColor[3] = 0;
            gBSMRetryMenuScale = sins(0x4000 * o->oTimer / 7) * 1.03f;

            if (gBSMRetryMenuScale < 1.0f && o->oTimer > 7) {
                gBSMRetryMenuScale = 1.0f;

                // Call again to save a frame of fade-in
                o->oAction = 1;
                o->oPrevAction = 1;
                o->oTimer = 0;
                bhv_bsm_retry_menu_loop();
            }

            return;
        } else {
            gBSMRetryMenuScale = 1.0f;
            o->oAction++;
        }
    } else if (o->oAction == 1) {
        if (gPlayer1Controller->rawStickX >= STICK_TRIGGER_ON || gPlayer1Controller->buttonDown & R_JPAD) {
            if (!o->oBSMRetryMenuStickInput) {
                s32 lastInput = o->oBSMRetryMenuSelection;
                o->oBSMRetryMenuStickInput = TRUE;
                o->oBSMRetryMenuSelection++;
                if (o->oBSMRetryMenuSelection >= NUM_RETRY_OPTIONS) {
                    o->oBSMRetryMenuSelection = NUM_RETRY_OPTIONS - 1;
                }
                
                if (lastInput != o->oBSMRetryMenuSelection) {
                    play_sound(SOUND_EXTRA1_BSM_MENU_CHANGE_SELECTION, gGlobalSoundSource);
                }
            }
        } else if (gPlayer1Controller->rawStickX <= -STICK_TRIGGER_ON || gPlayer1Controller->buttonDown & L_JPAD) {
            if (!o->oBSMRetryMenuStickInput) {
                s32 lastInput = o->oBSMRetryMenuSelection;
                o->oBSMRetryMenuStickInput = TRUE;
                o->oBSMRetryMenuSelection--;
                if (o->oBSMRetryMenuSelection < 0) {
                    o->oBSMRetryMenuSelection = 0;
                }
                
                if (lastInput != o->oBSMRetryMenuSelection) {
                    play_sound(SOUND_EXTRA1_BSM_MENU_CHANGE_SELECTION, gGlobalSoundSource);
                }
            }
        } else if (ABS(gPlayer1Controller->rawStickX) < STICK_TRIGGER_OFF) {
            o->oBSMRetryMenuStickInput = FALSE;
        }

        if (gPlayer1Controller->buttonPressed & (A_BUTTON | B_BUTTON | START_BUTTON)) {
            gBSMRetryMenuSelection = o->oBSMRetryMenuSelection;
            o->oAction++; 
            o->oBSMRetryMenuButtonPressed = 2;
            play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource);
        }
    }

    if (gClownFontColor[3] + 16 > 255) {
        gClownFontColor[3] = 255;
    } else {
        gClownFontColor[3] += 16;
    }
}

void bhv_bsm_retry_menu_selection_init(void) {

}

void bhv_bsm_retry_menu_selection_loop(void) {
    f32 scale = o->header.gfx.scale[0];

    if (o->parentObj->oBSMRetryMenuSelection == o->oBehParams2ndByte && o->parentObj->oBSMRetryMenuButtonPressed == 0) {
        scale = smoothstop(scale, 1.3f, 0.2f);
    } else {
        scale = smoothstop(scale, 1.0f, 0.2f);
    }

    cur_obj_scale(scale);
}

Gfx *geo_bsm_retry_menu_set_clownfont_color(s32 callContext, UNUSED struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart = NULL;
    Gfx *dlHead = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *objectGraphNode = (struct Object *) gCurGraphNodeObject; // TODO: change this to object pointer?
        struct GraphNodeGenerated *currentGraphNode = (struct GraphNodeGenerated *) node;

        if (gCurGraphNodeHeldObject != NULL) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }

        if (
            objectGraphNode->behavior != segmented_to_virtual(bhvBSMRetryMenuRank) &&
            objectGraphNode->behavior != segmented_to_virtual(bhvBSMRetryMenuSelection)
        ) {
            return dlStart;
        }
    
        SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, LAYER_TRANSPARENT);
        dlStart = alloc_display_list(sizeof(Gfx) * 2);
        dlHead = dlStart;
        gDPSetEnvColor(dlHead++, gClownFontColor[0], gClownFontColor[1], gClownFontColor[2], gClownFontColor[3]);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}
