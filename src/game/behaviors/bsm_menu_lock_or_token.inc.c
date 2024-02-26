#include "game/save_file.h"

void bhv_bsm_menu_lock_or_token_init(void) {
    
}

#define STEP_1_FC 30
#define STEP_2_FC 30
#define STEP_3_FC 30
void bhv_bsm_menu_lock_or_token_loop(void) {
    if (o->parentObj->oBSMMenuStageCutscene) {
        s32 timerOffset = o->oTimer;

        if (timerOffset < STEP_1_FC) {
            return;
        }
        timerOffset -= STEP_1_FC;

        o->oFaceAngleRoll = sins(((f32) timerOffset / 25.0f) * 0x10000) * (f32) 0x1000;

        f32 scale = o->header.gfx.scale[0];
        if (timerOffset < STEP_2_FC) {
            scale = smoothstart(scale, 1.3f, 0.4f);
            cur_obj_scale(scale);
            return;
        }
        timerOffset -= STEP_2_FC;

        if (timerOffset < STEP_3_FC) {
            scale = smoothstart(scale, 0.0f, 0.5f);
            if (scale < 0.0f)
                scale = 0.0f;
            cur_obj_scale(scale);
            return;
        }
        timerOffset -= STEP_3_FC;

        o->parentObj->oBSMMenuPressed = -1;
        obj_mark_for_deletion(o);
    }
}
