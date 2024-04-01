#include <ultra64.h>
#include "sm64.h"
#include "audio/external.h"
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
#include "levels/castle_grounds/header.h"
#include "game/area.h"
#include "game/texscroll.h"
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/castle_courtyard/header.h"

/* Fast64 begin persistent block [scripts] */
static const LevelScript ccy_area1_jump[] = {
	OBJECT(MODEL_BSM_TITLE_SCREEN_BALLOON, -1038, 1812, -326, 0, 0, 0, 0x00000000, bhvTitleScreenBalloon), // B
	OBJECT(MODEL_BSM_TITLE_SCREEN_BALLOON,  -749, 1664, -250, 0, 0, 0, 0x00010000, bhvTitleScreenBalloon), // A
	OBJECT(MODEL_BSM_TITLE_SCREEN_BALLOON,  -531, 1886, -443, 0, 0, 0, 0x00020000, bhvTitleScreenBalloon), // L
	OBJECT(MODEL_BSM_TITLE_SCREEN_BALLOON,  -275, 1738, -339, 0, 0, 0, 0x00030000, bhvTitleScreenBalloon), // L
	OBJECT(MODEL_BSM_TITLE_SCREEN_BALLOON,   -63, 1812, -549, 0, 0, 0, 0x00040000, bhvTitleScreenBalloon), // O
	OBJECT(MODEL_BSM_TITLE_SCREEN_BALLOON,   183, 1683, -742, 0, 0, 0, 0x00050000, bhvTitleScreenBalloon), // O
	OBJECT(MODEL_BSM_TITLE_SCREEN_BALLOON,   455, 1823, -605, 0, 0, 0, 0x00060000, bhvTitleScreenBalloon), // N
	RETURN(),
};

const LevelScript level_ccy_title_screen[] = {
    INIT_LEVEL(),
    LOAD_BEHAVIOR_DATA(),
    LOAD_YAY0(          /*seg*/ SEGMENT_COMMON1_YAY0, _common1_yay0SegmentRomStart, _common1_yay0SegmentRomEnd),
    LOAD_YAY0(          /*seg*/ SEGMENT_GROUP0_YAY0,   _group0_yay0SegmentRomStart,  _group0_yay0SegmentRomEnd), // group0 load needed for scrolling textures!
    LOAD_RAW_WITH_CODE( /*seg*/ SEGMENT_COMMON1_GEO,  _common1_geoSegmentRomStart,  _common1_geoSegmentRomEnd, _common1_geoSegmentBssStart, _common1_geoSegmentBssEnd),
    LOAD_RAW_WITH_CODE( /*seg*/ SEGMENT_GROUP0_GEO,     _group0_geoSegmentRomStart,   _group0_geoSegmentRomEnd,  _group0_geoSegmentBssStart,  _group0_geoSegmentBssEnd),
	LOAD_YAY0(0x07, _castle_courtyard_segment_7SegmentRomStart, _castle_courtyard_segment_7SegmentRomEnd), 

	ALLOC_LEVEL_POOL(),
	LOAD_MODEL_FROM_GEO(MODEL_BSM_TITLE_SCREEN_BALLOON, title_screen_balloon_geo),

	AREA(1, castle_courtyard_area_1_custom_static),
		JUMP_LINK(ccy_area1_jump),
		SET_BACKGROUND_MUSIC_WITH_REVERB(0, SEQ_CUSTOM_TITLE_SCREEN, BRPRESET_BSM_LEVEL_SELECT, BRPRESET_BSM_LEVEL_SELECT),
		SET_ECHO(0x00, 0x00),
	END_AREA(),

	FREE_LEVEL_POOL(),

    LOAD_AREA(/*area*/ 1),
	SET_MENU_MUSIC_WITH_REVERB(SEQ_CUSTOM_TITLE_SCREEN, BRPRESET_BSM_LEVEL_SELECT, BRPRESET_BSM_LEVEL_SELECT),

    CALL(/*arg*/ 0, /*func*/ load_mario_area),

	SET_ORTHO_CAM(TRUE),

    CALL(/*arg*/ 0, /*func*/ init_image_screen_press_button),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 16, /*color*/ 0x00, 0x00, 0x00),
    JUMP_LINK_PUSH_ARG(10),
		UPDATE_OBJECTS(),
    	SCROLL_TEXTURES(),
        SLEEP(/*frames*/ 1),
    JUMP_N_TIMES(),

	PLAY_SOUND_EFFECT(SOUND_NARRATION_BSM_TITLE),

    JUMP_LINK_PUSH_ARG(65),
		UPDATE_OBJECTS(),
    	SCROLL_TEXTURES(),
        SLEEP(/*frames*/ 1),
    JUMP_N_TIMES(),
    
	// To compensate for the early sleep below
	UPDATE_OBJECTS(),
    SCROLL_TEXTURES(),

    LOOP_BEGIN(),
		// This sleep comes early because of the way 'image_screen_press_button' is written.
		// 'image_screen_cannot_press_button' needs to be called on the same frame if the first returns TRUE, or else the button flickers.
        SLEEP(/*frames*/ 1),
		UPDATE_OBJECTS(),
    	SCROLL_TEXTURES(),
    	CALL(/*arg*/ -1, /*func*/ image_screen_press_button),
    LOOP_UNTIL(/*op*/ OP_EQ, /*arg*/ TRUE),

	// PLAY_SOUND_EFFECT(SOUND_MENU_CUSTOM_MENU_SOUND),

	// To compensate for that early sleep above
    CALL(/*arg*/ -1, /*func*/ image_screen_cannot_press_button),
    SLEEP(/*frames*/ 1),

	STOP_MUSIC_PLAYERS(150, (1 << SEQ_PLAYER_LEVEL)),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0x00, 0x00, 0x00),
    JUMP_LINK_PUSH_ARG(16),
		UPDATE_OBJECTS(),
    	SCROLL_TEXTURES(),
    	CALL(/*arg*/ -1, /*func*/ image_screen_cannot_press_button),
        SLEEP(/*frames*/ 1),
    JUMP_N_TIMES(),

    UNLOAD_AREA(/*area*/ 1),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 2),
    EXIT_AND_EXECUTE_WITH_CODE(/*seg*/ SEGMENT_LEVEL_SCRIPT, _castle_groundsSegmentRomStart, _castle_groundsSegmentRomEnd, level_cgds_menu_select, _castle_groundsSegmentBssStart, _castle_groundsSegmentBssEnd),
};
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_courtyard_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_courtyard_segment_7SegmentRomStart, _castle_courtyard_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	LOAD_MODEL_FROM_GEO(MODEL_BSM_TITLE_SCREEN_BALLOON, title_screen_balloon_geo),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_courtyard_area_1),
		WARP_NODE(0x0A, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 0, 1200, 0, -180, 0, 0x000A0000, bhvAirborneDeathWarp),
		MARIO_POS(0x01, -180, 0, 0, 1200),
		TERRAIN(castle_courtyard_area_1_collision),
		MACRO_OBJECTS(castle_courtyard_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		JUMP_LINK(ccy_area1_jump),
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
