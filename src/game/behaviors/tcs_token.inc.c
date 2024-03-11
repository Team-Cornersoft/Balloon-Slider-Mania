static struct ObjectHitbox sTCSTokenHitbox = {
    /* interactType:      */ INTERACT_STAR_OR_KEY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_tcs_token_init(void) {
    obj_set_hitbox(o, &sTCSTokenHitbox);
}

void bhv_tcs_token_loop(void) {
    o->oFaceAngleYaw += 0x200;

    if (o->oInteractStatus == INT_STATUS_INTERACTED) {
        obj_mark_for_deletion(o);
    }
}