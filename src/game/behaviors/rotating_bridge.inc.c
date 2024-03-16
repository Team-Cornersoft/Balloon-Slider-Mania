#define BRIDGE_LENGTH 5800.0f
#define BRIDGE_STARTING_ANGLE -0x2000
#define BRIDGE_MOVE_LENGTH 0x4000

enum RotatingBridgeActions {
    ROTATING_BRIDGE_IDLE,
    ROTATING_BRIDGE_MOVING,
};

static void rotating_bridge_move_tmp_for_mist_particles(void) {
    vec3f_copy(&o->oPosVec, &o->oHomeVec);
}

void bhv_rotating_bridge_init(void) {

}

void bhv_rotating_bridge_loop(void) {
    if (o->oAction == ROTATING_BRIDGE_IDLE || o->oTimer == 0) {
        return;
    }

    o->oFaceAngleYaw += 0x10 * sqr(o->oTimer);

    if (o->oFaceAngleYaw > BRIDGE_MOVE_LENGTH) {
        o->oFaceAngleYaw = BRIDGE_MOVE_LENGTH;
        o->oAction = ROTATING_BRIDGE_IDLE;
        cur_obj_play_sound_2(SOUND_GENERAL_ELEVATOR_LAND);
        rotating_bridge_move_tmp_for_mist_particles();
    } else {
        cur_obj_play_sound_2(SOUND_ENV_METAL_BOX_PUSH);
    }
}
