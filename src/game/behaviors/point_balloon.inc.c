#include "game/debug.h"
extern void spawn_orange_number(s8 behParam, s16 relX, s16 relY, s16 relZ);

#define BALLOON_FLOATING_CALC(relativePos, intensity, offset, freq) \
    (relativePos + intensity * sins((0x10000 * ((o->oPtBalloonAbsoluteTimer + offset) % freq)) / freq))

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

struct BalloonTypeProperties bProps[POINT_BALLOON_COUNT] = {
    [POINT_BALLOON_5]   = {.scale = 1.0f,  .points = 5,   .popsfx = SOUND_EXTRA1_BSM_BALLOON_SMALLEST,  .popjingle = SOUND_EXTRA2_BSM_POINTS_5  },
    [POINT_BALLOON_10]  = {.scale = 1.2f,  .points = 10,  .popsfx = SOUND_EXTRA1_BSM_BALLOON_SMALL,     .popjingle = SOUND_EXTRA2_BSM_POINTS_10 },
    [POINT_BALLOON_25]  = {.scale = 1.5f,  .points = 25,  .popsfx = SOUND_EXTRA1_BSM_BALLOON_SEMISMALL, .popjingle = SOUND_EXTRA2_BSM_POINTS_25 },
    [POINT_BALLOON_50]  = {.scale = 2.0f,  .points = 50,  .popsfx = SOUND_EXTRA1_BSM_BALLOON_LARGE,     .popjingle = SOUND_EXTRA2_BSM_POINTS_50 },
    [POINT_BALLOON_100] = {.scale = 3.0f,  .points = 100, .popsfx = SOUND_EXTRA1_BSM_BALLOON_LARGEST,   .popjingle = SOUND_EXTRA2_BSM_POINTS_100},
    [POINT_BALLOON_RED] = {.scale = 1.75f, .points = 0,   .popsfx = SOUND_EXTRA1_BSM_BALLOON_SEMILARGE, .popjingle = SOUND_EXTRA2_BSM_REDCOIN_0 },
};

static u8 point_balloon_check_if_interacted(void) {
    if (!gMarioState || !gMarioState->marioObj) {
        return FALSE;
    }

    f32 scale = bProps[o->oBehParams2ndByte].scale;

    Vec3f marioPos;
    Vec3f balloonPos;
    Vec3f requiredDist;
    Vec3f objDist;

    vec3f_copy(balloonPos, &o->oPosVec);
    balloonPos[1] -= 10.0f;

    s16 relativeYaw = obj_angle_to_object(o, gMarioState->marioObj) - o->oFaceAngleYaw;
    f32 dist = lateral_dist_between_objects(o, gMarioState->marioObj);

    marioPos[0] = balloonPos[0] + sins(relativeYaw) * dist;
    marioPos[1] = gMarioState->pos[1] + ABS(gMarioState->marioObj->hitboxHeight) / 2.0f;
    marioPos[2] = balloonPos[2] + coss(relativeYaw) * dist;

    objDist[0] = ABS(marioPos[0] - balloonPos[0]) - ABS(gMarioState->marioObj->hitboxRadius);
    objDist[1] = ABS(marioPos[1] - balloonPos[1]) - ABS(gMarioState->marioObj->hitboxHeight) / 2.0f;
    objDist[2] = ABS(marioPos[2] - balloonPos[2]) - ABS(gMarioState->marioObj->hitboxRadius);

    requiredDist[0] = 95.0f * scale;
    requiredDist[1] = (110.0f + 5.0f) * scale + 5.0f; // Increase hitbox Y slightly to reduce likelihood of sliding under balloons
    requiredDist[2] = 45.0f * scale;

    for (s32 i = 0; i < 3; i++) {
        if (objDist[i] < 0.0f) {
            objDist[i] = 0.0f;
        }
        if (requiredDist[i] < 0.01f) {
            requiredDist[i] = 0.01f;
        }
    }

    // Serves as a div by zero check somewhat
    if (
       objDist[0] > requiredDist[0] ||
       objDist[1] > requiredDist[1] ||
       objDist[2] > requiredDist[2]
    ) {
        return FALSE;
    }

    if (
        objDist[0] > (requiredDist[0] * coss(sqrtf(sqr(objDist[1]) + sqr(objDist[2])) / sqrtf(sqr(requiredDist[1]) + sqr(requiredDist[2])) * 0x4000)) ||
        objDist[1] > (requiredDist[1] * coss(sqrtf(sqr(objDist[0]) + sqr(objDist[2])) / sqrtf(sqr(requiredDist[0]) + sqr(requiredDist[2])) * 0x4000)) ||
        objDist[2] > (requiredDist[2] * coss(sqrtf(sqr(objDist[0]) + sqr(objDist[1])) / sqrtf(sqr(requiredDist[0]) + sqr(requiredDist[1])) * 0x4000))
    ) {
        return FALSE;
    }

    return TRUE;
}

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
    o->oPtBalloonOscillateZOffset = random_u16() % o->oPtBalloonOscillateZFreq;
    o->oPtBalloonOscillateZIntensity = (f32) (random_u16() % (u32) (20 * bProps[bType].scale));

    assert(o->oPtBalloonOscillateXFreq != 0, "Balloon X freq is 0!");
    assert(o->oPtBalloonOscillateYFreq != 0, "Balloon Y freq is 0!");
    assert(o->oPtBalloonOscillateZFreq != 0, "Balloon Z freq is 0!");
}

void bhv_point_balloon_loop(void) {
    u32 bType = o->oBehParams2ndByte;
    f32 scale = bProps[bType].scale;

    if (o->oDistanceToMario <= (120.0f * scale) + 120.0f /*Mario's height*/) {
        if (point_balloon_check_if_interacted()) {
            if (!(gEmulator & NO_CULLING_EMULATOR_BLACKLIST)) {
                spawn_mist_particles_variable(16, -120.0f, 46.0f * scale);
                struct Object *balloonPop = spawn_object(o, MODEL_BSM_POINT_BALLOON_POPPED, bhvPointBalloonPopped);
                if (balloonPop) {
                    obj_scale(balloonPop, scale * 0.25f);
                    balloonPop->oBehParams = o->oBehParams;
                    balloonPop->oBehParams2ndByte = o->oBehParams2ndByte;
                }
                spawn_mist_particles_variable(4, -120.0f, 46.0f * scale);
            } else {
                spawn_mist_particles_variable(8, -120.0f, 46.0f * scale);
            }
            obj_mark_for_deletion(o);
        }
    }

    o->oPosX = BALLOON_FLOATING_CALC(o->oPtBalloonRelativePosX, o->oPtBalloonOscillateXIntensity, o->oPtBalloonOscillateXOffset, o->oPtBalloonOscillateXFreq);
    o->oPosY = BALLOON_FLOATING_CALC(o->oPtBalloonRelativePosY, o->oPtBalloonOscillateYIntensity, o->oPtBalloonOscillateYOffset, o->oPtBalloonOscillateYFreq);
    o->oPosZ = BALLOON_FLOATING_CALC(o->oPtBalloonRelativePosZ, o->oPtBalloonOscillateZIntensity, o->oPtBalloonOscillateZOffset, o->oPtBalloonOscillateZFreq);

    o->oPtBalloonAbsoluteTimer++;
}

void bhv_point_balloon_popped_init(void) {
    o->oPtBalloonPoppedScale = o->header.gfx.scale[0];
    o->oOpacity = 127;
}

void bhv_point_balloon_popped_loop(void) {
    o->oOpacity -= 16;
    if (o->oOpacity <= 0) {
        obj_mark_for_deletion(o);
        return;
    }

    if (o->oTimer == 0) {
        struct BalloonTypeProperties *props = &bProps[o->oBehParams2ndByte];
        assert(o->oBehParams2ndByte < ARRAY_COUNT(bProps), "Invalid balloon pop type!");

        cur_obj_play_sound_2(props->popsfx);

        if (o->oBehParams2ndByte == POINT_BALLOON_RED) {
            play_sound(props->popjingle + gRedBalloonsPopped, gGlobalSoundSource);
            gRedBalloonsPopped++;
            spawn_orange_number(gRedBalloonsPopped, 0, 0, 0);
        } else {
            play_sound(props->popjingle, gGlobalSoundSource);
        }
    }

    o->oPosX = o->oHomeX - (5.0f + 40.0f * random_float()) * o->oPtBalloonPoppedScale;
    o->oPosY = o->oHomeY - (5.0f + 40.0f * random_float()) * o->oPtBalloonPoppedScale;
    o->oPosZ = o->oHomeZ - (5.0f + 40.0f * random_float()) * o->oPtBalloonPoppedScale;

    cur_obj_scale(o->oPtBalloonPoppedScale + ((o->oPtBalloonPoppedScale * 0.6f) * o->oTimer));
}
