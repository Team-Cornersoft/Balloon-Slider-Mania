#include "game/debug.h"
#include "game/mario_actions_moving.h"
extern void spawn_orange_number(s8 behParam, s16 relX, s16 relY, s16 relZ);

#define BALLOON_STEP_COUNT 2

struct SharedAreaPointBalloon {
    u8 loaded;
    s32 timer;
    Vec3s oscillateFreq;
    Vec3s oscillateOffset;
    Vec3f oscillateIntensity;
};

static struct SharedAreaPointBalloon sharedAreasPointBalloons[0x3F];


#define BALLOON_FLOATING_CALC(relativePos, intensity, offset, freq) \
    (relativePos + intensity * sins((0x10000 * ((o->oPtBalloonAbsoluteTimer + offset) % freq)) / freq))

static u8 point_balloon_check_if_interacted(void) {
    Vec3f initialMarioPositions;
    Vec3f marioPos;
    Vec3f balloonPos;
    Vec3f requiredDist;
    Vec3f objDist;
    s32 i;
    f32 scale = bProps[o->oBehParams2ndByte].scale;

    if (!gMarioState || !gMarioState->marioObj) {
        return FALSE;
    }

    for (s32 stepCount = 0; stepCount < BALLOON_STEP_COUNT; stepCount++) {
        f32 balancer = 1.0f - ((f32) stepCount / (f32) BALLOON_STEP_COUNT);

        for (i = 0; i < ARRAY_COUNT(initialMarioPositions); i++) {
            initialMarioPositions[i] = (gMarioState->pos[i] * balancer) + (gMarioState->prevPos[i] * (1.0f - balancer));
        }

        vec3f_copy(balloonPos, &o->oPosVec);
        balloonPos[1] -= 10.0f;

        s16 relativeYaw = atan2s(initialMarioPositions[2] - o->oPosZ, initialMarioPositions[0] - o->oPosX) - o->oFaceAngleYaw; // atan2s equivalent is obj_angle_to_object()

        // lateral_dist_between_objects() equivalent
        f32 distX = o->oPosX - initialMarioPositions[0];
        f32 distZ = o->oPosZ - initialMarioPositions[2];
        f32 dist = sqrtf(sqr(distX) + sqr(distZ));

        marioPos[0] = balloonPos[0] + sins(relativeYaw) * dist;
        marioPos[1] = initialMarioPositions[1] + ABS(gMarioState->marioObj->hitboxHeight) / 2.0f;
        marioPos[2] = balloonPos[2] + coss(relativeYaw) * dist;

        objDist[0] = ABS(marioPos[0] - balloonPos[0]) - ABS(gMarioState->marioObj->hitboxRadius);
        objDist[1] = ABS(marioPos[1] - balloonPos[1]) - ABS(gMarioState->marioObj->hitboxHeight) / 2.0f;
        objDist[2] = ABS(marioPos[2] - balloonPos[2]) - ABS(gMarioState->marioObj->hitboxRadius);

        requiredDist[0] = 95.0f * scale;
        requiredDist[1] = (110.0f + 5.0f) * scale + 5.0f; // Increase hitbox Y slightly to reduce likelihood of sliding under balloons
        requiredDist[2] = 45.0f * scale;

        for (i = 0; i < ARRAY_COUNT(objDist); i++) {
            if (objDist[i] < 0.0f) {
                objDist[i] = 0.0f;
            }
            if (requiredDist[i] < 0.01f) {
                requiredDist[i] = 0.01f;
            }
        }

        if (
           objDist[0] > requiredDist[0] ||
           objDist[1] > requiredDist[1] ||
           objDist[2] > requiredDist[2]
        ) {
            continue;
        }

        if (
           objDist[0] > (requiredDist[0] * coss(sqrtf(sqr(objDist[1]) + sqr(objDist[2])) / sqrtf(sqr(requiredDist[1]) + sqr(requiredDist[2])) * 0x4000)) ||
           objDist[1] > (requiredDist[1] * coss(sqrtf(sqr(objDist[0]) + sqr(objDist[2])) / sqrtf(sqr(requiredDist[0]) + sqr(requiredDist[2])) * 0x4000)) ||
           objDist[2] > (requiredDist[2] * coss(sqrtf(sqr(objDist[0]) + sqr(objDist[1])) / sqrtf(sqr(requiredDist[0]) + sqr(requiredDist[1])) * 0x4000))
        ) {
            continue;
        }

        return TRUE;
    }

    return FALSE;
}

static u8 key_balloon_check_if_interacted(void) {
    Vec3f initialMarioPositions;
    Vec3f marioPos;
    Vec3f balloonPos;
    Vec3f requiredDist;
    Vec3f objDist;
    s32 i;
    f32 scale = keyBalloon.scale;

    if (!gMarioState || !gMarioState->marioObj) {
        return FALSE;
    }

    for (s32 stepCount = 0; stepCount < BALLOON_STEP_COUNT; stepCount++) {
        f32 balancer = 1.0f - ((f32) stepCount / (f32) BALLOON_STEP_COUNT);

        for (i = 0; i < ARRAY_COUNT(initialMarioPositions); i++) {
            initialMarioPositions[i] = (gMarioState->pos[i] * balancer) + (gMarioState->prevPos[i] * (1.0f - balancer));
        }

        vec3f_copy(balloonPos, &o->oPosVec);
        balloonPos[1] -= 10.0f;

        s16 relativeYaw = atan2s(initialMarioPositions[2] - o->oPosZ, initialMarioPositions[0] - o->oPosX) - o->oFaceAngleYaw; // atan2s equivalent is obj_angle_to_object()

        // lateral_dist_between_objects() equivalent
        f32 distX = o->oPosX - initialMarioPositions[0];
        f32 distZ = o->oPosZ - initialMarioPositions[2];
        f32 dist = sqrtf(sqr(distX) + sqr(distZ));

        marioPos[0] = balloonPos[0] + sins(relativeYaw) * dist;
        marioPos[1] = initialMarioPositions[1] + ABS(gMarioState->marioObj->hitboxHeight) / 2.0f;
        marioPos[2] = balloonPos[2] + coss(relativeYaw) * dist;

        objDist[0] = ABS(marioPos[0] - balloonPos[0]) - ABS(gMarioState->marioObj->hitboxRadius);
        objDist[1] = ABS(marioPos[1] - balloonPos[1]) - ABS(gMarioState->marioObj->hitboxHeight) / 2.0f;
        objDist[2] = ABS(marioPos[2] - balloonPos[2]) - ABS(gMarioState->marioObj->hitboxRadius);

        requiredDist[0] = 95.0f * scale;
        requiredDist[1] = (225.0f + 5.0f) * scale + 5.0f; // Increase hitbox Y slightly to reduce likelihood of sliding under balloons
        requiredDist[2] = 50.0f * scale;

        for (i = 0; i < ARRAY_COUNT(objDist); i++) {
            if (objDist[i] < 0.0f) {
                objDist[i] = 0.0f;
            }
            if (requiredDist[i] < 0.01f) {
                requiredDist[i] = 0.01f;
            }
        }

        if (
           objDist[0] > requiredDist[0] ||
           objDist[1] > requiredDist[1] ||
           objDist[2] > requiredDist[2]
        ) {
            continue;
        }

        // Generously ignore Y elements of hitbox for key balloons
        if (
           objDist[0] > (requiredDist[0] * coss(objDist[2] / requiredDist[2] * 0x4000)) ||
           objDist[1] > requiredDist[1] ||
           objDist[2] > (requiredDist[2] * coss(objDist[0] / requiredDist[0] * 0x4000))
        ) {
            continue;
        }

        return TRUE;
    }

    return FALSE;
}

static void init_shared_generic_balloon_positions(void) {
    if (BPARAM4 == 0) {
        return;
    }

    u32 index = BPARAM4 - 1;
    assert(index < ARRAY_COUNT(sharedAreasPointBalloons), "bparam4 balloon index out of supported range!");

    if (!sharedAreasPointBalloons[index].loaded) {
        sharedAreasPointBalloons[index].loaded = TRUE;
        return;
    }

    // Copy balloon position from previous area
    o->oPtBalloonAbsoluteTimer = sharedAreasPointBalloons[index].timer;

    o->oPtBalloonOscillateXFreq = sharedAreasPointBalloons[index].oscillateFreq[0];
    o->oPtBalloonOscillateYFreq = sharedAreasPointBalloons[index].oscillateFreq[1];
    o->oPtBalloonOscillateZFreq = sharedAreasPointBalloons[index].oscillateFreq[2];

    o->oPtBalloonOscillateXOffset = sharedAreasPointBalloons[index].oscillateOffset[0];
    o->oPtBalloonOscillateYOffset = sharedAreasPointBalloons[index].oscillateOffset[1];
    o->oPtBalloonOscillateZOffset = sharedAreasPointBalloons[index].oscillateOffset[2];

    o->oPtBalloonOscillateXIntensity = sharedAreasPointBalloons[index].oscillateIntensity[0];
    o->oPtBalloonOscillateYIntensity = sharedAreasPointBalloons[index].oscillateIntensity[1];
    o->oPtBalloonOscillateZIntensity = sharedAreasPointBalloons[index].oscillateIntensity[2];
}

static void update_generic_balloon_positions(void) {
    o->oPosX = BALLOON_FLOATING_CALC(o->oPtBalloonRelativePosX, o->oPtBalloonOscillateXIntensity, o->oPtBalloonOscillateXOffset, o->oPtBalloonOscillateXFreq);
    o->oPosY = BALLOON_FLOATING_CALC(o->oPtBalloonRelativePosY, o->oPtBalloonOscillateYIntensity, o->oPtBalloonOscillateYOffset, o->oPtBalloonOscillateYFreq);
    o->oPosZ = BALLOON_FLOATING_CALC(o->oPtBalloonRelativePosZ, o->oPtBalloonOscillateZIntensity, o->oPtBalloonOscillateZOffset, o->oPtBalloonOscillateZFreq);

    o->oPtBalloonAbsoluteTimer++;

    if (BPARAM4 > 0) {
        u32 index = BPARAM4 - 1;
        sharedAreasPointBalloons[index].timer = o->oPtBalloonAbsoluteTimer;

        sharedAreasPointBalloons[index].oscillateFreq[0] = o->oPtBalloonOscillateXFreq;
        sharedAreasPointBalloons[index].oscillateFreq[1] = o->oPtBalloonOscillateYFreq;
        sharedAreasPointBalloons[index].oscillateFreq[2] = o->oPtBalloonOscillateZFreq;

        sharedAreasPointBalloons[index].oscillateOffset[0] = o->oPtBalloonOscillateXOffset;
        sharedAreasPointBalloons[index].oscillateOffset[1] = o->oPtBalloonOscillateYOffset;
        sharedAreasPointBalloons[index].oscillateOffset[2] = o->oPtBalloonOscillateZOffset;

        sharedAreasPointBalloons[index].oscillateIntensity[0] = o->oPtBalloonOscillateXIntensity;
        sharedAreasPointBalloons[index].oscillateIntensity[1] = o->oPtBalloonOscillateYIntensity;
        sharedAreasPointBalloons[index].oscillateIntensity[2] = o->oPtBalloonOscillateZIntensity;
    }
}

void bhv_point_balloon_init(void) {
    if (gBSMGameplayMode == BSM_MENU_GAMEPLAY_MODE_TIME_TRIALS) {
        obj_mark_for_deletion(o);
        return;
    }

    u32 bType = o->oBehParams2ndByte;
    assert(bType < POINT_BALLOON_COUNT, "Invalid point balloon type detected!");

    if (!obj_has_behavior(o->parentObj, bhvSkiFlagSpawner)) {
        cur_obj_scale(bProps[bType].scale);
    }
    o->oHomeY += bProps[bType].scale * 110.0f + (10.0f * bProps[bType].scale) + 25.0f;

    vec3f_copy(&o->oPosVec, &o->oHomeVec);
    vec3f_copy(&o->oPtBalloonRelativePosVec, &o->oHomeVec);

    o->oPtBalloonOscillateXFreq = (random_u16() % (u32) (60.0f * bProps[bType].scale)) + 120;
    o->oPtBalloonOscillateXOffset = random_u16() % o->oPtBalloonOscillateXFreq;
    o->oPtBalloonOscillateXIntensity = (f32) (random_u16() % (u32) (20 * bProps[bType].scale));

    o->oPtBalloonOscillateYFreq = random_u16() % (u32) (40.0f * bProps[bType].scale) + 75;
    o->oPtBalloonOscillateYOffset = random_u16() % o->oPtBalloonOscillateYFreq;
    o->oPtBalloonOscillateYIntensity = (f32) (random_u16() % (u32) (30 * sqrtf(bProps[bType].scale))) + 10;

    o->oPtBalloonOscillateZFreq = (random_u16() % (u32) (60.0f * bProps[bType].scale)) + 120;
    o->oPtBalloonOscillateZOffset = random_u16() % o->oPtBalloonOscillateZFreq;
    o->oPtBalloonOscillateZIntensity = (f32) (random_u16() % (u32) (20 * bProps[bType].scale));

    assert(o->oPtBalloonOscillateXFreq != 0, "Balloon X freq is 0!");
    assert(o->oPtBalloonOscillateYFreq != 0, "Balloon Y freq is 0!");
    assert(o->oPtBalloonOscillateZFreq != 0, "Balloon Z freq is 0!");

    init_shared_generic_balloon_positions();
}

void bhv_point_balloon_loop(void) {
    u32 bType = o->oBehParams2ndByte;
    f32 scale = bProps[bType].scale;

    if (o->activeFlags == ACTIVE_FLAG_DEACTIVATED) {
        return;
    }

    // slideSpeedMultiplier added here to handle high Mario velocities
    if (o->oDistanceToMario <= ((120.0f * scale) + 160.0f /*About Mario's height*/) * slideSpeedMultiplier) {
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
                struct Object *balloonPop = spawn_object(o, MODEL_NONE, bhvPointBalloonPopped);
                if (balloonPop) {
                    obj_scale(balloonPop, scale * 0.25f);
                    balloonPop->oBehParams = o->oBehParams;
                    balloonPop->oBehParams2ndByte = o->oBehParams2ndByte;
                }
            }
            obj_mark_for_deletion(o);
        }
    }

    update_generic_balloon_positions();
}

void bhv_key_balloon_init(void) {
    vec3f_copy(&o->oPtBalloonRelativePosVec, &o->oHomeVec);
    cur_obj_scale(keyBalloon.scale);

    o->oPtBalloonOscillateXFreq = (random_u16() % (u32) (120.0f * keyBalloon.scale)) + 120;
    o->oPtBalloonOscillateXOffset = random_u16() % o->oPtBalloonOscillateXFreq;
    o->oPtBalloonOscillateXIntensity = (f32) (random_u16() % (u32) (20 * keyBalloon.scale));

    o->oPtBalloonOscillateYFreq = random_u16() % (u32) (170.0f * keyBalloon.scale) + 75;
    o->oPtBalloonOscillateYOffset = random_u16() % o->oPtBalloonOscillateYFreq;
    o->oPtBalloonOscillateYIntensity = (f32) (random_u16() % (u32) (35 * keyBalloon.scale)) + 5;

    o->oPtBalloonOscillateZFreq = (random_u16() % (u32) (120.0f * keyBalloon.scale)) + 120;
    o->oPtBalloonOscillateZOffset = random_u16() % o->oPtBalloonOscillateZFreq;
    o->oPtBalloonOscillateZIntensity = (f32) (random_u16() % (u32) (20 * keyBalloon.scale));

    assert(o->oPtBalloonOscillateXFreq != 0, "Balloon X freq is 0!");
    assert(o->oPtBalloonOscillateYFreq != 0, "Balloon Y freq is 0!");
    assert(o->oPtBalloonOscillateZFreq != 0, "Balloon Z freq is 0!");

    init_shared_generic_balloon_positions();
}

void bhv_key_balloon_loop(void) {
    f32 scale = keyBalloon.scale;

    if (o->oDistanceToMario <= ((225.0f * scale) + 160.0f /*About Mario's height*/) * slideSpeedMultiplier) {
        if (key_balloon_check_if_interacted()) {
            if (!(gEmulator & NO_CULLING_EMULATOR_BLACKLIST)) {
                spawn_mist_particles_variable(16, -120.0f + (110.0f * scale), 46.0f * scale);
                spawn_mist_particles_variable(16, -120.0f - (110.0f * scale), 46.0f * scale);
                struct Object *balloonPop = spawn_object_relative(0xFF, 0, 110 * scale, 0, o, MODEL_BSM_POINT_BALLOON_POPPED, bhvPointBalloonPopped);
                if (balloonPop) {
                    obj_scale(balloonPop, scale * 0.25f);
                    SET_BPARAM1(balloonPop->oBehParams, BPARAM1);
                    SET_BPARAM3(balloonPop->oBehParams, BPARAM3);
                    SET_BPARAM4(balloonPop->oBehParams, BPARAM4);
                }
                spawn_mist_particles_variable(4, -120.0f + (110.0f * scale), 46.0f * scale);
                spawn_mist_particles_variable(4, -120.0f - (110.0f * scale), 46.0f * scale);
            } else {
                struct Object *balloonPop = spawn_object_relative(0xFF, 0, 110 * scale, 0, o, MODEL_NONE, bhvPointBalloonPopped);
                if (balloonPop) {
                    obj_scale(balloonPop, scale * 0.25f);
                    SET_BPARAM1(balloonPop->oBehParams, BPARAM1);
                    SET_BPARAM3(balloonPop->oBehParams, BPARAM3);
                    SET_BPARAM4(balloonPop->oBehParams, BPARAM4);
                }
                spawn_mist_particles_variable(8, -120.0f + (110.0f * scale), 46.0f * scale);
                spawn_mist_particles_variable(8, -120.0f - (110.0f * scale), 46.0f * scale);
            }
            obj_mark_for_deletion(o);
        }
    }

    update_generic_balloon_positions();
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
        struct BalloonTypeProperties *props;

        if (o->oBehParams2ndByte == 0xFF) {
            props = &keyBalloon;
            gBSMNarratorItemTimer = 10;
        } else {
            props = &bProps[o->oBehParams2ndByte];
            assert(o->oBehParams2ndByte < ARRAY_COUNT(bProps), "Invalid balloon pop type!");
            if (props->points != 0) {
                if (props->points < 0 && gBSMScoreCount < (u32) -props->points) {
                    gBSMScoreCount = 0;
                } else {
                    gBSMScoreCount += props->points;
                }
                gBSMLastBalloonType = o->oBehParams2ndByte;
            }
        }

        cur_obj_play_sound_2(props->popsfx);

        if (props == &bProps[POINT_BALLOON_RED]) {
            assert(gBSMRedBalloonsPopped < 8, "Tried to collect more than 8 red balloons!");
            if (gBSMRedBalloonsPopped < 8) {
                play_sound(props->popjingle + (gBSMRedBalloonsPopped << SOUNDARGS_SHIFT_SOUNDID), gGlobalSoundSource);
                gBSMRedBalloonsPopped++;
                spawn_orange_number(gBSMRedBalloonsPopped, 0, 0, 0);
            }
        } else if (props == &keyBalloon) {
            gBSMKeyCollected = TRUE;
            play_sound(props->popjingle, gGlobalSoundSource);
        } else {
            play_sound(props->popjingle, gGlobalSoundSource);
        }
    }

    o->oPosX = o->oHomeX - (5.0f + 40.0f * random_float()) * o->oPtBalloonPoppedScale;
    o->oPosY = o->oHomeY - (5.0f + 40.0f * random_float()) * o->oPtBalloonPoppedScale;
    o->oPosZ = o->oHomeZ - (5.0f + 40.0f * random_float()) * o->oPtBalloonPoppedScale;

    cur_obj_scale(o->oPtBalloonPoppedScale + ((o->oPtBalloonPoppedScale * 0.6f) * o->oTimer));
}

void bhv_key_gate_loop(void) {
    if (gBSMKeyCollected) {
        struct Object *obj = spawn_object(o, MODEL_BSM_KEY_GATE, bhvKeyGateOpen);
        if (obj) {
            obj->parentObj = obj;
        }

        obj_mark_for_deletion(o);
    } else {
        load_object_collision_model();
    }
}

void bhv_item_gate_loop(void) {
    u32 countNeeded = 5;
    if (o->oBehParams2ndByte != 0) {
        countNeeded = o->oBehParams2ndByte;
    }

    if (gBSMCountTo5 >= countNeeded) {
        struct Object *obj = spawn_object(o, MODEL_BSM_ITEM_GATE, bhvItemGateOpen);
        if (obj) {
            obj->parentObj = obj;
        }

        obj_mark_for_deletion(o);
    } else {
        load_object_collision_model();
    }
}

void bhv_title_screen_balloon_init(void) {
    // Do not fill shared area slots
    SET_BPARAM4(o->oBehParams, 0);

    f32 scale = 1.5f; // Does not actually scale the object

    vec3f_copy(&o->oPosVec, &o->oHomeVec);
    vec3f_copy(&o->oPtBalloonRelativePosVec, &o->oHomeVec);

    o->oPtBalloonOscillateXFreq = (random_u16() % (u32) (60.0f * scale)) + 120;
    o->oPtBalloonOscillateXOffset = random_u16() % o->oPtBalloonOscillateXFreq;
    o->oPtBalloonOscillateXIntensity = (f32) (random_u16() % (u32) (20 * scale));

    o->oPtBalloonOscillateYFreq = random_u16() % (u32) (40.0f * scale) + 75;
    o->oPtBalloonOscillateYOffset = random_u16() % o->oPtBalloonOscillateYFreq;
    o->oPtBalloonOscillateYIntensity = (f32) (random_u16() % (u32) (30 * sqrtf(scale))) + 10;

    o->oPtBalloonOscillateZFreq = (random_u16() % (u32) (60.0f * scale)) + 120;
    o->oPtBalloonOscillateZOffset = random_u16() % o->oPtBalloonOscillateZFreq;
    o->oPtBalloonOscillateZIntensity = (f32) (random_u16() % (u32) (20 * scale));

    assert(o->oPtBalloonOscillateXFreq != 0, "Balloon X freq is 0!");
    assert(o->oPtBalloonOscillateYFreq != 0, "Balloon Y freq is 0!");
    assert(o->oPtBalloonOscillateZFreq != 0, "Balloon Z freq is 0!");

    f32 decreaseY = 1800.0f + ((random_u16() & 0x1FFF));
    o->oPosY -= decreaseY;
    o->oPtBalloonRelativePosY -= decreaseY;

    o->oPtBalloonLerpSpeed = random_float() * 0.015f + 0.02f;
}

void bhv_title_screen_balloon_loop(void) {
    o->oPtBalloonRelativePosY = lerpf(o->oPtBalloonRelativePosY, o->oHomeY, o->oPtBalloonLerpSpeed);
    
    update_generic_balloon_positions();
}

void clear_shared_area_point_balloons(void) {
    bzero(sharedAreasPointBalloons, sizeof(sharedAreasPointBalloons));
}
