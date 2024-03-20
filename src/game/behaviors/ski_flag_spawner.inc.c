void bhv_ski_flag_spawner_loop(void) {
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
        o->oSkiFlagSpawnerBalloonReferenceScale = bProps[gBSMSkiFlagsHit].scale;
        obj->oBehParams = gBSMSkiFlagsHit << 16;
        obj->oBehParams2ndByte = gBSMSkiFlagsHit;
        obj_scale(obj, 0.05f * o->oSkiFlagSpawnerBalloonReferenceScale);
        o->oTimer = 1;
    } else {
        obj_mark_for_deletion(o);
        return;
    }

    gBSMSkiFlagsHit++;

    if (gMarioState->marioObj) {
        obj = o;
        o = gMarioState->marioObj;

        spawn_orange_number(gBSMSkiFlagsHit, 0, 0, 0);
        play_sound(SOUND_MENU_COLLECT_SECRET + (((u8) gBSMSkiFlagsHit - 1) << 16), gGlobalSoundSource);

        o = obj;
    }
}
