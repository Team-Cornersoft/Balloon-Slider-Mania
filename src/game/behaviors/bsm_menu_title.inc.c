#define SINE_FRAMES 360
#define MAX_ROTATION_OFFSET 0x400
#define MAX_SCALE_DIFF 0.02f
#define BASE_SCALE 0.725f

static void bhv_bsm_menu_title_update_scale(void) {
    if (o->oAnimState == (u8) gBSMGameplayMode) {
        o->oBSMMenuTitleGeneralScale = smoothstop(o->oBSMMenuTitleGeneralScale, 1.0f, 0.35f);
    } else {
        o->oBSMMenuTitleGeneralScale = smoothstop(o->oBSMMenuTitleGeneralScale, 0.0f, 0.35f);
    }

    if (o->oBSMMenuTitleGeneralScale <= 0.005f) {
        o->oBSMMenuTitleGeneralScale = 0.005f;
        cur_obj_hide();
        o->oAnimState = gBSMGameplayMode;
    } else {
        cur_obj_unhide();
    }

    if (gBSMShowStats.isShowingStats) {
        o->oPosZ = 100;
    } else {
        o->oPosZ = o->oHomeZ;
    }
}

void bhv_bsm_menu_title_init(void) {
    cur_obj_scale(BASE_SCALE);

    o->oBSMMenuTitleRollHome = o->oFaceAngleRoll;
    o->oAnimState = gBSMGameplayMode;
    o->oBSMMenuTitleGeneralScale = 1.0f;
}

void bhv_bsm_menu_title_loop(void) {
    f32 sinCalc = sins(65536.0f * ((f32) o->oBSMMenuTitleSineFunc / (f32) SINE_FRAMES));
    f32 halfSinCalc = sins(65536.0f * ((f32) o->oBSMMenuTitleSineFunc / (f32) (SINE_FRAMES / 2)));
    f32 scale = BASE_SCALE + (MAX_SCALE_DIFF * halfSinCalc);
    o->oFaceAngleRoll = o->oBSMMenuTitleRollHome + (MAX_ROTATION_OFFSET * sinCalc);

    o->oBSMMenuTitleSineFunc = (o->oBSMMenuTitleSineFunc + 1) % SINE_FRAMES;

    o->oPosX = o->oHomeX + BSM_MENU_CAMERA_LAYOUT_OFFSET;

    bhv_bsm_menu_title_update_scale();

    scale *= o->oBSMMenuTitleGeneralScale;
    cur_obj_scale(scale);
}
