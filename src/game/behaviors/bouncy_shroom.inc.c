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
        set_mario_animation(m, MARIO_ANIM_TRIPLE_JUMP_LAND);
        set_mario_action(m, ACT_MUSHROOM_BOUNCE, 0);
        m->forwardVel = o->oBouncyShroomFVelLastFrame - (o->oBouncyShroomFVelLastFrame * (BPARAM1 / 255.0f));
        m->vel[1] = o->oBouncyShroomBounciness;
    }






    o->oBouncyShroomFVelLastFrame = m->forwardVel;
}
