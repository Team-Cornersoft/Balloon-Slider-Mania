#include "game/print.h"

const char rankText[] = "RANK: ";

void bhv_bsm_retry_menu_init(void) {
    s32 x = -8 - 16 - 12;
    s32 i = 0;
    while (rankText[i] != '\0') {
        x -= get_clown_font_left_kerning(char_to_glyph_index(rankText[i]));
        x += get_clown_font_right_kerning(char_to_glyph_index(rankText[i]));
        i++;
    }

    o->oBSMRetryMenuRankObj = spawn_object_abs_with_rot(o, 0, MODEL_BSM_MENU_RANK, bhvBSMRetryMenuRank,
        x * 10, (SCREEN_CENTER_Y - 16 + 9) * 10, 0, 
        0, 0, 0);

    vec3f_copy(&o->oBSMRetryMenuRankObj->oHomeVec, &o->oBSMRetryMenuRankObj->oPosVec); // Set home
}

void bhv_bsm_retry_menu_loop(void) {
    char buf[32];
    gClownFontColor[0] = 255;
    gClownFontColor[1] = 255;
    gClownFontColor[2] = 255;

    if (o->oAction == 0) {
        if (o->oTimer < 10) {
            gClownFontColor[3] = 0;
            gBSMRetryMenuScale = sins(0x4000 * o->oTimer / 7) * 1.03f;

            if (gBSMRetryMenuScale < 1.0f && o->oTimer > 7) {
                gBSMRetryMenuScale = 1.0f;
            }

            return;
        }

        gBSMRetryMenuScale = 1.0f;

        if (gClownFontColor[3] + 16 > 255) {
            gClownFontColor[3] = 255;
        } else {
            gClownFontColor[3] += 16;
        }

        print_text_centered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 48, "TOO BAD!");

        sprintf(buf, "SCORE: %d", gBSMScoreCount);
        print_text_centered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 12, buf);

        print_text_centered(SCREEN_CENTER_X - 8, SCREEN_CENTER_Y - 16, rankText);

        print_text_centered(SCREEN_CENTER_X - 54, SCREEN_CENTER_Y - 64, "RETRY");
        print_text_centered(SCREEN_CENTER_X + 54, SCREEN_CENTER_Y - 64, "QUIT");
    }
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

        if (objectGraphNode->behavior != segmented_to_virtual(bhvBSMRetryMenuRank)) {
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
