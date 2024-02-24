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

enum BSMMenuLayoutBGState gBSMMenuLayoutBGState = BSM_MENU_LAYOUT_BG_MINIMAL;

struct Object *bsmMenuLevels[BSM_COURSE_COUNT];
struct Object *bsmMenuButtonStats;
struct Object *bsmMenuButtonCredits;

// BEGIN OBJECT CODE

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
                if (obj->oBehParams2ndByte == 0) { // Stats
                    bsmMenuButtonStats = obj;
                } else if (obj->oBehParams2ndByte == 1) { // Credits
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

void bhv_bsm_menu_button_manager_init(void) {
    locate_all_button_objects();
}

void bhv_bsm_menu_button_manager_loop(void) {
    // TODO: remove
    if (gPlayer1Controller->buttonPressed & L_TRIG) {
        gBSMMenuLayoutBGState = (gBSMMenuLayoutBGState + 1) % BSM_MENU_LAYOUT_BG_COUNT;
    }
}

Gfx *geo_bsm_level_select_camera(s32 state, struct GraphNode *node, UNUSED void *context) {
    if (state == GEO_CONTEXT_RENDER) {
        struct GraphNodeCamera *cameraNode = (struct GraphNodeCamera *) node->next;

        if (!cameraNode) {
            return NULL;
        }

        f32 xOffset = BSM_MENU_CAMERA_LAYOUT_FIRST + (gBSMMenuLayoutBGState * BSM_MENU_CAMERA_LAYOUT_INCREMENT);

        cameraNode->pos[0] = xOffset;
        cameraNode->focus[0] = xOffset;

        // TODO: remove
        print_small_text_buffered(SCREEN_CENTER_X, SCREEN_HEIGHT - 14, "<RAINBOW>Press L to swap perspective<RAINBOW>", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
    }

    return NULL;
}
