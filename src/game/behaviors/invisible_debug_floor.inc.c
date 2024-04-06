void bhv_invisible_debug_floor_loop(void) {
    if (gMarioState && gMarioObject && gMarioState->action == ACT_DEBUG_FREE_MOVE) {
        o->oPosX = gMarioObject->oPosX;
        o->oPosY = FLOOR_LOWER_LIMIT + 50.0f;
        o->oPosZ = gMarioObject->oPosZ;
#ifdef PUPPYPRINT_DEBUG
        if (fDebug && sPPDebugPage == PUPPYPRINT_PAGE_SMOOTH_VIDEO) {
            o->oPosY = MAX(FLOOR_LOWER_LIMIT, gMarioObject->oPosY - 150.0f);
        }
#endif
    } else {
        o->oPosY = FLOOR_LOWER_LIMIT + 50.0f;
    }
}