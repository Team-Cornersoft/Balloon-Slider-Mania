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

static u8 point_balloon_check_if_interacted(void) {
    // TODO:
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
    o->oOpacity = 105;
}

void bhv_point_balloon_popped_loop(void) {
    o->oOpacity -= 15;
    if (o->oOpacity <= 0) {
        obj_mark_for_deletion(o);
        return;
    }

    // TODO:
    if (o->oTimer == 0) {
        switch (o->oBehParams2ndByte) {
            case POINT_BALLOON_5:
                // cur_obj_play_sound_2(SOUND_GENERAL2_BALLOON_POP_SMALLEST);
                // play_sound(SOUND_EXTRA_POINTS_5, gGlobalSoundSource);
                break;
            case POINT_BALLOON_10:
                // cur_obj_play_sound_2(SOUND_GENERAL2_BALLOON_POP_SMALL);
                // play_sound(SOUND_EXTRA_POINTS_10, gGlobalSoundSource);
                break;
            case POINT_BALLOON_25:
                // cur_obj_play_sound_2(SOUND_GENERAL2_BALLOON_POP_MEDIUM);
                // play_sound(SOUND_EXTRA_POINTS_25, gGlobalSoundSource);
                break;
            case POINT_BALLOON_50:
                // cur_obj_play_sound_2(SOUND_GENERAL2_BALLOON_POP_LARGE);
                // play_sound(SOUND_EXTRA_POINTS_50, gGlobalSoundSource);
                break;
            case POINT_BALLOON_100:
                // cur_obj_play_sound_2(SOUND_GENERAL2_BALLOON_POP_HUGE);
                // play_sound(SOUND_EXTRA_POINTS_100, gGlobalSoundSource);
                break;
            default:
                assert(FALSE, "Missed pop condition for new balloon type!");
                // cur_obj_play_sound_2(SOUND_GENERAL2_BALLOON_POP_SMALLEST);
                // play_sound(SOUND_EXTRA_POINTS_5, gGlobalSoundSource);
                break;
        }
    }

    o->oPosX = o->oHomeX - (5.0f + 40.0f * random_float()) * o->oPtBalloonPoppedScale;
    o->oPosY = o->oHomeY - (5.0f + 40.0f * random_float()) * o->oPtBalloonPoppedScale;
    o->oPosZ = o->oHomeZ - (5.0f + 40.0f * random_float()) * o->oPtBalloonPoppedScale;

    cur_obj_scale(o->oPtBalloonPoppedScale + ((o->oPtBalloonPoppedScale * 0.6f) * o->oTimer));
}
