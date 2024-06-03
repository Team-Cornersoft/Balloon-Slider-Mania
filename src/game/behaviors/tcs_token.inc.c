static struct ObjectHitbox sTCSTokenHitbox = {
    /* interactType:      */ INTERACT_STAR_OR_KEY,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 120,
    /* height:            */ 120,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_tcs_token_init(void) {
    if (gBSMGameplayMode == BSM_MENU_GAMEPLAY_MODE_TIME_TRIALS) {
        obj_mark_for_deletion(o);
        return;
    }

    obj_set_hitbox(o, &sTCSTokenHitbox);
}

void bhv_tcs_token_loop(void) {
    if (o->activeFlags == ACTIVE_FLAG_DEACTIVATED) {
        return;
    }

    o->oFaceAngleYaw += 0x200;

    if (o->oInteractStatus == INT_STATUS_INTERACTED) {
        obj_mark_for_deletion(o);
    }
}