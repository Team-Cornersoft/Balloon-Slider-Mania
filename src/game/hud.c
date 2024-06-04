#include <PR/ultratypes.h>

#include "sm64.h"
#include "actors/common1.h"
#include "emutest.h"
#include "gfx_dimensions.h"
#include "game_init.h"
#include "level_update.h"
#include "camera.h"
#include "print.h"
#include "ingame_menu.h"
#include "hud.h"
#include "segment2.h"
#include "area.h"
#include "save_file.h"
#include "print.h"
#include "engine/surface_load.h"
#include "engine/math_util.h"
#include "puppycam2.h"
#include "puppyprint.h"

#include "config.h"

/* @file hud.c
 * This file implements HUD rendering and power meter animations.
 * That includes stars, lives, coins, camera status, power meter, timer
 * cannon reticle, and the unused keys.
 **/

s32 gConsoleOffsetDiffX = 0;
s32 gConsoleOffsetDiffY = 0;
s32 gWidescreenViewportOffset = 0;

#ifdef BREATH_METER
#define HUD_BREATH_METER_X         40
#define HUD_BREATH_METER_Y         32
#define HUD_BREATH_METER_HIDDEN_Y -20
#endif

// ------------- FPS COUNTER ---------------
// To use it, call print_fps(x,y); every frame.
#define FRAMETIME_COUNT 30

OSTime frameTimes[FRAMETIME_COUNT];
u8 curFrameTimeIndex = 0;

#include "PR/os_convert.h"

#ifdef USE_PROFILER
float profiler_get_fps();
#else
// Call once per frame
f32 calculate_and_update_fps() {
    OSTime newTime = osGetTime();
    OSTime oldTime = frameTimes[curFrameTimeIndex];
    frameTimes[curFrameTimeIndex] = newTime;

    curFrameTimeIndex++;
    if (curFrameTimeIndex >= FRAMETIME_COUNT) {
        curFrameTimeIndex = 0;
    }
    return ((f32)FRAMETIME_COUNT * 1000000.0f) / (s32)OS_CYCLES_TO_USEC(newTime - oldTime);
}
#endif

void print_fps(s32 x, s32 y) {
#ifdef USE_PROFILER
    f32 fps = profiler_get_fps();
#else
    f32 fps = calculate_and_update_fps();
#endif
    char text[14];

    sprintf(text, "FPS %2.2f", fps);
#ifdef PUPPYPRINT
    print_small_text(x, y, text, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_OUTLINE);
#else
    print_text(x, y, text);
#endif
}

// ------------ END OF FPS COUNER -----------------

struct PowerMeterHUD {
    s8 animation;
    s16 x;
    s16 y;
};

struct CameraHUD {
    s16 status;
};

// Stores health segmented value defined by numHealthWedges
// When the HUD is rendered this value is 8, full health.
static s16 sPowerMeterStoredHealth;

static struct PowerMeterHUD sPowerMeterHUD = {
    POWER_METER_HIDDEN,
    HUD_POWER_METER_X,
    HUD_POWER_METER_HIDDEN_Y,
};

// Power Meter timer that keeps counting when it's visible.
// Gets reset when the health is filled and stops counting
// when the power meter is hidden.
s32 sPowerMeterVisibleTimer = 0;

#ifdef BREATH_METER
static s16 sBreathMeterStoredValue;
static struct PowerMeterHUD sBreathMeterHUD = {
    BREATH_METER_HIDDEN,
    HUD_BREATH_METER_X,
    HUD_BREATH_METER_HIDDEN_Y,
};
s32 sBreathMeterVisibleTimer = 0;
#endif

static struct CameraHUD sCameraHUD = { CAM_STATUS_NONE };

/**
 * Renders a rgba16 16x16 glyph texture from a table list.
 */
void render_hud_tex_lut(s32 x, s32 y, Texture *texture) {
    Gfx *tempGfxHead = gDisplayListHead;

    gDPPipeSync(tempGfxHead++);
    gDPSetTextureImage(tempGfxHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture);
    gSPDisplayList(tempGfxHead++, &dl_hud_img_load_tex_block);
    gSPTextureRectangle(tempGfxHead++, x << 2, y << 2, (x + 15) << 2, (y + 15) << 2,
                        G_TX_RENDERTILE, 0, 0, 4 << 10, 1 << 10);

    gDisplayListHead = tempGfxHead;
}

void render_rgba16_tex_lut(s32 x, s32 y, Texture *texture) {
    Gfx *tempGfxHead = gDisplayListHead;

    gDPPipeSync(tempGfxHead++);
    gDPSetTextureImage(tempGfxHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture);
    gSPDisplayList(tempGfxHead++, &dl_rgba16_load_tex_block);                        
    gSPTextureRectangle(tempGfxHead++, x << 2, y << 2, (x + 16) << 2,
                        (y + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

    gDisplayListHead = tempGfxHead;
}

/**
 * Renders a rgba16 8x8 glyph texture from a table list.
 */
void render_rgba16_small_tex_lut(s32 x, s32 y, Texture *texture) {
    Gfx *tempGfxHead = gDisplayListHead;

    gDPSetTile(tempGfxHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0,
                G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD);
    gDPTileSync(tempGfxHead++);
    gDPSetTile(tempGfxHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0, G_TX_RENDERTILE, 0,
                G_TX_CLAMP, 3, G_TX_NOLOD, G_TX_CLAMP, 3, G_TX_NOLOD);
    gDPSetTileSize(tempGfxHead++, G_TX_RENDERTILE, 0, 0, (8 - 1) << G_TEXTURE_IMAGE_FRAC, (8 - 1) << G_TEXTURE_IMAGE_FRAC);
    gDPPipeSync(tempGfxHead++);
    gDPSetTextureImage(tempGfxHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture);
    gDPLoadSync(tempGfxHead++);
    gDPLoadBlock(tempGfxHead++, G_TX_LOADTILE, 0, 0, 8 * 8 - 1, CALC_DXT(8, G_IM_SIZ_16b_BYTES));
    gSPTextureRectangle(tempGfxHead++, x << 2, y << 2, (x + 8) << 2, (y + 8) << 2, G_TX_RENDERTILE,
                        0, 0, 1 << 10, 1 << 10);

    gDisplayListHead = tempGfxHead;
}

/**
 * Renders power meter health segment texture using a table list.
 */
void render_power_meter_health_segment(s16 numHealthWedges) {
    Texture *(*healthLUT)[] = segmented_to_virtual(&power_meter_health_segments_lut);
    Gfx *tempGfxHead = gDisplayListHead;

    gDPPipeSync(tempGfxHead++);
    gDPSetTextureImage(tempGfxHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1,
                       (*healthLUT)[numHealthWedges - 1]);
    gDPLoadSync(tempGfxHead++);
    gDPLoadBlock(tempGfxHead++, G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES));
    gSP1Triangle(tempGfxHead++, 0, 1, 2, 0);
    gSP1Triangle(tempGfxHead++, 0, 2, 3, 0);

    gDisplayListHead = tempGfxHead;
}

/**
 * Renders power meter display lists.
 * That includes the "POWER" base and the colored health segment textures.
 */
void render_dl_power_meter(s16 numHealthWedges) {
    Mtx *mtx = alloc_display_list(sizeof(Mtx));

    if (mtx == NULL) {
        return;
    }

    guTranslate(mtx, (f32) sPowerMeterHUD.x, (f32) sPowerMeterHUD.y, 0);

    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx++),
              G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPDisplayList(gDisplayListHead++, &dl_power_meter_base);

    if (numHealthWedges != 0) {
        gSPDisplayList(gDisplayListHead++, &dl_power_meter_health_segments_begin);
        render_power_meter_health_segment(numHealthWedges);
        gSPDisplayList(gDisplayListHead++, &dl_power_meter_health_segments_end);
    }

    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

/**
 * Power meter animation called when there's less than 8 health segments
 * Checks its timer to later change into deemphasizing mode.
 */
void animate_power_meter_emphasized(void) {
    s16 hudDisplayFlags = gHudDisplay.flags;

    if (!(hudDisplayFlags & HUD_DISPLAY_FLAG_EMPHASIZE_POWER)) {
        if (sPowerMeterVisibleTimer == 45.0f) {
            sPowerMeterHUD.animation = POWER_METER_DEEMPHASIZING;
        }
    } else {
        sPowerMeterVisibleTimer = 0;
    }
}

/**
 * Power meter animation called after emphasized mode.
 * Moves power meter y pos speed until it's at 200 to be visible.
 */
static void animate_power_meter_deemphasizing(void) {
    s16 speed = 5;

    if (sPowerMeterHUD.y > HUD_POWER_METER_Y - 20) speed = 3;
    if (sPowerMeterHUD.y > HUD_POWER_METER_Y - 10) speed = 2;
    if (sPowerMeterHUD.y > HUD_POWER_METER_Y -  5) speed = 1;

    sPowerMeterHUD.y += speed;

    if (sPowerMeterHUD.y > HUD_POWER_METER_Y) {
        sPowerMeterHUD.y = HUD_POWER_METER_Y;
        sPowerMeterHUD.animation = POWER_METER_VISIBLE;
    }
}

/**
 * Power meter animation called when there's 8 health segments.
 * Moves power meter y pos quickly until it's at 301 to be hidden.
 */
static void animate_power_meter_hiding(void) {
    sPowerMeterHUD.y += 20;
    if (sPowerMeterHUD.y > HUD_POWER_METER_HIDDEN_Y) {
        sPowerMeterHUD.animation = POWER_METER_HIDDEN;
        sPowerMeterVisibleTimer = 0;
    }
}

/**
 * Handles power meter actions depending of the health segments values.
 */
void handle_power_meter_actions(s16 numHealthWedges) {
    // Show power meter if health is not full, less than 8
    if (numHealthWedges < 8 && sPowerMeterStoredHealth == 8
        && sPowerMeterHUD.animation == POWER_METER_HIDDEN) {
        sPowerMeterHUD.animation = POWER_METER_EMPHASIZED;
        sPowerMeterHUD.y = HUD_POWER_METER_EMPHASIZED_Y;
    }

    // Show power meter if health is full, has 8
    if (numHealthWedges == 8 && sPowerMeterStoredHealth == 7) {
        sPowerMeterVisibleTimer = 0;
    }

    // After health is full, hide power meter
    if (numHealthWedges == 8 && sPowerMeterVisibleTimer > 45.0f) {
        sPowerMeterHUD.animation = POWER_METER_HIDING;
    }

    // Update to match health value
    sPowerMeterStoredHealth = numHealthWedges;

#ifndef BREATH_METER
    // If Mario is swimming, keep power meter visible
    if (gPlayerCameraState->action & ACT_FLAG_SWIMMING) {
        if (sPowerMeterHUD.animation == POWER_METER_HIDDEN
            || sPowerMeterHUD.animation == POWER_METER_EMPHASIZED) {
            sPowerMeterHUD.animation = POWER_METER_DEEMPHASIZING;
            sPowerMeterHUD.y = HUD_POWER_METER_EMPHASIZED_Y;
        }
        sPowerMeterVisibleTimer = 0;
    }
#endif
}

/**
 * Renders the power meter that shows when Mario is in underwater
 * or has taken damage and has less than 8 health segments.
 * And calls a power meter animation function depending of the value defined.
 */
void render_hud_power_meter(void) {
    s16 shownHealthWedges = gHudDisplay.wedges;
    if (sPowerMeterHUD.animation != POWER_METER_HIDING) handle_power_meter_actions(shownHealthWedges);
    if (sPowerMeterHUD.animation == POWER_METER_HIDDEN) return;
    switch (sPowerMeterHUD.animation) {
        case POWER_METER_EMPHASIZED:    animate_power_meter_emphasized();    break;
        case POWER_METER_DEEMPHASIZING: animate_power_meter_deemphasizing(); break;
        case POWER_METER_HIDING:        animate_power_meter_hiding();        break;
        default:                                                             break;
    }
    render_dl_power_meter(shownHealthWedges);
    sPowerMeterVisibleTimer++;
}

#ifdef BREATH_METER
/**
 * Renders breath meter health segment texture using a table list.
 */
void render_breath_meter_segment(s16 numBreathWedges) {
    Texture *(*breathLUT)[];
    breathLUT = segmented_to_virtual(&breath_meter_segments_lut);
    Gfx *tempGfxHead = gDisplayListHead;

    gDPPipeSync(tempGfxHead++);
    gDPSetTextureImage(tempGfxHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, (*breathLUT)[numBreathWedges - 1]);
    gDPLoadSync(tempGfxHead++);
    gDPLoadBlock(tempGfxHead++, G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES));
    gSP1Triangle(tempGfxHead++, 0, 1, 2, 0);
    gSP1Triangle(tempGfxHead++, 0, 2, 3, 0);

    gDisplayListHead = tempGfxHead;
}

/**
 * Renders breath meter display lists.
 * That includes the base and the colored segment textures.
 */
void render_dl_breath_meter(s16 numBreathWedges) {
    Mtx *mtx = alloc_display_list(sizeof(Mtx));

    if (mtx == NULL) {
        return;
    }

    guTranslate(mtx, (f32) sBreathMeterHUD.x, (f32) sBreathMeterHUD.y, 0);
    gSPMatrix(      gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx++),
                    G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPDisplayList( gDisplayListHead++, &dl_breath_meter_base);
    if (numBreathWedges != 0) {
        gSPDisplayList(gDisplayListHead++, &dl_breath_meter_health_segments_begin);
        render_breath_meter_segment(numBreathWedges);
        gSPDisplayList(gDisplayListHead++, &dl_breath_meter_health_segments_end);
    }
    gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
}

/**
 * Breath meter animation called after emphasized mode.
 * Moves breath meter y pos speed until it's visible.
 */
static void animate_breath_meter_sliding_in(void) {
    approach_s16_symmetric_bool(&sBreathMeterHUD.y, HUD_BREATH_METER_Y, 5);
    if (sBreathMeterHUD.y         == HUD_BREATH_METER_Y) {
        sBreathMeterHUD.animation = BREATH_METER_VISIBLE;
    }
}

/**
 * Breath meter animation called when there's 8 health segments.
 * Moves breath meter y pos quickly until it's hidden.
 */
static void animate_breath_meter_sliding_out(void) {
    approach_s16_symmetric_bool(&sBreathMeterHUD.y, HUD_BREATH_METER_HIDDEN_Y, 20);
    if (sBreathMeterHUD.y         == HUD_BREATH_METER_HIDDEN_Y) {
        sBreathMeterHUD.animation = BREATH_METER_HIDDEN;
    }
}

/**
 * Handles breath meter actions depending of the health segments values.
 */
void handle_breath_meter_actions(s16 numBreathWedges) {
    // Show breath meter if health is not full, less than 8
    if ((numBreathWedges < 8) && (sBreathMeterStoredValue == 8) && sBreathMeterHUD.animation == BREATH_METER_HIDDEN) {
        sBreathMeterHUD.animation = BREATH_METER_SHOWING;
        // sBreathMeterHUD.y         = HUD_BREATH_METER_Y;
    }
    // Show breath meter if breath is full, has 8
    if ((numBreathWedges == 8) && (sBreathMeterStoredValue  == 7)) sBreathMeterVisibleTimer  = 0;
    // After breath is full, hide breath meter
    if ((numBreathWedges == 8) && (sBreathMeterVisibleTimer > 45)) sBreathMeterHUD.animation = BREATH_METER_HIDING;
    // Update to match breath value
    sBreathMeterStoredValue = numBreathWedges;
    // If Mario is swimming, keep breath meter visible
    if (gPlayerCameraState->action & ACT_FLAG_SWIMMING) {
        if (sBreathMeterHUD.animation == BREATH_METER_HIDDEN) {
            sBreathMeterHUD.animation = BREATH_METER_SHOWING;
        }
        sBreathMeterVisibleTimer = 0;
    }
}

void render_hud_breath_meter(void) {
    s16 shownBreathAmount = gHudDisplay.breath;
    if (sBreathMeterHUD.animation != BREATH_METER_HIDING) handle_breath_meter_actions(shownBreathAmount);
    if (sBreathMeterHUD.animation == BREATH_METER_HIDDEN) return;
    switch (sBreathMeterHUD.animation) {
        case BREATH_METER_SHOWING:       animate_breath_meter_sliding_in();  break;
        case BREATH_METER_HIDING:        animate_breath_meter_sliding_out(); break;
        default:                                                             break;
    }
    render_dl_breath_meter(shownBreathAmount);
    sBreathMeterVisibleTimer++;
}
#endif


static u16 get_press_button_alpha() {
    f32 tmp;
    s32 currentCycles = pressAFrames % CYCLE_FRAMES;
    if (currentCycles > CYCLE_FRAMES / 2)
        currentCycles = CYCLE_FRAMES - currentCycles;

    if (pressAFrames < (CYCLE_FRAMES/2)) {
        tmp = sins((f32) currentCycles / (f32) CYCLE_FRAMES * 32767.0f) * 255.0f;
        return (u8) tmp;
    }

    tmp = 1.0f - sins(((f32) ((CYCLE_FRAMES/2) - currentCycles) / (f32) CYCLE_FRAMES + 0.5f) * 32767.0f);
    return ((u8) ((1.0f - (tmp * 0.67f)) * 255.0f + 0.5f));
}

static void render_press_button(void) {
    u8 out[] = { GLYPH_A_BUTTON, GLYPH_SPACE };

    u16 alpha = get_press_button_alpha();
    if (alpha > 255) {
        alpha = 255;
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    if (!(gEmulator & EMU_CONSOLE)) {
        gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, (u8) ((alpha * 95) >> 8));
        print_hud_lut_string(HUD_LUT_GLOBAL, 282 + gConsoleOffsetDiffX - 1, 208 + gConsoleOffsetDiffY + 1, out);
    }
    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, (u8) alpha);
    print_hud_lut_string(HUD_LUT_GLOBAL, 282 + gConsoleOffsetDiffX, 208 + gConsoleOffsetDiffY, out);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}


/**
 * Renders the amount of lives Mario has.
 */
void render_hud_mario_lives(void) {
    print_text(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(22), HUD_TOP_Y, ","); // 'Mario Head' glyph
    print_text(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(38), HUD_TOP_Y, "*"); // 'X' glyph
    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_LEFT_EDGE(54), HUD_TOP_Y, "%d", gHudDisplay.lives);
}

#ifdef VANILLA_STYLE_CUSTOM_DEBUG
void render_debug_mode(void) {
    print_text(180, 40, "DEBUG MODE");
    print_text_fmt_int(5, 20, "Z %d", gMarioState->pos[2]);
    print_text_fmt_int(5, 40, "Y %d", gMarioState->pos[1]);
    print_text_fmt_int(5, 60, "X %d", gMarioState->pos[0]);
    print_text_fmt_int(10, 100, "SPD %d", (s32) gMarioState->forwardVel);
    print_text_fmt_int(10, 120, "ANG 0*%04x", (u16) gMarioState->faceAngle[1]);
    print_fps(10,80);
}
#endif

/**
 * Renders the amount of coins collected.
 */
void render_hud_coins(void) {
    print_text(HUD_COINS_X, HUD_TOP_Y, "$"); // 'Coin' glyph
    print_text((HUD_COINS_X + 16), HUD_TOP_Y, "*"); // 'X' glyph
    print_text_fmt_int((HUD_COINS_X + 30), HUD_TOP_Y, "%d", gHudDisplay.coins);
}

/**
 * Renders the amount of stars collected.
 * Disables "X" glyph when Mario has 100 stars or more.
 */
void render_hud_stars(void) {
    if (gHudFlash == HUD_FLASH_STARS && gGlobalTimer & 0x8) return;
    s8 showX = (gHudDisplay.stars < 100);
    print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X), HUD_TOP_Y, "^"); // 'Star' glyph
    if (showX) print_text((GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X) + 16), HUD_TOP_Y, "*"); // 'X' glyph
    print_text_fmt_int((showX * 14) + GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_STARS_X - 16),
                       HUD_TOP_Y, "%d", gHudDisplay.stars);
}

/**
 * Unused function that renders the amount of keys collected.
 * Leftover function from the beta version of the game.
 */
void render_hud_keys(void) {
    s16 i;

    for (i = 0; i < gHudDisplay.keys; i++) {
        print_text((i * 16) + 220, 142, "|"); // unused glyph - beta key
    }
}

/**
 * Renders the timer when Mario start sliding in PSS.
 */
void render_hud_timer(void) {
    Texture *(*hudLUT)[] = segmented_to_virtual(&main_hud_lut);
    u16 timerValFrames = gHudDisplay.timer;
    u16 timerMins = timerValFrames / (30 * 60);
    u16 timerSecs = (timerValFrames - (timerMins * 1800)) / 30;
    u16 timerFracSecs = ((timerValFrames - (timerMins * 1800) - (timerSecs * 30)) & 0xFFFF) / 3;

#if MULTILANG
    switch (eu_get_language()) {
        case LANGUAGE_ENGLISH: print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(150), 185,  "TIME"); break;
        case LANGUAGE_FRENCH:  print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(155), 185, "TEMPS"); break;
        case LANGUAGE_GERMAN:  print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(150), 185,  "ZEIT"); break;
    }
#else
    print_text(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(150), 185, "TIME");
#endif

    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(91), 185, "%0d", timerMins);
    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(71), 185, "%02d", timerSecs);
    print_text_fmt_int(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(37), 185, "%d", timerFracSecs);

    gSPDisplayList(gDisplayListHead++, dl_hud_img_begin);
    render_hud_tex_lut(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(81), 32, (*hudLUT)[GLYPH_APOSTROPHE]);
    render_hud_tex_lut(GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(46), 32, (*hudLUT)[GLYPH_DOUBLE_QUOTE]);
    gSPDisplayList(gDisplayListHead++, dl_hud_img_end);
}

/**
 * Sets HUD status camera value depending of the actions
 * defined in update_camera_status.
 */
void set_hud_camera_status(s16 status) {
    sCameraHUD.status = status;
}

/**
 * Renders camera HUD glyphs using a table list, depending of
 * the camera status called, a defined glyph is rendered.
 */
void render_hud_camera_status(void) {
    Texture *(*cameraLUT)[6] = segmented_to_virtual(&main_hud_camera_lut);

    if (sCameraHUD.status == CAM_STATUS_NONE) {
        return;
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    for (s32 i = 0; i < 2; i++) {
        s32 x = GFX_DIMENSIONS_RECT_FROM_RIGHT_EDGE(HUD_CAMERA_X) + gConsoleOffsetDiffX;
        s32 y = 205 + gConsoleOffsetDiffY;

        if (i == 0) {
            if (gEmulator & EMU_CONSOLE) {
                continue;
            }

            gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 95);
            x -= 1;
            y += 1;
        } else {
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
        }

        switch (sCameraHUD.status & CAM_STATUS_C_MODE_GROUP) {
            case CAM_STATUS_C_DOWN:
                render_rgba16_small_tex_lut(x + 4, y + 16, (*cameraLUT)[GLYPH_CAM_ARROW_DOWN]);
                break;
            case CAM_STATUS_C_UP:
                render_rgba16_small_tex_lut(x + 4, y - 8, (*cameraLUT)[GLYPH_CAM_ARROW_UP]);
                break;
        }

        if (i == 0) {
            x -= 1;
            y += 1;
        }

        render_rgba16_tex_lut(x, y, (*cameraLUT)[GLYPH_CAM_CAMERA]);
        switch (sCameraHUD.status & CAM_STATUS_MODE_GROUP) {
            case CAM_STATUS_MARIO:
                render_rgba16_tex_lut(x + 16, y, (*cameraLUT)[GLYPH_CAM_MARIO_HEAD]);
                break;
            case CAM_STATUS_LAKITU:
                render_rgba16_tex_lut(x + 16, y, (*cameraLUT)[GLYPH_CAM_LAKITU_HEAD]);
                break;
            case CAM_STATUS_FIXED:
                render_rgba16_tex_lut(x + 16, y, (*cameraLUT)[GLYPH_CAM_FIXED]);
                break;
        }
    }

    gDPSetCombineMode(gDisplayListHead++, G_CC_SHADE, G_CC_SHADE);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

struct BalloonTypeProperties bProps[POINT_BALLOON_COUNT] = {
    [POINT_BALLOON_5]      = {.scale = 1.0f,  .points = 5,    .popsfx = SOUND_EXTRA1_BSM_BALLOON_SMALLEST,  .popjingle = SOUND_EXTRA2_BSM_POINTS_5    },
    [POINT_BALLOON_10]     = {.scale = 1.2f,  .points = 10,   .popsfx = SOUND_EXTRA1_BSM_BALLOON_SMALL,     .popjingle = SOUND_EXTRA2_BSM_POINTS_10   },
    [POINT_BALLOON_25]     = {.scale = 1.5f,  .points = 25,   .popsfx = SOUND_EXTRA1_BSM_BALLOON_SEMISMALL, .popjingle = SOUND_EXTRA2_BSM_POINTS_25   },
    [POINT_BALLOON_50]     = {.scale = 2.0f,  .points = 50,   .popsfx = SOUND_EXTRA1_BSM_BALLOON_LARGE,     .popjingle = SOUND_EXTRA2_BSM_POINTS_50   },
    [POINT_BALLOON_100]    = {.scale = 3.0f,  .points = 100,  .popsfx = SOUND_EXTRA1_BSM_BALLOON_LARGEST,   .popjingle = SOUND_EXTRA2_BSM_POINTS_100  },
    [POINT_BALLOON_RED]    = {.scale = 1.75f, .points = 0,    .popsfx = SOUND_EXTRA1_BSM_BALLOON_SEMILARGE, .popjingle = SOUND_EXTRA2_BSM_REDCOIN_0   },
    [POINT_BALLOON_BOWSER] = {.scale = 2.5f,  .points = -100, .popsfx = SOUND_EXTRA1_BSM_BALLOON_LARGE,     .popjingle = SOUND_SPECIAL2_BOWSER_BALLOON},
};

struct BalloonTypeProperties keyBalloon = {.scale = 1.35f, .points = 0, .popsfx = SOUND_EXTRA1_BSM_BALLOON_SEMISMALL, .popjingle = SOUND_MENU_STAR_SOUND};

enum BSMHudTypes {
    BSM_HUD_SCORE,
    BSM_HUD_TIME,
    BSM_HUD_REDBALLOONS,
    BSM_HUD_KEY,
    BSM_HUD_TCS,

    BSM_HUD_COUNT,
};

struct BSMHudTypeProps {
    s16 x;
    s16 y;
    s16 shadowX;
    s16 shadowY;
    s16 animTimer;
    u32 lastValue;
    u32 *trackValueAddr;
};

static const ColorRGBA sBSMBalloonScoreColorIndex[POINT_BALLOON_COUNT] = {
    [POINT_BALLOON_5]      = {175, 175, 175, 255},
    [POINT_BALLOON_10]     = {127, 255, 127, 255},
    [POINT_BALLOON_25]     = {151, 151, 255, 255},
    [POINT_BALLOON_50]     = {191, 127, 191, 255},
    [POINT_BALLOON_100]    = {255, 223, 127, 255},
    [POINT_BALLOON_RED]    = {255, 127, 127, 255},
    [POINT_BALLOON_BOWSER] = { 31,  31,  31, 255},
};

struct BSMHudTypeProps bsmHudProps[BSM_HUD_COUNT];

struct BSMPointDisplay {
    ColorRGBA color;
    s16 x;
    s16 y;
    s16 timer;
    s16 points;
    s16 speedupTimer;
};

struct BSMPointDisplay bsmPointColors[3];
u8 bsmPointColorDisplayIndex = 0;

void init_bsm_hud(s32 updateLastValue) {
    bsmHudProps[BSM_HUD_SCORE].x = 22 - gConsoleOffsetDiffX;
    bsmHudProps[BSM_HUD_SCORE].y = SCREEN_HEIGHT - (HUD_TOP_Y + 16) - gConsoleOffsetDiffY;
    bsmHudProps[BSM_HUD_SCORE].shadowX = bsmHudProps[BSM_HUD_SCORE].x - 2;
    bsmHudProps[BSM_HUD_SCORE].shadowY = bsmHudProps[BSM_HUD_SCORE].y + 2;
    bsmHudProps[BSM_HUD_SCORE].trackValueAddr = &gBSMScoreCount;

    bsmHudProps[BSM_HUD_TIME].x = SCREEN_WIDTH - (22 + 64) + gConsoleOffsetDiffX;
    bsmHudProps[BSM_HUD_TIME].y = SCREEN_HEIGHT - (HUD_TOP_Y + 16) - gConsoleOffsetDiffY;
    bsmHudProps[BSM_HUD_TIME].shadowX = bsmHudProps[BSM_HUD_TIME].x - 2;
    bsmHudProps[BSM_HUD_TIME].shadowY = bsmHudProps[BSM_HUD_TIME].y + 2;
    bsmHudProps[BSM_HUD_TIME].trackValueAddr = NULL;

    bsmHudProps[BSM_HUD_REDBALLOONS].x = 22 - gConsoleOffsetDiffX;
    bsmHudProps[BSM_HUD_REDBALLOONS].y = 205 + gConsoleOffsetDiffY;
    bsmHudProps[BSM_HUD_REDBALLOONS].shadowX = bsmHudProps[BSM_HUD_REDBALLOONS].x - 1;
    bsmHudProps[BSM_HUD_REDBALLOONS].shadowY = bsmHudProps[BSM_HUD_REDBALLOONS].y + 1;
    bsmHudProps[BSM_HUD_REDBALLOONS].trackValueAddr = &gBSMRedBalloonsPopped;

    if (gBSMGameplayMode == BSM_MENU_GAMEPLAY_MODE_TIME_TRIALS) {
        bsmHudProps[BSM_HUD_KEY].x = SCREEN_CENTER_X - 8;
    } else {
        bsmHudProps[BSM_HUD_KEY].x = SCREEN_CENTER_X - 18;
    }
    bsmHudProps[BSM_HUD_KEY].y = SCREEN_HEIGHT - (HUD_TOP_Y + 16) - gConsoleOffsetDiffY;
    bsmHudProps[BSM_HUD_KEY].shadowX = bsmHudProps[BSM_HUD_KEY].x - 1;
    bsmHudProps[BSM_HUD_KEY].shadowY = bsmHudProps[BSM_HUD_KEY].y + 1;
    bsmHudProps[BSM_HUD_KEY].trackValueAddr = &gBSMKeyCollected;

    bsmHudProps[BSM_HUD_TCS].x = SCREEN_CENTER_X + 2;
    bsmHudProps[BSM_HUD_TCS].y = SCREEN_HEIGHT - (HUD_TOP_Y + 16) - gConsoleOffsetDiffY;
    bsmHudProps[BSM_HUD_TCS].shadowX = bsmHudProps[BSM_HUD_TCS].x - 1;
    bsmHudProps[BSM_HUD_TCS].shadowY = bsmHudProps[BSM_HUD_TCS].y + 1;
    bsmHudProps[BSM_HUD_TCS].trackValueAddr = &gBSMTCSTokenCollected;

    for (s32 i = 0; i < BSM_HUD_COUNT; i++) {
        bsmHudProps[i].animTimer = S16_MAX;
        if (updateLastValue) {
            bsmHudProps[i].lastValue = 0;
        }
    }

    for (s32 i = 0; i < ARRAY_COUNT(bsmPointColors); i++) {
        bsmPointColors[i].timer = S16_MAX;
        bsmPointColors[i].speedupTimer = -1;
    }
}

#define STRINGCOL_ANIM_DURATION 50
#define STRINGCOL_ANIM_FADEIN 2
static void update_string_color(u8 *currentColor, const u8 *toColor, s32 timer) {
    if (timer > STRINGCOL_ANIM_DURATION + 2) {
        return;
    }

    f32 intensity = 0.0f;
#if (STRINGCOL_ANIM_FADEIN != 0)
    if (timer < STRINGCOL_ANIM_FADEIN) {
        intensity = sins((s16) (u16) ((0x4000 * (timer + 1)) / (STRINGCOL_ANIM_FADEIN + 1)));
    }
    else {
        intensity = coss((s16) (u16) ((0x4000 * (timer - STRINGCOL_ANIM_FADEIN)) / (STRINGCOL_ANIM_DURATION - STRINGCOL_ANIM_FADEIN)));
    }
#else
        intensity = coss((s16) (u16) (0x4000 * timer / STRINGCOL_ANIM_DURATION));
#endif

    if (intensity < 0.0f)
        intensity = 0.0f;
    else if (intensity > 1.0f)
        intensity = 1.0f;

    for (u32 i = 0; i < sizeof(ColorRGBA); i++) {
        u32 color = (u32) (((f32) toColor[i] * intensity + currentColor[i] * (1.0f - intensity)) + 0.5f);
        if (color > 255)
            color = 255;
            
        currentColor[i] = color;
    }
}

#define NEWPOINTCOL_ONE_WAY_FADE_DUR 12
#define NEWPOINTCOL_ANIM_HOLD 45
#define NEWPOINTCOL_X_MOVEMENT 32.0f
static void print_last_point_update(void) {
    char str[16];
    struct BSMPointDisplay *props;

    for (s32 i = 0; i < ARRAY_COUNT(bsmPointColors); i++) {
        props = &bsmPointColors[(i + bsmPointColorDisplayIndex) % ARRAY_COUNT(bsmPointColors)];

        if (props->timer >= 2*NEWPOINTCOL_ONE_WAY_FADE_DUR + NEWPOINTCOL_ANIM_HOLD)
            continue;            

        if (i != ARRAY_COUNT(bsmPointColors) - 1 && props->speedupTimer < 0) {
            props->speedupTimer = props->timer;
        }

        f32 intensity = 1.0f;
        f32 mult = -1.0f;
        s32 timer = props->timer;
        s32 x = props->x;
        
        if (props->speedupTimer >= 0 && props->speedupTimer < NEWPOINTCOL_ONE_WAY_FADE_DUR) {
            if (timer - props->speedupTimer >= NEWPOINTCOL_ONE_WAY_FADE_DUR) {
                props->timer = S16_MAX;
                continue;
            }

            f32 relativeIntensity = coss((s16) (u16) ((0x4000 * (timer - props->speedupTimer)) / NEWPOINTCOL_ONE_WAY_FADE_DUR));
            intensity = sins((s16) (u16) ((0x4000 * props->speedupTimer) / NEWPOINTCOL_ONE_WAY_FADE_DUR)) * relativeIntensity;

            f32 tmpXOffset = -(1.0f - intensity) * NEWPOINTCOL_X_MOVEMENT;
            tmpXOffset += ((f32) (timer - props->speedupTimer) / NEWPOINTCOL_ONE_WAY_FADE_DUR) * (f32) (-tmpXOffset);
            tmpXOffset += (1.0f - relativeIntensity) * NEWPOINTCOL_X_MOVEMENT;

            x += tmpXOffset;
        } else {
            if (props->speedupTimer >= 0 && props->speedupTimer < NEWPOINTCOL_ONE_WAY_FADE_DUR + NEWPOINTCOL_ANIM_HOLD) {
                props->speedupTimer = NEWPOINTCOL_ONE_WAY_FADE_DUR + NEWPOINTCOL_ANIM_HOLD;
                timer = props->speedupTimer;
                props->timer = timer;
            }

            if (timer > NEWPOINTCOL_ONE_WAY_FADE_DUR + NEWPOINTCOL_ANIM_HOLD) {
                timer = (2*NEWPOINTCOL_ONE_WAY_FADE_DUR + NEWPOINTCOL_ANIM_HOLD) - timer;
                mult = 1.0f;
            }

            if (timer < NEWPOINTCOL_ONE_WAY_FADE_DUR) {
                intensity = sins((s16) (u16) ((0x4000 * timer) / NEWPOINTCOL_ONE_WAY_FADE_DUR));
            }

            x += mult * (1.0f - intensity) * NEWPOINTCOL_X_MOVEMENT;
        }

        print_set_envcolour(props->color[0], props->color[1], props->color[2], (u8) (props->color[3] * sqr(intensity)));
        sprintf(str, "%s%d", props->points >= 0 ? "+" : "", props->points);
        print_small_text(x, props->y, str, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);

        props->timer++;
    }
}

#define NEWPOINTCOL_DARK_MULT 0.75f
#define NEWPOINTCOL_TRANSPARENT_MULT 0.8f
static void init_new_point_buffer(s32 x, s32 y, s32 points, const u8 *colorIndex) {
    if (points == 0) {
        return;
    }

    struct BSMPointDisplay *props = &bsmPointColors[bsmPointColorDisplayIndex];
    props->x = x;
    props->y = y;
    props->points = points;
    props->timer = 0;
    props->speedupTimer = -1;
    props->color[0] = colorIndex[0] * NEWPOINTCOL_DARK_MULT;
    props->color[1] = colorIndex[1] * NEWPOINTCOL_DARK_MULT;
    props->color[2] = colorIndex[2] * NEWPOINTCOL_DARK_MULT;
    props->color[3] = colorIndex[3] * NEWPOINTCOL_TRANSPARENT_MULT;

    bsmPointColorDisplayIndex = (bsmPointColorDisplayIndex + 1) % ARRAY_COUNT(bsmPointColors);
}

#define BOUNCE_ANIM_TIME 3
void render_hud_bsm_info(void) {
    char strBuff[32];
    struct BSMHudTypeProps *props;
    void **hudLUT = segmented_to_virtual(main_hud_lut);

    for (s32 i = 0; i < BSM_HUD_COUNT; i++) {
        if (
            gBSMGameplayMode == BSM_MENU_GAMEPLAY_MODE_TIME_TRIALS &&
            (i == BSM_HUD_SCORE || i == BSM_HUD_REDBALLOONS || i == BSM_HUD_TCS)
        ) {
            continue;
        }
        props = &bsmHudProps[i];
        s32 animY = props->y;
        if (props->animTimer < BOUNCE_ANIM_TIME) {
            animY = props->y - (s32) (2.0f * sins((s16) (u16) (0x8000 * props->animTimer / BOUNCE_ANIM_TIME)));
        }
        s32 animShadowY = (props->shadowY - props->y) + animY;

        if (props->animTimer < S16_MAX) {
            props->animTimer++;
        }

        if (props->trackValueAddr && props->lastValue != *props->trackValueAddr) {
            props->lastValue = *props->trackValueAddr;
            props->animTimer = 0;

            if (i == BSM_HUD_SCORE) {
                init_new_point_buffer(props->x + 32, props->y + 32, bProps[gBSMLastBalloonType].points, sBSMBalloonScoreColorIndex[gBSMLastBalloonType]);
            }
        }

        if (i == BSM_HUD_SCORE || i == BSM_HUD_TIME) {
            gSPDisplayList(gDisplayListHead++, dl_rgba32_64x16_text_begin);
            gDPPipeSync(gDisplayListHead++);
            if (i == BSM_HUD_SCORE) {
                gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 1, hudLUT[GLYPH_BSM_SCORE]);
                sprintf(strBuff, "%d", gBSMScoreCount);
            } else {
                gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 1, hudLUT[GLYPH_BSM_TIME]);
                sprintf(strBuff, "%d:%02d.%02d", gBSMFrameTimer / (30 * 60), (gBSMFrameTimer / 30) % 60, (gBSMFrameTimer % 30) * 100 / 30);
            }

            if (!(gEmulator & EMU_CONSOLE)) {
                gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 95);
                gSPDisplayList(gDisplayListHead++, dl_rgba32_64x16_load_tex_block);
                gSPTextureRectangle(gDisplayListHead++, props->shadowX << 2, props->shadowY << 2, (props->shadowX + 64) << 2,
                                    (props->shadowY + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
                gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
                gDPPipeSync(gDisplayListHead++);
            }
            gSPDisplayList(gDisplayListHead++, dl_rgba32_64x16_load_tex_block);
            gSPTextureRectangle(gDisplayListHead++, props->x << 2, props->y << 2, (props->x + 64) << 2,
                                (props->y + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

            gSPDisplayList(gDisplayListHead++, dl_rgba32_64x16_text_end);

            if (i == BSM_HUD_SCORE) {
                ColorRGBA colorIndex = {255, 255, 255, 255};
                update_string_color(colorIndex, sBSMBalloonScoreColorIndex[gBSMLastBalloonType], props->animTimer);
                print_set_envcolour(colorIndex[0], colorIndex[1], colorIndex[2], colorIndex[3]);
            } else {
                print_set_envcolour(255, 255, 255, 255);
            }
            print_small_text(props->x + 32, animY + 20, strBuff, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
        } else if (i == BSM_HUD_REDBALLOONS) {
            s32 redBalloonX;

            gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
            gDPPipeSync(gDisplayListHead++);
            gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT[GLYPH_BSM_RED_BALLOON]);

            if (!(gEmulator & EMU_CONSOLE)) {
                redBalloonX = props->shadowX;
                gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 95);
                for (u32 j = 0; j < gBSMRedBalloonsPopped; j++) {
                    s32 redBalloonAnimY = props->shadowY;

                    gDPPipeSync(gDisplayListHead++);
                    gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);

                    if (gBSMRedBalloonsPopped != 8 && j + 1 == gBSMRedBalloonsPopped) {
                        redBalloonAnimY = animShadowY;
                    } else if (
                    gBSMRedBalloonsPopped == 8 &&
                    (gBSMRedBalloonsPopped - j - 1) == (u32) (props->animTimer / BOUNCE_ANIM_TIME)
                    ) {
                        redBalloonAnimY = props->shadowY - (s32) (2.0f * sins((s16) (u16) (0x8000 * (props->animTimer % BOUNCE_ANIM_TIME) / BOUNCE_ANIM_TIME)));
                    }
                    gSPTextureRectangle(gDisplayListHead++, redBalloonX << 2, redBalloonAnimY << 2, (redBalloonX + 16) << 2,
                                        (redBalloonAnimY + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

                    redBalloonX += 16;
                }
                gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
            }

            redBalloonX = props->x;

            ColorRGBA colorIndex = {255, 255, 255, 255};
            update_string_color(colorIndex, sBSMBalloonScoreColorIndex[POINT_BALLOON_RED], props->animTimer);
            gDPSetEnvColor(gDisplayListHead++, colorIndex[0], colorIndex[1], colorIndex[2], colorIndex[3]);
            for (u32 j = 0; j < gBSMRedBalloonsPopped; j++) {
                s32 redBalloonAnimY = props->y;

                gDPPipeSync(gDisplayListHead++);
                gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);

                if (gBSMRedBalloonsPopped != 8 && j + 1 == gBSMRedBalloonsPopped) {
                    redBalloonAnimY = animY;
                } else if (
                    gBSMRedBalloonsPopped == 8 &&
                    (gBSMRedBalloonsPopped - j - 1) == (u32) (props->animTimer / BOUNCE_ANIM_TIME)
                ) {
                    redBalloonAnimY = props->y - (s32) (2.0f * sins((s16) (u16) (0x8000 * (props->animTimer % BOUNCE_ANIM_TIME) / BOUNCE_ANIM_TIME)));
                }
                gSPTextureRectangle(gDisplayListHead++, redBalloonX << 2, redBalloonAnimY << 2, (redBalloonX + 16) << 2,
                                    (redBalloonAnimY + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

                redBalloonX += 16;
            }

            gDPPipeSync(gDisplayListHead++);
            gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT[GLYPH_BSM_RED_BALLOON_NA]);
            gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 95);
            for (u32 j = gBSMRedBalloonsPopped; j < 8; j++) {
                gDPPipeSync(gDisplayListHead++);
                gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
                gSPTextureRectangle(gDisplayListHead++, redBalloonX << 2, props->y << 2, (redBalloonX + 16) << 2,
                                    (props->y + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

                redBalloonX += 16;
            }
            
            gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);

            if (props->animTimer == 10 && gBSMRedBalloonsPopped == 8) {
                play_narrator_sound_at_random(&gBSMNarratorReds);
            }
        } else {
            gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
            gDPPipeSync(gDisplayListHead++);
            if (props->trackValueAddr && *props->trackValueAddr) {
                if (i == BSM_HUD_KEY) {
                    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT[GLYPH_BSM_KEY]);
                } else {
                    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT[GLYPH_BSM_TCS]);
                }

                if (!(gEmulator & EMU_CONSOLE)) {
                    gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, 95);
                    gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
                    gSPTextureRectangle(gDisplayListHead++, props->shadowX << 2, animShadowY << 2, (props->shadowX + 16) << 2,
                                        (animShadowY + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
                    gDPPipeSync(gDisplayListHead++);
                    gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 255);
                }

                
                ColorRGBA colorIndex = {255, 255, 255, 255};
                if (i == BSM_HUD_KEY) {
                    update_string_color(colorIndex, (ColorRGBA) {255, 255, 127, 255}, props->animTimer);
                } else {
                    update_string_color(colorIndex, (ColorRGBA) {255, 191, 159, 255}, props->animTimer);
                }
                gDPSetEnvColor(gDisplayListHead++, colorIndex[0], colorIndex[1], colorIndex[2], colorIndex[3]);
            } else {
                if (i == BSM_HUD_KEY) {
                    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT[GLYPH_BSM_KEY_NA]);
                } else {
                    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT[GLYPH_BSM_TCS_NA]);
                }
                gDPSetEnvColor(gDisplayListHead++, 255, 255, 255, 95);
            }
            gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
            gSPTextureRectangle(gDisplayListHead++, props->x << 2, animY << 2, (props->x + 16) << 2,
                                (animY + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
                                
            gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
        }
    }

    print_last_point_update();
}

/**
 * Render HUD strings using hudDisplayFlags with it's render functions,
 * excluding the cannon reticle which detects a camera preset for it.
 */
void render_hud(void) {
    s16 hudDisplayFlags = gHudDisplay.flags & HUD_DISPLAY_FLAG_CAMERA_AND_POWER;

    if (
        (gMarioState && gMarioState->action == ACT_BSM_CELEBRATION)
#ifdef PUPPYPRINT_DEBUG
        || (fDebug && sPPDebugPage == PUPPYPRINT_PAGE_SMOOTH_VIDEO)
#endif
    ) {
        hudDisplayFlags &= ~HUD_DISPLAY_FLAG_CAMERA_AND_POWER;
    }

    if (hudDisplayFlags == HUD_DISPLAY_NONE) {
        sPowerMeterHUD.animation = POWER_METER_HIDDEN;
        sPowerMeterStoredHealth = 8;
        sPowerMeterVisibleTimer = 0;

        if (renderPressA) {
            create_dl_ortho_matrix();
            render_press_button();
            renderPressA = FALSE;
        }

        // if (gCurrLevelNum == LEVEL_CASTLE_GROUNDS) {
        //     create_dl_ortho_matrix();
        // }
#ifdef BREATH_METER
        sBreathMeterHUD.animation = BREATH_METER_HIDDEN;
        sBreathMeterStoredValue = 8;
        sBreathMeterVisibleTimer = 0;
#endif
    } else {
#ifdef VERSION_EU
        // basically create_dl_ortho_matrix but guOrtho screen width is different
        Mtx *mtx = alloc_display_list(sizeof(*mtx));

        if (mtx == NULL) {
            return;
        }

        create_dl_identity_matrix();
        guOrtho(mtx, -16.0f, SCREEN_WIDTH + 16, 0, SCREEN_HEIGHT, -10.0f, 10.0f, 1.0f);
        gSPPerspNormalize(gDisplayListHead++, 0xFFFF);
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx),
                  G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
#else
        create_dl_ortho_matrix();
#endif

        if (gCurrentArea != NULL && gCurrentArea->camera->mode == CAMERA_MODE_INSIDE_CANNON) {
            render_hud_cannon_reticle();
        }

#ifdef ENABLE_LIVES
        if (hudDisplayFlags & HUD_DISPLAY_FLAG_LIVES) {
            render_hud_mario_lives();
        }
#endif

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_COIN_COUNT) {
            render_hud_coins();
        }

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_STAR_COUNT) {
            render_hud_stars();
        }

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_KEYS) {
            render_hud_keys();
        }

#ifdef BREATH_METER
        if (hudDisplayFlags & HUD_DISPLAY_FLAG_BREATH_METER) render_hud_breath_meter();
#endif

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_CAMERA_AND_POWER) {
            render_hud_power_meter();
#ifdef PUPPYCAM
            if (!gPuppyCam.enabled) {
#endif
            render_hud_camera_status();
#ifdef PUPPYCAM
            }
#endif

            render_hud_bsm_info();
        }

        if (hudDisplayFlags & HUD_DISPLAY_FLAG_TIMER) {
            render_hud_timer();
        }

        if (renderPressA) {
            render_press_button();
            renderPressA = FALSE;
        }

#ifdef VANILLA_STYLE_CUSTOM_DEBUG
        if (gCustomDebugMode) {
            render_debug_mode();
        }
#endif
    }
}
