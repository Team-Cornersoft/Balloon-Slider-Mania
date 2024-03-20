#ifndef HUD_H
#define HUD_H

#include <PR/ultratypes.h>
#include <PR/gbi.h>

#define HUD_POWER_METER_X            140
#define HUD_POWER_METER_EMPHASIZED_Y 166
#define HUD_POWER_METER_Y            200
#define HUD_POWER_METER_HIDDEN_Y     300

#define HUD_TOP_Y 209
#define HUD_BOTTOM_Y 19 // Same height as the Lakitu icon

#define HUD_COINS_X 168
#define HUD_STARS_X 78 // This starts counting from the right edge
#define HUD_CAMERA_X 54 // This starts counting from the right edge

#define EMULATOR_DIFF 6

enum PowerMeterAnimation {
    POWER_METER_HIDDEN,
    POWER_METER_EMPHASIZED,
    POWER_METER_DEEMPHASIZING,
    POWER_METER_HIDING,
    POWER_METER_VISIBLE
};

#ifdef BREATH_METER
enum BreathMeterAnimation {
    BREATH_METER_HIDDEN,
    BREATH_METER_SHOWING,
    BREATH_METER_HIDING,
    BREATH_METER_VISIBLE
};
#endif

enum CameraHUDLUT {
    GLYPH_CAM_CAMERA,
    GLYPH_CAM_MARIO_HEAD,
    GLYPH_CAM_LAKITU_HEAD,
    GLYPH_CAM_FIXED,
    GLYPH_CAM_ARROW_UP,
    GLYPH_CAM_ARROW_DOWN
};

enum BalloonTypes {
    POINT_BALLOON_5,
    POINT_BALLOON_10,
    POINT_BALLOON_25,
    POINT_BALLOON_50,
    POINT_BALLOON_100,
    POINT_BALLOON_RED,

    POINT_BALLOON_COUNT,
};

struct BalloonTypeProperties {
    f32 scale;
    s32 points;
    s32 popsfx;
    s32 popjingle;
};

extern struct BalloonTypeProperties bProps[POINT_BALLOON_COUNT];
extern struct BalloonTypeProperties keyBalloon;

void render_rgba16_tex_lut(s32 x, s32 y, Texture *texture);
void set_hud_camera_status(s16 status);
void render_hud(void);
void init_bsm_hud(s32 updateLastValue);

#endif // HUD_H
