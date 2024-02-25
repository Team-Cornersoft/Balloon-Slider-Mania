#include "game/save_file.h"
#include "game/puppyprint.h"

static void bhv_bsm_menu_button_or_stage_update_sub_objects(struct Object **obj) {
    struct Object *objRef = *obj;

    if (objRef) {
        if (objRef->activeFlags == ACTIVE_FLAG_DEACTIVATED) {
            *obj = NULL; // Remove the actual source reference of the object that was passed in
        } else {
            objRef->oPosX = objRef->oHomeX + BSM_MENU_CAMERA_LAYOUT_OFFSET;
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

    o->oPosX = o->oHomeX + BSM_MENU_CAMERA_LAYOUT_OFFSET;
    bhv_bsm_menu_button_or_stage_update_sub_objects(&o->oBSMMenuLockObj);
    bhv_bsm_menu_button_or_stage_update_sub_objects(&o->oBSMMenuRankObj);
    bhv_bsm_menu_button_or_stage_update_sub_objects(&o->oBSMMenuTCSTokenObj);
}

void bhv_bsm_menu_button_or_stage_init(void) {
    struct BSMCourseData *bsmData = save_file_get_bsm_data(gCurrSaveFileNum);
    u8 *bsmCompletionFlags = save_file_get_bsm_completion(gCurrSaveFileNum);

    o->oBSMMenuFrameColor = 0xFFFFFFFF;

    s32 buttonId = o->oBehParams2ndByte;

    if (!cur_obj_has_model(MODEL_BSM_MENU_STAGE)) {
        return; // Process only stages below
    }

    // if (FALSE) {
    if (!(bsmCompletionFlags[buttonId] & (1 << BSM_STAR_WATCHED_CUTSCENE))) {
        o->oAnimState = 1;

        if (buttonId < BSM_COURSE_ROW_1_END) {
            o->oBSMMenuLockObj = spawn_object_relative(buttonId, 0, 0, 20, o, MODEL_BSM_MENU_LOCK, bhvBSMMenuLockOrToken);
            if (bsmCompletionFlags[buttonId - 1] & (1 << BSM_STAR_COMPLETED_COURSE)) {
                o->oBSMMenuStageCutscene = TRUE;
            }
        } else if (buttonId < BSM_COURSE_ROW_2_END) {
            o->oBSMMenuLockObj = spawn_object_relative(buttonId, 0, 0, 20, o, MODEL_BSM_MENU_TCSLOCK, bhvBSMMenuLockOrToken);
            if (bsmCompletionFlags[buttonId - (BSM_COURSE_ROW_2_END - BSM_COURSE_ROW_1_END)] & (1 << BSM_STAR_COLLECTED_CS_TOKEN)) {
                o->oBSMMenuStageCutscene = TRUE;
            }
        } else {
            o->oBSMMenuLockObj = spawn_object_relative(buttonId, 0, 0, 20, o, MODEL_BSM_MENU_TCSLOCK, bhvBSMMenuLockOrToken);
            if (bsmData[buttonId].score != (u16) -1) {
                o->oBSMMenuStageCutscene = TRUE;
            } else {
                o->oBSMMenuLockObj->oPosX -= 115.0f;
            }
        }

        vec3f_copy(&o->oBSMMenuLockObj->oHomeVec, &o->oBSMMenuLockObj->oPosVec); // Set home
    }

    if (bsmCompletionFlags[buttonId] & (1 << BSM_STAR_COMPLETED_COURSE)) {
        o->oBSMMenuRankObj = spawn_object_relative(buttonId, 0, 0, 20, o, MODEL_BSM_MENU_RANK, bhvBSMMenuRankOrToken);
        vec3f_copy(&o->oBSMMenuRankObj->oHomeVec, &o->oBSMMenuRankObj->oPosVec); // Set home
    }

    if (bsmCompletionFlags[buttonId] & (1 << BSM_STAR_COLLECTED_CS_TOKEN)) {
        o->oBSMMenuTCSTokenObj = spawn_object_relative(buttonId, 0, 0, 20, o, MODEL_BSM_MENU_TCSTOKEN, bhvBSMMenuRankOrToken);
        vec3f_copy(&o->oBSMMenuTCSTokenObj->oHomeVec, &o->oBSMMenuTCSTokenObj->oPosVec); // Set home
    }

    bhv_bsm_menu_button_or_stage_common();
}

void bhv_bsm_menu_button_or_stage_loop(void) {
    f32 scale = o->header.gfx.scale[0];

    // s32 buttonId = o->oBehParams2ndByte;
    bhv_bsm_menu_button_or_stage_common();

    if (obj_is_hidden(o)) {
        o->oBSMMenuPressed = 0;
        return;
    }

    if (o->oBSMMenuIsSelected && o->oBSMMenuPressed == 0) {
        scale = smoothstop(scale, 1.2f, 0.2f);
    } else {
        scale = smoothstop(scale, 1.0f, 0.2f);
    }

    cur_obj_scale(scale);

    if (o->oBSMMenuPressed != 0) {
        o->oBSMMenuPressed--;
    }

    // struct BSMCourseData *bsmData = save_file_get_bsm_data(gCurrSaveFileNum);
    // u8 *bsmCompletionFlags = save_file_get_bsm_completion(gCurrSaveFileNum);
}

Gfx *geo_bsm_menu_set_envcolor(s32 callContext, struct GraphNode *node, UNUSED void *context) {
    Gfx *dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *objectGraphNode = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeGenerated *currentGraphNode = (struct GraphNodeGenerated *) node;

        if (gCurGraphNodeHeldObject != NULL) {
            objectGraphNode = gCurGraphNodeHeldObject->objNode;
        }

        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, LAYER_TRANSPARENT);
        Gfx *dlHead = dlStart;

        if (objectGraphNode->behavior == segmented_to_virtual(bhvBSMMenuButtonOrStage)) {
            f32 r = 1.0f;
            f32 g = 1.0f;
            f32 b = 1.0f;

            if (objectGraphNode->oBSMMenuIsSelected) {
                if (objectGraphNode->oAnimState == 0) {
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
