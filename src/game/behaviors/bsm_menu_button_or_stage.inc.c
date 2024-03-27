#include "game/save_file.h"
#include "game/puppyprint.h"
#include "game/bsm_level_select_menu.h"

#define FADE_FRAMES 17

static void bhv_bsm_menu_button_or_stage_update_sub_objects(struct Object **obj) {
    struct Object *objRef = *obj;

    if (objRef) {
        if (objRef->activeFlags == ACTIVE_FLAG_DEACTIVATED) {
            *obj = NULL; // Remove the actual source reference of the object that was passed in
        } else if (!(objRef == o->oBSMMenuLockObj && o->oBSMMenuStageCutscene) || o->oTimer < 3) {
            vec3f_copy(objRef->header.gfx.scale, o->header.gfx.scale); // Copy scale

            f32 xDiff = (objRef->oHomeX - o->oHomeX) * objRef->header.gfx.scale[0];
            f32 yDiff = (objRef->oHomeY - o->oHomeY) * objRef->header.gfx.scale[1];

            objRef->oPosX = o->oHomeX + xDiff + BSM_MENU_CAMERA_LAYOUT_OFFSET;
            objRef->oPosY = o->oHomeY + yDiff;
            objRef->header.gfx.node.flags = o->header.gfx.node.flags;
        }
    }
}

static void bhv_bsm_menu_button_or_stage_common(void) {
    if (cur_obj_has_model(MODEL_BSM_MENU_STAGE) &&
        ((o->oBehParams2ndByte >= BSM_COURSE_ROW_1_END && gBSMMenuLayoutBGState < BSM_MENU_LAYOUT_BG_STANDARD) ||
        (o->oBehParams2ndByte >= BSM_COURSE_ROW_2_END && gBSMMenuLayoutBGState < BSM_MENU_LAYOUT_BG_BONUS))
    ) {
        cur_obj_hide();
    } else {
        cur_obj_unhide();
    }

#ifdef BALLOON_SLIDER_MANIA_DISABLE_C9
    if (cur_obj_has_model(MODEL_BSM_MENU_STAGE) && o->oBehParams2ndByte == BSM_COURSE_9_CORNERSOFT_PARADE) {
        o->oAnimState = 1;

        if (gBSMMenuLayoutBGState >= BSM_MENU_LAYOUT_BG_BONUS) {
            s32 x = (o->oHomeX * 0.1f) + SCREEN_CENTER_X;
            s32 y = SCREEN_HEIGHT - (s32) (o->oHomeY * 0.1f) - 10;

            if (gSelectionShown == BSM_SELECTION_NONE) {
                print_small_text_buffered(x, y, "<RAINBOW>COMING\nSOON!<RAINBOW>", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
            }
        }
    }
#endif

    o->oPosX = o->oHomeX + BSM_MENU_CAMERA_LAYOUT_OFFSET;
    bhv_bsm_menu_button_or_stage_update_sub_objects(&o->oBSMMenuLockObj);
    bhv_bsm_menu_button_or_stage_update_sub_objects(&o->oBSMMenuRankObj);
    bhv_bsm_menu_button_or_stage_update_sub_objects(&o->oBSMMenuTCSTokenObj);
}

void bhv_bsm_menu_button_or_stage_init(void) {
    u8 *bsmCompletionFlags = save_file_get_bsm_completion(gCurrSaveFileNum - 1);
    struct BSMCourseData *bsmData = save_file_get_bsm_data(gCurrSaveFileNum - 1);
    s32 buttonId = o->oBehParams2ndByte;
    o->oBSMMenuFrameColor = 0xFFFFFFFF;
    o->oBSMStageFadeTimer = 0;

    if (!cur_obj_has_model(MODEL_BSM_MENU_STAGE)) {
        return; // Process only stages below
    }

#ifdef BALLOON_SLIDER_MANIA_DISABLE_C9
    if (buttonId == BSM_COURSE_9_CORNERSOFT_PARADE) {
        o->oBSMMenuLockObj = spawn_object_relative(buttonId, 0, 0, 20, o, MODEL_NONE, bhvBSMMenuLockOrToken);
    }
#endif

#ifdef DEBUG_LEVEL_SELECT
    if (FALSE) {
#else
    if (!(bsmCompletionFlags[buttonId] & (1 << BSM_STAR_WATCHED_CUTSCENE))) {
#endif
        o->oAnimState = 1;

        if (buttonId < BSM_COURSE_ROW_1_END) {
            o->oBSMMenuLockObj = spawn_object_relative(buttonId, 0, 0, 20, o, MODEL_BSM_MENU_LOCK, bhvBSMMenuLockOrToken);
            // if (TRUE) {
            if (
                gBSMMenuLayoutBGState >= BSM_MENU_LAYOUT_BG_MINIMAL &&
                bsmCompletionFlags[buttonId - 1] & (1 << BSM_STAR_COMPLETED_COURSE)
            ) {
                o->oBSMMenuStageCutscene = TRUE;
            }
        } else if (buttonId < BSM_COURSE_ROW_2_END) {
            o->oBSMMenuLockObj = spawn_object_relative(buttonId, 0, 0, 20, o, MODEL_BSM_MENU_TCSLOCK, bhvBSMMenuLockOrToken);
            // if (TRUE) {
            if (
                gBSMMenuLayoutBGState >= BSM_MENU_LAYOUT_BG_STANDARD &&
                bsmCompletionFlags[buttonId - (BSM_COURSE_ROW_2_END - BSM_COURSE_ROW_1_END)] & (1 << BSM_STAR_COLLECTED_CS_TOKEN)
            ) {
                o->oBSMMenuStageCutscene = TRUE;
            }
        } else {
#ifdef BALLOON_SLIDER_MANIA_DISABLE_C9
            if (!o->oBSMMenuLockObj) {
                o->oBSMMenuLockObj = spawn_object_relative(buttonId, 0, 0, 20, o, MODEL_NONE, bhvBSMMenuLockOrToken);
            }
#else
            s32 tcsTokensCollected = TRUE;
            for (s32 i = 0; i < BSM_COURSE_ROW_2_END; i++) {
                if (!(bsmCompletionFlags[i] & (1 << BSM_STAR_COMPLETED_COURSE))) {
                    tcsTokensCollected = FALSE;
                    break;
                }
            }

            // if (TRUE) {
            if (gBSMMenuLayoutBGState >= BSM_MENU_LAYOUT_BG_BONUS && tcsTokensCollected) {
                o->oBSMMenuLockObj = spawn_object_relative(buttonId, 0, 0, 20, o, MODEL_BSM_MENU_TCSLOCK, bhvBSMMenuLockOrToken);
                o->oBSMMenuStageCutscene = TRUE;
            } else {
                o->oBSMMenuLockObj = spawn_object_relative(buttonId, 0, 0, 20, o, MODEL_BSM_MENU_TCSLOCK_X8, bhvBSMMenuLockOrToken);
            }
#endif
        }

        vec3f_copy(&o->oBSMMenuLockObj->oHomeVec, &o->oBSMMenuLockObj->oPosVec); // Set home
    }

    // if (TRUE) {
    if (bsmData[buttonId].score != (u16) -1) {
        o->oBSMMenuRankObj = spawn_object_relative(buttonId, 340, -140, 20, o, MODEL_BSM_MENU_RANK, bhvBSMMenuRankOrToken);
        vec3f_copy(&o->oBSMMenuRankObj->oHomeVec, &o->oBSMMenuRankObj->oPosVec); // Set home
    }

    // if (TRUE) {
    if (bsmCompletionFlags[buttonId] & (1 << BSM_STAR_COLLECTED_CS_TOKEN)) {
        o->oBSMMenuTCSTokenObj = spawn_object_relative(buttonId, -340, -140, 20, o, MODEL_BSM_MENU_TCSTOKEN, bhvBSMMenuRankOrToken);
        vec3f_copy(&o->oBSMMenuTCSTokenObj->oHomeVec, &o->oBSMMenuTCSTokenObj->oPosVec); // Set home
    }

    bhv_bsm_menu_button_or_stage_common();
}

#define UNLOCK_CUTSCENE_FRAMES 30
#define UNLOCK_CUTSCENE_FRAMES_SCALE 35
#define UNLOCK_CUTSCENE_IDLE_FRAMES 8
void bhv_bsm_menu_button_or_stage_loop(void) {
    f32 scale = o->header.gfx.scale[0];
    s32 buttonId = o->oBehParams2ndByte;

    if (o->oBSMMenuStageCutscene) {
        if (o->oBSMMenuPressed != 0) {
            if (o->oBSMMenuPressed < 0) {
                o->oBSMMenuPressed = UNLOCK_CUTSCENE_FRAMES + UNLOCK_CUTSCENE_IDLE_FRAMES;
            }

            s32 cutsceneFramesLeft = o->oBSMMenuPressed - UNLOCK_CUTSCENE_IDLE_FRAMES;
            s32 cutsceneFramesLeftScale = cutsceneFramesLeft - (UNLOCK_CUTSCENE_FRAMES - UNLOCK_CUTSCENE_FRAMES_SCALE);
            if (cutsceneFramesLeft < 0) {
                scale = smoothstop(scale, 1.0f, 0.1f);
                if (o->oBSMMenuPressed == 1) {
                    o->oFaceAngleYaw = 0;
                    o->oBSMMenuStageCutscene = FALSE;
                    save_file_update_bsm_completion(gCurrSaveFileNum - 1, buttonId, -1, -1, TRUE);
                }
            } else {
                f32 rot = coss(((f32) cutsceneFramesLeft / UNLOCK_CUTSCENE_FRAMES) * 0x8000);
                if (rot >= 0) {
                    o->oAnimState = 0;
                } else {
                    rot = -rot;
                }

                o->oFaceAngleYaw = 0x4000 - (0x4000 * rot);

                scale = sins(((f32) cutsceneFramesLeftScale / (UNLOCK_CUTSCENE_FRAMES_SCALE)) * 0x8000) * 0.15f + 1.0f;
                cur_obj_scale(scale);
            }
        }
    } else if (o->oBSMMenuIsSelected && o->oBSMMenuPressed == 0) {
        scale = smoothstop(scale, 1.2f, 0.2f);
    } else {
        scale = smoothstop(scale, 1.0f, 0.2f);
    }

    cur_obj_scale(scale);

    if (o->oBSMMenuPressed != 0) {
        o->oBSMMenuPressed--;
    }

    bhv_bsm_menu_button_or_stage_common();
}

Gfx *geo_bsm_menu_set_envcolor(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *objectGraphNode = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeGenerated *currentGraphNode = (struct GraphNodeGenerated *) node;
        struct Object *parentNode = objectGraphNode->parentObj;

        if (!parentNode || objectGraphNode->behavior == segmented_to_virtual(bhvBSMMenuButtonOrStage)) {
            parentNode = objectGraphNode;
        }

        if (gCurGraphNodeHeldObject != NULL) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }

        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, LAYER_TRANSPARENT);
        Gfx *dlHead = dlStart;

        if (parentNode->behavior == segmented_to_virtual(bhvBSMMenuButtonOrStage)) {
            f32 r = 1.0f;
            f32 g = 1.0f;
            f32 b = 1.0f;

            if (parentNode->oBSMMenuIsSelected) {
                if (parentNode->oAnimState == 0) {
                    r = (coss(gGlobalTimer * 0x100) + 1) * 0.375f + 0.125f;
                    g = (coss((gGlobalTimer * 0x100) + (0x10000 / 3)) + 1) * 0.375f + 0.125f;
                    b = (coss((gGlobalTimer * 0x100) - (0x10000 / 3)) + 1) * 0.375f + 0.125f;

                    if (r > 1.0f) {
                        r = 1.0f;
                    } else if (r < 0.0f) {
                        r = 0.0f;
                    }
                    if (g > 1.0f) {
                        g = 1.0f;
                    } else if (g < 0.0f) {
                        g = 0.0f;
                    }
                    if (b > 1.0f) {
                        b = 1.0f;
                    } else if (b < 0.0f) {
                        b = 0.0f;
                    }
                } else {
                    r = 0.75f;
                    g = 0.75f;
                    b = 0.75f;
                }
            }

            r = smoothstop((objectGraphNode->oBSMMenuFrameColor >> 24 & 0xFF) / 255.0f, r, 0.15f);
            g = smoothstop((objectGraphNode->oBSMMenuFrameColor >> 16 & 0xFF) / 255.0f, g, 0.15f);
            b = smoothstop((objectGraphNode->oBSMMenuFrameColor >>  8 & 0xFF) / 255.0f, b, 0.15f);

            r *= 255.0f;
            g *= 255.0f;
            b *= 255.0f;

            objectGraphNode->oBSMMenuFrameColor = (objectGraphNode->oBSMMenuFrameColor & 0xFF) | 
                ((u8) r << 24) |
                ((u8) g << 16) |
                ((u8) b << 8);

            gDPSetEnvColor(dlHead++, r, g, b, objectGraphNode->oOpacity);
        } else {
            gDPSetEnvColor(dlHead++, 255, 255, 255, objectGraphNode->oOpacity);
        }

        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}

Gfx *geo_bsm_menu_set_special_transparency(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *objectGraphNode = (struct Object *) gCurGraphNodeObject; // TODO: change this to object pointer?
        struct GraphNodeGenerated *currentGraphNode = (struct GraphNodeGenerated *) node;

        if (gCurGraphNodeHeldObject != NULL) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }

        s32 objectOpacity = 255 - (objectGraphNode->oBSMStageFadeTimer * 255 / FADE_FRAMES);
        objectOpacity = CLAMP_U8(objectOpacity);

        dlStart = alloc_display_list(sizeof(Gfx) * 3);
        Gfx *dlHead = dlStart;

        if (objectOpacity == 0xFF) {
            SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, LAYER_OPAQUE);
        } else {
            SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, LAYER_TRANSPARENT);
        }
    
        gDPSetEnvColor(dlHead++, 255, 255, 255, objectOpacity);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}

Gfx *geo_bsm_menu_switch_alpha_stage(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = gCurGraphNodeObjectNode;

        // move to a local var because GraphNodes are passed in all geo functions.
        // cast the pointer.
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

        if (gCurGraphNodeHeldObject != NULL) {
            obj = gCurGraphNodeHeldObject->objNode;
        }

        if (gSafeToLoadVideo != BSM_VIDEO_SAFE || !obj->oBSMMenuIsSelected) {
            obj->oBSMStageFadeTimer = 0;
            switchCase->selectedCase = 0;
            return NULL;
        }

        if (obj->oBSMStageFadeTimer < FADE_FRAMES) {
            obj->oBSMStageFadeTimer++;
        }

        if (obj->oBSMStageFadeTimer <= FADE_FRAMES) {
            switchCase->selectedCase = 1;
        } else {
            switchCase->selectedCase = 2;
        }
    }

    return NULL;
}
