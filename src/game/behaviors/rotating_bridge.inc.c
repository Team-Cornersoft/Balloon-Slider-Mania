#include "levels/hmc/header.h"

#define BRIDGE_LENGTH 5800.0f
#define BRIDGE_STARTING_ANGLE 0x6000
#define BRIDGE_MOVE_LENGTH 0x4000

enum RotatingBridgeActions {
    ROTATING_BRIDGE_IDLE,
    ROTATING_BRIDGE_MOVING,
};

static void rotating_bridge_update_child_balloon(void) {
    struct Object *obj = o->oRotatingBridgeBalloonChild;
    if (!obj || obj->activeFlags == ACTIVE_FLAG_DEACTIVATED) {
        o->oRotatingBridgeBalloonChild = NULL;
        return;
    }
    
    obj->oPtBalloonRelativePosX = obj->oHomeX + (BRIDGE_LENGTH * 2 / 5) * sins(o->oFaceAngleYaw + BRIDGE_STARTING_ANGLE);
    obj->oPtBalloonRelativePosY = obj->oHomeY - 275.0f;
    obj->oPtBalloonRelativePosZ = obj->oHomeZ + (BRIDGE_LENGTH * 2 / 5) * coss(o->oFaceAngleYaw + BRIDGE_STARTING_ANGLE);

    obj->oFaceAngleYaw = o->oFaceAngleYaw + BRIDGE_STARTING_ANGLE;
}

void bhv_rotating_bridge_init(void) {
    o->oRotatingBridgeYawHome = o->oFaceAngleYaw;

    if (COURSE_NUM_TO_INDEX(gCurrCourseNum) == BSM_COURSE_6_SCORCH_ISLE) {
        o->collisionData = segmented_to_virtual(custom_moving_dragon_bridge_collision);
    }

    struct Object *obj = spawn_object(o, MODEL_BSM_POINT_BALLOON, bhvPointBalloon);
    if (obj) {
        vec3f_copy(&obj->oHomeVec, &obj->oPosVec);
        obj->oBehParams2ndByte = POINT_BALLOON_25;
        obj->oBehParams = POINT_BALLOON_25 << 16;
        o->oRotatingBridgeBalloonChild = obj;
    }
}

void bhv_rotating_bridge_loop(void) {
    rotating_bridge_update_child_balloon();
    if (o->oAction == ROTATING_BRIDGE_IDLE || o->oTimer == 0) {
        return;
    }

    o->oRotatingBridgeYawRotated += (BRIDGE_MOVE_LENGTH / 0xC00) * sqr(o->oTimer);

    if (o->oRotatingBridgeYawRotated >= BRIDGE_MOVE_LENGTH) {
        o->oRotatingBridgeYawRotated = BRIDGE_MOVE_LENGTH;
        o->oAction = ROTATING_BRIDGE_IDLE;
        cur_obj_play_sound_2(SOUND_GENERAL_ELEVATOR_LAND);
    } else {
        cur_obj_play_sound_2(SOUND_ENV_METAL_BOX_PUSH);
    }

    o->oFaceAngleYaw = o->oRotatingBridgeYawHome - o->oRotatingBridgeYawRotated;
}
