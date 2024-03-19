#include "game/print.h"

void bhv_bsm_retry_menu_init(void) {
    
}

void bhv_bsm_retry_menu_loop(void) {
    if (o->oAction == 0) {
        if (o->oTimer < 10) {
            gBSMRetryMenuScale = sins(0x4000 * o->oTimer / 7) * 1.03f;

            if (gBSMRetryMenuScale < 1.0f && o->oTimer > 7) {
                gBSMRetryMenuScale = 1.0f;
            }

            return;
        }

        gBSMRetryMenuScale = 1.0f;

        print_text_centered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 48, "TOO BAD!");
        print_text_centered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 16, "SCORE:");
    }
}