#ifndef BSM_LEVEL_SELECT_MENU_H
#define BSM_LEVEL_SELECT_MENU_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "types.h"
#include "engine/graph_node.h"

enum BSMMenuLayoutBGState {
    BSM_MENU_LAYOUT_BG_MINIMAL,
    BSM_MENU_LAYOUT_BG_STANDARD,
    BSM_MENU_LAYOUT_BG_BONUS,

    BSM_MENU_LAYOUT_BG_COUNT
};

extern enum BSMMenuLayoutBGState gBSMMenuLayoutBGState;

#define BSM_MENU_CAMERA_LAYOUT_FIRST -6000.0f
#define BSM_MENU_CAMERA_LAYOUT_INCREMENT 6000.0f
#define BSM_MENU_CAMERA_LAYOUT_OFFSET (BSM_MENU_CAMERA_LAYOUT_FIRST + (gBSMMenuLayoutBGState * BSM_MENU_CAMERA_LAYOUT_INCREMENT))

Gfx *geo_bsm_level_select_camera(s32 state, struct GraphNode *node, UNUSED void *context);

#endif // BSM_LEVEL_SELECT_MENU_H
