void bhv_bsm_menu_button_or_stage_init(void) {
    o->oAnimState = 0; // TODO: is stage unlocked?
}

void bhv_bsm_menu_button_or_stage_loop(void) {
    o->oPosX = o->oHomeX + BSM_MENU_CAMERA_LAYOUT_OFFSET;

    if (cur_obj_has_model(MODEL_BSM_MENU_STAGE) &&
        ((o->oBehParams2ndByte >= 4 && gBSMMenuLayoutBGState < BSM_MENU_LAYOUT_BG_STANDARD) ||
        (o->oBehParams2ndByte >= 8 && gBSMMenuLayoutBGState < BSM_MENU_LAYOUT_BG_BONUS))
    ) {
        cur_obj_hide();
    } else {
        cur_obj_unhide();
    }
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
