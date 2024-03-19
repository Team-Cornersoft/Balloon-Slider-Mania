#include "game/print.h"

void bhv_bsm_retry_menu_init(void) {
    
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
        print_text_centered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 56, "TOO BAD!");

        sprintf(buf, "SCORE: %d", gBSMScoreCount);
        print_text_centered(SCREEN_CENTER_X, SCREEN_CENTER_Y + 16, buf);
    }
}