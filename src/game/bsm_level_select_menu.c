#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "audio/external.h"
#include "engine/graph_node.h"
#include "engine/math_util.h"
#include "area.h"
#include "bsm_level_select_menu.h"
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

enum BSMMenuLayoutBGState gBSMMenuLayoutBGState = BSM_MENU_LAYOUT_BG_MINIMAL;

Gfx *geo_bsm_level_select_camera(s32 state, struct GraphNode *node, UNUSED void *context) {
    if (state == GEO_CONTEXT_RENDER) {
        struct GraphNodeCamera *cameraNode = (struct GraphNodeCamera *) node->next;

        if (!cameraNode) {
            return NULL;
        }

        // TODO: remove
        if (gPlayer1Controller->buttonPressed & L_TRIG) {
            gBSMMenuLayoutBGState = (gBSMMenuLayoutBGState + 1) % BSM_MENU_LAYOUT_BG_COUNT;
        }

        f32 xOffset = BSM_MENU_CAMERA_LAYOUT_FIRST + (gBSMMenuLayoutBGState * BSM_MENU_CAMERA_LAYOUT_INCREMENT);

        cameraNode->pos[0] = xOffset;
        cameraNode->focus[0] = xOffset;

        // TODO: remove
        print_small_text_buffered(SCREEN_CENTER_X, SCREEN_HEIGHT - 14, "<RAINBOW>Press L to swap perspective<RAINBOW>", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
    }

    return NULL;
}
