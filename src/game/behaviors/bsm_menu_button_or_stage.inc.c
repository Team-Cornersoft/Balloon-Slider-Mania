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
        ((o->oBehParams2ndByte >= 4 && gBSMMenuLayoutBGState < BSM_MENU_LAYOUT_BG_STANDARD) ||
        (o->oBehParams2ndByte >= 8 && gBSMMenuLayoutBGState < BSM_MENU_LAYOUT_BG_BONUS))
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

    s32 buttonId = o->oBehParams2ndByte;

    if (!cur_obj_has_model(MODEL_BSM_MENU_STAGE)) {
        return; // Process only stages below
    }

    // if (!(bsmCompletionFlags[buttonId] & (1 << BSM_STAR_WATCHED_CUTSCENE))) {
    if (FALSE) {
        o->oAnimState = 1;

        if (buttonId < 4) {
            o->oBSMMenuLockObj = spawn_object_relative(buttonId, 0, 0, 20, o, MODEL_BSM_MENU_LOCK, bhvBSMMenuLockOrToken);
            if (bsmCompletionFlags[buttonId - 1] & (1 << BSM_STAR_COMPLETED_COURSE)) {
                o->oBSMMenuStageCutscene = TRUE;
            }
        } else if (buttonId < 8) {
            o->oBSMMenuLockObj = spawn_object_relative(buttonId, 0, 0, 20, o, MODEL_BSM_MENU_TCSLOCK, bhvBSMMenuLockOrToken);
            if (bsmCompletionFlags[buttonId - 4] & (1 << BSM_STAR_COLLECTED_CS_TOKEN)) {
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
    // s32 buttonId = o->oBehParams2ndByte;
    bhv_bsm_menu_button_or_stage_common();

    if (obj_is_hidden(o)) {
        return;
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
        gDPSetEnvColor(dlHead++, 255, 255, 255, objectGraphNode->oOpacity);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}
