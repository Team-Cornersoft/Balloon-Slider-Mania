#define BELL_RADIUS 350.0f
#define BELL_HEIGHT 750.0f

#define BELL_RING_PEAK 0x4000
#define BELL_RING_SLOW_RATE 0x80
#define BELL_RING_FREQ 52
#define BELL_FRICTION 0.98f

enum BellGongActions {
    BELL_GONG_IDLE,
    BELL_GONG_RINGING,
    BELL_GONG_STOP,
};

static s32 bell_gong_check_if_interacted(void) {
    if (!gMarioState || !gMarioState->marioObj) {
        return FALSE;
    }

    if (lateral_dist_between_objects(gMarioState->marioObj, o) > BELL_RADIUS) {
        return FALSE;
    }

    f32 distY = (o->oPosY - (BELL_HEIGHT / 2)) - gMarioState->pos[1];
    if (ABS(distY) > (BELL_HEIGHT / 2)) {
        return FALSE;
    }

    return TRUE;
}

static void bell_gong_ring(void) {
    if (o->oFriction < 0.001f) {
        o->oAction = BELL_GONG_STOP;
        o->oFaceAnglePitch = 0x0;
        return;
    }

    o->oFaceAnglePitch = sins((o->oTimer % BELL_RING_FREQ) * (0x10000 / BELL_RING_FREQ)) * (BELL_RING_PEAK * o->oFriction);
    o->oFriction *= BELL_FRICTION;
}

void bhv_bell_gong_init(void) {

}

void bhv_bell_gong_loop(void) {
    switch(o->oAction) {
        case BELL_GONG_IDLE:
            if (!bell_gong_check_if_interacted()) {
                break;
            }

            struct Object *obj = find_first_object_with_behavior_and_bparams(bhvRotatingBridge, o->oBehParams, 0x00FF0000);
            assert(obj != NULL, "Bridge object with matching bparam2 not found!");
            if (obj) {
                obj->oAction++;
            }

            o->oAction = BELL_GONG_RINGING;
            o->oFriction = 1.0f;
            if (cur_obj_has_model(MODEL_BSM_BELL)) {
                cur_obj_play_sound_2(SOUND_SPECIAL1_BSM_BELL);
            } else {
                cur_obj_play_sound_2(SOUND_SPECIAL1_BSM_GONG);
            }
            break;
        case BELL_GONG_RINGING:
            bell_gong_ring();
            break;
        case BELL_GONG_STOP:
        default:
            break;
    }
}
