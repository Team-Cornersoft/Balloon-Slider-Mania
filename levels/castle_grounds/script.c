#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
#include "levels/intro/header.h"
#include "game/area.h"
#include "game/texscroll.h"
#include "game/bsm_level_select_menu.h"
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
static const LevelScript cgds_area1_jump[] = {
	OBJECT(MODEL_BSM_MENU_TITLE,   -980, 2020, 540, 0, 0, 15, 0x00000000, bhvBSMMenuTitle), // Title
	OBJECT(MODEL_NONE,   			  0,    0,   0, 0, 0,  0, 0x00000000, bhvBSMMenuButtonManager), // Button Manager

	OBJECT(MODEL_BSM_MENU_BUTTON, -1040, 1490, 540, 0, 0,  0, 0x00000000, bhvBSMMenuButtonOrStage), // Stats
	OBJECT(MODEL_BSM_MENU_BUTTON, -1040, 1170, 540, 0, 0,  0, 0x00010000, bhvBSMMenuButtonOrStage), // Credits

	OBJECT(MODEL_BSM_MENU_STAGE,      0, 1810, 540, 0, 0,  0, 0x00000000, bhvBSMMenuButtonOrStage), // Course 1
	OBJECT(MODEL_BSM_MENU_STAGE,      0, 1330, 540, 0, 0,  0, 0x00010000, bhvBSMMenuButtonOrStage), // Course 2
	OBJECT(MODEL_BSM_MENU_STAGE,      0,  850, 540, 0, 0,  0, 0x00020000, bhvBSMMenuButtonOrStage), // Course 3
	OBJECT(MODEL_BSM_MENU_STAGE,      0,  370, 540, 0, 0,  0, 0x00030000, bhvBSMMenuButtonOrStage), // Course 4
	OBJECT(MODEL_BSM_MENU_STAGE,    980, 1810, 540, 0, 0,  0, 0x00040000, bhvBSMMenuButtonOrStage), // Course 5
	OBJECT(MODEL_BSM_MENU_STAGE,    980, 1330, 540, 0, 0,  0, 0x00050000, bhvBSMMenuButtonOrStage), // Course 6
	OBJECT(MODEL_BSM_MENU_STAGE,    980,  850, 540, 0, 0,  0, 0x00060000, bhvBSMMenuButtonOrStage), // Course 7
	OBJECT(MODEL_BSM_MENU_STAGE,    980,  370, 540, 0, 0,  0, 0x00070000, bhvBSMMenuButtonOrStage), // Course 8
	OBJECT(MODEL_BSM_MENU_STAGE,   -980,  370, 540, 0, 0,  0, 0x00080000, bhvBSMMenuButtonOrStage), // Course 9

	// Rank:     x:  340, y: 60 (Relative to button)
	// CS Token: x: -340, y: 60 (Relative to button)

	RETURN(),
};

const LevelScript level_cgds_menu_select[] = {
    INIT_LEVEL(),
    LOAD_BEHAVIOR_DATA(),
	LOAD_YAY0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 

	ALLOC_LEVEL_POOL(),
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_BUTTON, custom_menu_button_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_STAGE, custom_menu_stage_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_LOCK, custom_menu_lock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_TCSLOCK, custom_menu_tcslock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_RANK, custom_menu_rank_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_TCSTOKEN, custom_menu_tcstoken_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_TITLE, custom_menu_title_geo), 

	AREA(1, castle_grounds_area_1_custom_static),
		JUMP_LINK(cgds_area1_jump),
	END_AREA(),
	FREE_LEVEL_POOL(),

    LOAD_AREA(/*area*/ 1),
	SET_MENU_MUSIC_WITH_REVERB(SEQ_CUSTOM_LEVEL_SELECT, 3, 3),

    CALL(/*arg*/ 0, /*func*/ load_mario_area),

	SET_ORTHO_CAM(TRUE),

    CALL(/*arg*/ 0, /*func*/ init_image_screen_press_button),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 16, /*color*/ 0x00, 0x00, 0x00),
    JUMP_LINK_PUSH_ARG(75),
		UPDATE_OBJECTS(),
    	CALL(/*arg*/ 0, /*func*/ scroll_textures),
        SLEEP(/*frames*/ 1),
    JUMP_N_TIMES(),
    
	// To compensate for the early sleep below
	UPDATE_OBJECTS(),
    CALL(/*arg*/ 0, /*func*/ scroll_textures),

    LOOP_BEGIN(),
		// This sleep comes early because of the way 'image_screen_press_button' is written.
		// 'image_screen_cannot_press_button' needs to be called on the same frame if the first returns TRUE, or else the button flickers.
        SLEEP(/*frames*/ 1),
		UPDATE_OBJECTS(),
    	CALL(/*arg*/ 0, /*func*/ scroll_textures),
    	CALL(/*arg*/ -1, /*func*/ image_screen_press_button),
    LOOP_UNTIL(/*op*/ OP_EQ, /*arg*/ TRUE),

	// PLAY_SOUND_EFFECT(SOUND_MENU_CUSTOM_MENU_SOUND),

	// To compensate for that early sleep above
    CALL(/*arg*/ -1, /*func*/ image_screen_cannot_press_button),
    SLEEP(/*frames*/ 1),

    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0x00, 0x00, 0x00),
    JUMP_LINK_PUSH_ARG(16),
		UPDATE_OBJECTS(),
    	CALL(/*arg*/ 0, /*func*/ scroll_textures),
    	CALL(/*arg*/ -1, /*func*/ image_screen_cannot_press_button),
        SLEEP(/*frames*/ 1),
    JUMP_N_TIMES(),

    UNLOAD_AREA(/*area*/ 1),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 2),
    EXIT_AND_EXECUTE_WITH_CODE(/*seg*/ SEGMENT_MENU_INTRO, _introSegmentRomStart, _introSegmentRomEnd, level_intro_mario_head_regular, _introSegmentBssStart, _introSegmentBssEnd),
};
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_BUTTON, custom_menu_button_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_STAGE, custom_menu_stage_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_LOCK, custom_menu_lock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_TCSLOCK, custom_menu_tcslock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_RANK, custom_menu_rank_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_TCSTOKEN, custom_menu_tcstoken_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_TITLE, custom_menu_title_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(0x0A, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 0, 1200, 0, -180, 0, 0x000A0000, bhvAirborneDeathWarp),
		MARIO_POS(0x01, -180, 0, 0, 1200),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		JUMP_LINK(cgds_area1_jump),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 0, 0, 1200),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
