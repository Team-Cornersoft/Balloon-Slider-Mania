#define BOUNCY_SHROOM_DEFAULT_BOUNCINESS 4.0f

void bhv_bouncy_shroom_init(void) {
    o->oBouncyShroomBounciness = o->oBehParams2ndByte * (BOUNCY_SHROOM_DEFAULT_BOUNCINESS);

    if (o->oBehParams2ndByte == 0) {
        o->oBouncyShroomBounciness = BOUNCY_SHROOM_DEFAULT_BOUNCINESS * 32.0f;
    }
}

void bhv_bouncy_shroom_loop(void) {
    struct MarioState *m = gMarioState;

    if (m && m->floor && m->floor->object == o && !(m->action & ACT_FLAG_AIR)) {
        // if (o->oAction != 1 || o->oTimer >= 15) {
            set_mario_animation(m, MARIO_ANIM_TRIPLE_JUMP_LAND);
            set_mario_action(m, ACT_MUSHROOM_BOUNCE, 0);
            m->forwardVel = o->oBouncyShroomFVelLastFrame - (o->oBouncyShroomFVelLastFrame * (BPARAM1 / 255.0f));
            m->vel[1] = o->oBouncyShroomBounciness;
            o->oAction = 1;
            o->oPrevAction = 1;
            o->oTimer = 0;
            o->oBouncyShroomOscillation = 0;
            o->oBouncyShroomOscillationIntensity = 0.35f;
            cur_obj_play_sound_2(SOUND_SPECIAL1_BSM_BOUNCY_MUSHROOM);
        // }
    }

    if (o->oAction == 1) {
        o->oBouncyShroomOscillation += 0x58 * (o->oTimer + 20);
        o->oBouncyShroomOscillationIntensity *= 0.97f;

        if (o->oBouncyShroomOscillationIntensity < 0.001f) {
            o->oAction = 0;
            o->oBouncyShroomOscillation = 0;
            o->oBouncyShroomOscillationIntensity = 0.0f;
        }
    }

    f32 mushScale = o->oBouncyShroomOscillationIntensity * sins(o->oBouncyShroomOscillation);
    o->header.gfx.scale[0] = 1.0f + mushScale;
    o->header.gfx.scale[1] = sqr(1.0f - mushScale);
    o->header.gfx.scale[2] = 1.0f + mushScale;

    o->oBouncyShroomFVelLastFrame = m->forwardVel;
}
