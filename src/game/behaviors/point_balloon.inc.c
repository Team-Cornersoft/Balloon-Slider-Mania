#include "game/debug.h"

#define BALLOON_FLOATING_CALC(relativePos, intensity, offset, freq) \
    (relativePos + intensity * sins((0x10000 * ((o->oPtBalloonAbsoluteTimer + offset) % freq)) / freq))

enum BalloonTypes {
    POINT_BALLOON_5,
    POINT_BALLOON_10,
    POINT_BALLOON_25,
    POINT_BALLOON_50,
    POINT_BALLOON_100,

    POINT_BALLOON_COUNT,
};

struct BalloonTypeProperties {
    f32 scale;
    s32 points;
};

struct BalloonTypeProperties bProps[POINT_BALLOON_COUNT] = {
    [POINT_BALLOON_5]   = {.scale = 1.0f, .points = 5  },
    [POINT_BALLOON_10]  = {.scale = 1.2f, .points = 10 },
    [POINT_BALLOON_25]  = {.scale = 1.5f, .points = 25 },
    [POINT_BALLOON_50]  = {.scale = 2.0f, .points = 50 },
    [POINT_BALLOON_100] = {.scale = 3.0f, .points = 100},
};

void bhv_point_balloon_init(void) {
    u32 bType = o->oBehParams2ndByte;
    assert(bType < POINT_BALLOON_COUNT, "Invalid point balloon type detected!");

    vec3f_copy(&o->oPtBalloonRelativePosVec, &o->oHomeVec);
    cur_obj_scale(bProps[bType].scale);

    o->oPtBalloonOscillateXFreq = (random_u16() % (u32) (60.0f * bProps[bType].scale)) + 120;
    o->oPtBalloonOscillateXOffset = random_u16() % o->oPtBalloonOscillateXFreq;
    o->oPtBalloonOscillateXIntensity = (f32) (random_u16() % (u32) (20 * bProps[bType].scale));

    o->oPtBalloonOscillateYFreq = random_u16() % (u32) (40.0f * bProps[bType].scale) + 75;
    o->oPtBalloonOscillateYOffset = random_u16() % o->oPtBalloonOscillateYFreq;
    o->oPtBalloonOscillateYIntensity = (f32) (random_u16() % (u32) (35 * bProps[bType].scale)) + 5;

    o->oPtBalloonOscillateZFreq = (random_u16() % (u32) (60.0f * bProps[bType].scale)) + 120;
    o->oPtBalloonOscillateZOffset = random_u16() % o->oPtBalloonOscillateXFreq;
    o->oPtBalloonOscillateZIntensity = (f32) (random_u16() % (u32) (20 * bProps[bType].scale));

    assert(o->oPtBalloonOscillateXFreq != 0, "Balloon X freq is 0!");
    assert(o->oPtBalloonOscillateYFreq != 0, "Balloon Y freq is 0!");
    assert(o->oPtBalloonOscillateZFreq != 0, "Balloon Z freq is 0!");
}

void bhv_point_balloon_loop(void) {
    o->oPosX = BALLOON_FLOATING_CALC(o->oPtBalloonRelativePosX, o->oPtBalloonOscillateXIntensity, o->oPtBalloonOscillateXOffset, o->oPtBalloonOscillateXFreq);
    o->oPosY = BALLOON_FLOATING_CALC(o->oPtBalloonRelativePosY, o->oPtBalloonOscillateYIntensity, o->oPtBalloonOscillateYOffset, o->oPtBalloonOscillateYFreq);
    o->oPosZ = BALLOON_FLOATING_CALC(o->oPtBalloonRelativePosZ, o->oPtBalloonOscillateZIntensity, o->oPtBalloonOscillateZOffset, o->oPtBalloonOscillateZFreq);

    o->oPtBalloonAbsoluteTimer++;
}
