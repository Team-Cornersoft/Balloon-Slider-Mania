void bhv_ski_flag_spawner_loop(void) {
    if (gBSMGameplayMode == BSM_MENU_GAMEPLAY_MODE_TIME_TRIALS) {
        obj_mark_for_deletion(o);
        return;
    }

    if (o->oSkiFlagSpawnerBalloon) {
        obj_scale(o->oSkiFlagSpawnerBalloon, (0.05f * o->oTimer) * o->oSkiFlagSpawnerBalloonReferenceScale);

        if (o->oTimer >= 20) {
            o->oSkiFlagSpawnerBalloon->parentObj = o->oSkiFlagSpawnerBalloon;
            o->oSkiFlagSpawnerBalloon = NULL;
            obj_mark_for_deletion(o);
        }
        return;
    }

    if (!gMarioState || !gMarioState->floor || gMarioState->floor->type != o->oBehParams2ndByte) {
        return;
    }

    struct Object *obj = spawn_object(o, MODEL_BSM_POINT_BALLOON, bhvPointBalloon);
    if (obj) {
        o->oSkiFlagSpawnerBalloon = obj;
        o->oSkiFlagSpawnerBalloonReferenceScale = bProps[gBSMCountTo5].scale;
        obj->oBehParams = gBSMCountTo5 << 16;
        obj->oBehParams2ndByte = gBSMCountTo5;
        obj_scale(obj, 0.05f * o->oSkiFlagSpawnerBalloonReferenceScale);
        o->oTimer = 1;
    } else {
        obj_mark_for_deletion(o);
        return;
    }

    gBSMCountTo5++;
    if (gBSMCountTo5 == 5) {
        gBSMNarratorItemTimer = 10;
    }

    if (gMarioState->marioObj) {
        obj = o;
        o = gMarioState->marioObj;

        spawn_orange_number(gBSMCountTo5, 0, 0, 0);
        play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) gBSMCountTo5 - 1) << 16), gGlobalSoundSource);

        o = obj;
    }
}

#define PRESENT_Y_OSCILLATION 64
#define PRESENT_Y_AMPLITUDE 25.0f
void bhv_present_init(void) {
    o->oHomeY += 100.0f + 50.0f;
    o->oPosY += 100.0f + 50.0f;
    gCurrentObject->hitboxRadius = 150.0f;
    gCurrentObject->hitboxHeight = 265.0f + PRESENT_Y_AMPLITUDE;
    gCurrentObject->hitboxDownOffset = 100.0f;
}

void bhv_present_loop(void) {
    if (obj_check_if_collided_with_object(o, gMarioObject)) {
        gBSMCountTo5++;
        if (gBSMCountTo5 == 5) {
            gBSMNarratorItemTimer = 10;
        }

        spawn_orange_number(gBSMCountTo5, 0, 0, 0);
        play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) gBSMCountTo5 - 1) << 16), gGlobalSoundSource);
        cur_obj_play_sound_2(SOUND_EXTRA1_BSM_BALLOON_SEMILARGE);
        spawn_mist_particles();

        obj_mark_for_deletion(o);
        return;
    }

    o->oFaceAngleYaw += 0x200;
    o->oGraphYOffset = PRESENT_Y_AMPLITUDE * (1.0f + sins(0x10000 * o->oTimer / PRESENT_Y_OSCILLATION));
}
