#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"
#include "audio/external.h"

#include "game/area.h"
#include "game/level_update.h"
#include "game/texscroll.h"
#include "menu/title_screen.h"

#include "levels/scripts.h"
#include "levels/menu/header.h"
#include "levels/castle_courtyard/header.h"
#include "levels/castle_grounds/header.h"

#include "actors/common0.h"
#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/intro/header.h"
#include "farcall.h"

#include "config.h"
#include "game/print.h"

#include "game/object_list_processor.h"

const LevelScript level_scam_warning_screen[] = {
    INIT_LEVEL(),
    SLEEP(/*frames*/ 15),
    LOAD_GODDARD(),
    LOAD_BEHAVIOR_DATA(),
    LOAD_YAY0(          /*seg*/ SEGMENT_COMMON1_YAY0, _common1_yay0SegmentRomStart, _common1_yay0SegmentRomEnd),
    LOAD_YAY0(          /*seg*/ SEGMENT_GROUP0_YAY0,   _group0_yay0SegmentRomStart,  _group0_yay0SegmentRomEnd), // group0 load needed for scrolling textures!
    LOAD_RAW_WITH_CODE( /*seg*/ SEGMENT_COMMON1_GEO,  _common1_geoSegmentRomStart,  _common1_geoSegmentRomEnd, _common1_geoSegmentBssStart, _common1_geoSegmentBssEnd),
    LOAD_RAW_WITH_CODE( /*seg*/ SEGMENT_GROUP0_GEO,     _group0_geoSegmentRomStart,   _group0_geoSegmentRomEnd,  _group0_geoSegmentBssStart,  _group0_geoSegmentBssEnd),
    LOAD_YAY0(/*seg*/ 0x07, _intro_segment_7SegmentRomStart, _intro_segment_7SegmentRomEnd),

    // Load Scam Warning Screen
    ALLOC_LEVEL_POOL(),
    AREA(/*index*/ 1, intro_scam_screen),
    END_AREA(),
    FREE_LEVEL_POOL(),

    // Start animation
    LOAD_AREA(/*area*/ 1),

    CALL(/*arg*/ 0, /*func*/ init_image_screen_press_button),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 16, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 105),
    CALL_LOOP(/*arg*/ -1, /*func*/ image_screen_press_button),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0x00, 0x00, 0x00),
    CALL_LOOP(/*arg*/ 16, /*func*/ image_screen_cannot_press_button),
    UNLOAD_AREA(/*area*/ 1),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 20),

    // NOTE: Remember to change ALL OF THESE if changing scripts/segments
    EXIT_AND_EXECUTE_WITH_CODE(/*seg*/ SEGMENT_LEVEL_SCRIPT, _castle_courtyardSegmentRomStart, _castle_courtyardSegmentRomEnd, level_ccy_title_screen, _castle_courtyardSegmentBssStart, _castle_courtyardSegmentBssEnd),
};

const LevelScript level_intro_retry_menu_yes[] = {
    CALL(/*arg*/ 1, /*func*/ bsm_menu_selection_made),
	EXIT_AND_EXECUTE(/*seg*/ SEGMENT_GLOBAL_LEVEL_SCRIPT, _scriptsSegmentRomStart, _scriptsSegmentRomEnd, level_main_scripts_entry),
};

const LevelScript level_intro_retry_menu[] = {
    INIT_LEVEL(),
    LOAD_GODDARD(),
    LOAD_BEHAVIOR_DATA(),
    LOAD_YAY0(          /*seg*/ SEGMENT_COMMON1_YAY0, _common1_yay0SegmentRomStart, _common1_yay0SegmentRomEnd),
    LOAD_YAY0(          /*seg*/ SEGMENT_GROUP0_YAY0,   _group0_yay0SegmentRomStart,  _group0_yay0SegmentRomEnd), // group0 load needed for scrolling textures!
    LOAD_RAW_WITH_CODE( /*seg*/ SEGMENT_COMMON1_GEO,  _common1_geoSegmentRomStart,  _common1_geoSegmentRomEnd, _common1_geoSegmentBssStart, _common1_geoSegmentBssEnd),
    LOAD_RAW_WITH_CODE( /*seg*/ SEGMENT_GROUP0_GEO,     _group0_geoSegmentRomStart,   _group0_geoSegmentRomEnd,  _group0_geoSegmentBssStart,  _group0_geoSegmentBssEnd),
	LOAD_YAY0(0x07, _intro_segment_7SegmentRomStart, _intro_segment_7SegmentRomEnd),

    // Load Retry Menu
    ALLOC_LEVEL_POOL(),
	LOAD_MODEL_FROM_GEO(MODEL_BSM_MENU_RANK, custom_menu_rank_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_RETRY_MENU_RETRY, custom_retry_button_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_RETRY_MENU_QUIT, custom_quit_button_geo), 
    
    CALL(/*arg*/ 0, /*func*/ retry_menu_state),
    AREA(/*index*/ 1, intro_retry_menu),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ 0, 1200, 0, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBSMRetryMenu),
        SET_BACKGROUND_MUSIC_WITH_REVERB(0, SEQ_SOUND_PLAYER, BRPRESET_BSM_LEVEL_SELECT, BRPRESET_BSM_LEVEL_SELECT),
        SET_ECHO(0x00, 0x00),
    END_AREA(),
    FREE_LEVEL_POOL(),

	SET_ORTHO_CAM(TRUE),

    CALL(/*arg*/ 0, /*func*/ retry_menu_state),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 1, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 8),

    // Start animation
    LOAD_AREA(/*area*/ 1),
    CALL(/*arg*/ 0, /*func*/ load_mario_area),
    SET_MENU_MUSIC_WITH_REVERB(SEQ_SOUND_PLAYER, BRPRESET_BSM_LEVEL_SELECT, BRPRESET_BSM_LEVEL_SELECT),
	STOP_MUSIC_PLAYERS(0, (1 << SEQ_PLAYER_LEVEL)), // Needed to actually reinit audio when restarting level

    PLAY_SOUND_EFFECT(SOUND_MENU_MESSAGE_DISAPPEAR),

    LOOP_BEGIN(),
        UPDATE_OBJECTS(),
    	SCROLL_TEXTURES(),
        SLEEP(/*frames*/ 1),
        CALL(/*arg*/ 1, /*func*/ retry_menu_state),
    LOOP_UNTIL(/*op*/ OP_NEQ, /*arg*/ 0),

    JUMP_LINK_PUSH_ARG(8),
        UPDATE_OBJECTS(),
    	SCROLL_TEXTURES(),
        SLEEP(/*frames*/ 1),
    JUMP_N_TIMES(),

    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 12, /*color*/ 0x00, 0x00, 0x00),

    JUMP_LINK_PUSH_ARG(12),
        UPDATE_OBJECTS(),
    	SCROLL_TEXTURES(),
        SLEEP(/*frames*/ 1),
    JUMP_N_TIMES(),

    UNLOAD_AREA(/*area*/ 1),
    CLEAR_LEVEL(),

    SLEEP(/*frames*/ 2),
    CALL(/*arg*/ 2, /*func*/ retry_menu_state), // TODO: dialog prompt return
    JUMP_IF(/*op*/ OP_EQ, /*arg*/ 0,  level_intro_retry_menu_yes), // Jump if first result is selected (Retry)

    // Otherwise exit to menu select
    SLEEP(/*frames*/ 12),
    EXIT_AND_EXECUTE_WITH_CODE(/*seg*/ SEGMENT_LEVEL_SCRIPT, _castle_groundsSegmentRomStart, _castle_groundsSegmentRomEnd, level_cgds_menu_select, _castle_groundsSegmentBssStart, _castle_groundsSegmentBssEnd),
};

const LevelScript level_intro_elise_message[] = {
    INIT_LEVEL(),
    LOAD_GODDARD(),
    LOAD_BEHAVIOR_DATA(),
    LOAD_YAY0(          /*seg*/ SEGMENT_COMMON1_YAY0, _common1_yay0SegmentRomStart, _common1_yay0SegmentRomEnd),
    LOAD_YAY0(          /*seg*/ SEGMENT_GROUP0_YAY0,   _group0_yay0SegmentRomStart,  _group0_yay0SegmentRomEnd), // group0 load needed for scrolling textures!
    LOAD_RAW_WITH_CODE( /*seg*/ SEGMENT_COMMON1_GEO,  _common1_geoSegmentRomStart,  _common1_geoSegmentRomEnd, _common1_geoSegmentBssStart, _common1_geoSegmentBssEnd),
    LOAD_RAW_WITH_CODE( /*seg*/ SEGMENT_GROUP0_GEO,     _group0_geoSegmentRomStart,   _group0_geoSegmentRomEnd,  _group0_geoSegmentBssStart,  _group0_geoSegmentBssEnd),
    LOAD_YAY0(/*seg*/ 0x07, _intro_segment_7SegmentRomStart, _intro_segment_7SegmentRomEnd),

    // Load Scam Warning Screen
    ALLOC_LEVEL_POOL(),
    AREA(/*index*/ 1, intro_elise_message),
        SET_BACKGROUND_MUSIC_WITH_REVERB(0, SEQ_CUSTOM_ELISE_UNLOCK_JINGLE, BRPRESET_BSM_ELISE_UNLOCK_JINGLE, BRPRESET_BSM_ELISE_UNLOCK_JINGLE),
        SET_ECHO(0x1C, 0x1C),
    END_AREA(),
    FREE_LEVEL_POOL(),

	SET_ORTHO_CAM(TRUE),

    // Start animation
    LOAD_AREA(/*area*/ 1),
    CALL(/*arg*/ 0, /*func*/ load_mario_area),
    SET_MENU_MUSIC_WITH_REVERB(SEQ_CUSTOM_ELISE_UNLOCK_JINGLE, BRPRESET_BSM_ELISE_UNLOCK_JINGLE, BRPRESET_BSM_ELISE_UNLOCK_JINGLE),

    CALL(/*arg*/ 0, /*func*/ init_image_screen_press_button),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 10, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 25),

    PLAY_SOUND_EFFECT(SOUND_MARIO_HERE_WE_GO | ELISE_INDEX_FLAGS), // Let's go!
    SLEEP(/*frames*/ 40),

    CALL_LOOP(/*arg*/ -1, /*func*/ image_screen_press_button),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 12, /*color*/ 0x00, 0x00, 0x00),
    CALL_LOOP(/*arg*/ 12, /*func*/ image_screen_cannot_press_button),
    UNLOAD_AREA(/*area*/ 1),
    CLEAR_LEVEL(),

	STOP_MUSIC_PLAYERS(180, (1 << SEQ_PLAYER_LEVEL)), // Just in case, probably not needed here
    SLEEP(/*frames*/ 12),
	EXIT_AND_EXECUTE(/*seg*/ SEGMENT_GLOBAL_LEVEL_SCRIPT, _scriptsSegmentRomStart, _scriptsSegmentRomEnd, goto_bsm_level_select),
};

const LevelScript level_intro_gold_mario_message[] = {
    INIT_LEVEL(),
    LOAD_GODDARD(),
    LOAD_BEHAVIOR_DATA(),
    LOAD_YAY0(          /*seg*/ SEGMENT_COMMON1_YAY0, _common1_yay0SegmentRomStart, _common1_yay0SegmentRomEnd),
    LOAD_YAY0(          /*seg*/ SEGMENT_GROUP0_YAY0,   _group0_yay0SegmentRomStart,  _group0_yay0SegmentRomEnd), // group0 load needed for scrolling textures!
    LOAD_RAW_WITH_CODE( /*seg*/ SEGMENT_COMMON1_GEO,  _common1_geoSegmentRomStart,  _common1_geoSegmentRomEnd, _common1_geoSegmentBssStart, _common1_geoSegmentBssEnd),
    LOAD_RAW_WITH_CODE( /*seg*/ SEGMENT_GROUP0_GEO,     _group0_geoSegmentRomStart,   _group0_geoSegmentRomEnd,  _group0_geoSegmentBssStart,  _group0_geoSegmentBssEnd),
    LOAD_YAY0(/*seg*/ 0x07, _intro_segment_7SegmentRomStart, _intro_segment_7SegmentRomEnd),

    // Load Scam Warning Screen
    ALLOC_LEVEL_POOL(),
    AREA(/*index*/ 1, intro_gold_mario_message),
        SET_BACKGROUND_MUSIC_WITH_REVERB(0, SEQ_CUSTOM_ELISE_UNLOCK_JINGLE, BRPRESET_BSM_ELISE_UNLOCK_JINGLE, BRPRESET_BSM_ELISE_UNLOCK_JINGLE),
        SET_ECHO(0x1C, 0x1C),
    END_AREA(),
    FREE_LEVEL_POOL(),

	SET_ORTHO_CAM(TRUE),

    // Start animation
    LOAD_AREA(/*area*/ 1),
    CALL(/*arg*/ 0, /*func*/ load_mario_area),
    SET_MENU_MUSIC_WITH_REVERB(SEQ_CUSTOM_ELISE_UNLOCK_JINGLE, BRPRESET_BSM_ELISE_UNLOCK_JINGLE, BRPRESET_BSM_ELISE_UNLOCK_JINGLE),

    CALL(/*arg*/ 0, /*func*/ init_image_screen_press_button),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 10, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 25),

    PLAY_SOUND_EFFECT(SOUND_NARRATION_BSM_REDS_0), // You did it!
    SLEEP(/*frames*/ 40),

    CALL_LOOP(/*arg*/ -1, /*func*/ image_screen_press_button),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 12, /*color*/ 0x00, 0x00, 0x00),
    CALL_LOOP(/*arg*/ 12, /*func*/ image_screen_cannot_press_button),
    UNLOAD_AREA(/*area*/ 1),
    CLEAR_LEVEL(),

	STOP_MUSIC_PLAYERS(180, (1 << SEQ_PLAYER_LEVEL)), // Just in case, probably not needed here
    SLEEP(/*frames*/ 12),
	EXIT_AND_EXECUTE(/*seg*/ SEGMENT_GLOBAL_LEVEL_SCRIPT, _scriptsSegmentRomStart, _scriptsSegmentRomEnd, goto_bsm_level_select),
};

const LevelScript level_intro_wing_mario_message[] = {
    INIT_LEVEL(),
    LOAD_GODDARD(),
    LOAD_BEHAVIOR_DATA(),
    LOAD_YAY0(          /*seg*/ SEGMENT_COMMON1_YAY0, _common1_yay0SegmentRomStart, _common1_yay0SegmentRomEnd),
    LOAD_YAY0(          /*seg*/ SEGMENT_GROUP0_YAY0,   _group0_yay0SegmentRomStart,  _group0_yay0SegmentRomEnd), // group0 load needed for scrolling textures!
    LOAD_RAW_WITH_CODE( /*seg*/ SEGMENT_COMMON1_GEO,  _common1_geoSegmentRomStart,  _common1_geoSegmentRomEnd, _common1_geoSegmentBssStart, _common1_geoSegmentBssEnd),
    LOAD_RAW_WITH_CODE( /*seg*/ SEGMENT_GROUP0_GEO,     _group0_geoSegmentRomStart,   _group0_geoSegmentRomEnd,  _group0_geoSegmentBssStart,  _group0_geoSegmentBssEnd),
    LOAD_YAY0(/*seg*/ 0x07, _intro_segment_7SegmentRomStart, _intro_segment_7SegmentRomEnd),

    // Load Scam Warning Screen
    ALLOC_LEVEL_POOL(),
    AREA(/*index*/ 1, intro_wing_mario_message),
        SET_BACKGROUND_MUSIC_WITH_REVERB(0, SEQ_CUSTOM_ELISE_UNLOCK_JINGLE, BRPRESET_BSM_ELISE_UNLOCK_JINGLE, BRPRESET_BSM_ELISE_UNLOCK_JINGLE),
        SET_ECHO(0x1C, 0x1C),
    END_AREA(),
    FREE_LEVEL_POOL(),

	SET_ORTHO_CAM(TRUE),

    // Start animation
    LOAD_AREA(/*area*/ 1),
    CALL(/*arg*/ 0, /*func*/ load_mario_area),
    SET_MENU_MUSIC_WITH_REVERB(SEQ_CUSTOM_ELISE_UNLOCK_JINGLE, BRPRESET_BSM_ELISE_UNLOCK_JINGLE, BRPRESET_BSM_ELISE_UNLOCK_JINGLE),

    CALL(/*arg*/ 0, /*func*/ init_image_screen_press_button),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 10, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 25),

    PLAY_SOUND_EFFECT(SOUND_NARRATION_BSM_RANK_G_0), // Congratulations!
    SLEEP(/*frames*/ 40),

    CALL_LOOP(/*arg*/ -1, /*func*/ image_screen_press_button),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 12, /*color*/ 0x00, 0x00, 0x00),
    CALL_LOOP(/*arg*/ 12, /*func*/ image_screen_cannot_press_button),
    UNLOAD_AREA(/*area*/ 1),
    CLEAR_LEVEL(),

	STOP_MUSIC_PLAYERS(180, (1 << SEQ_PLAYER_LEVEL)), // Just in case, probably not needed here
    SLEEP(/*frames*/ 12),
	EXIT_AND_EXECUTE(/*seg*/ SEGMENT_GLOBAL_LEVEL_SCRIPT, _scriptsSegmentRomStart, _scriptsSegmentRomEnd, goto_bsm_level_select),
};

const LevelScript level_intro_splash_screen[] = {
#ifdef SKIP_TITLE_SCREEN
    EXIT_AND_EXECUTE_WITH_CODE(/*seg*/ SEGMENT_MENU_INTRO, _introSegmentRomStart, _introSegmentRomEnd, level_intro_mario_head_regular, _introSegmentBssStart, _introSegmentBssEnd),
#endif
    INIT_LEVEL(),
    LOAD_GODDARD(),
    LOAD_BEHAVIOR_DATA(),
    LOAD_LEVEL_DATA(intro),
#if defined(FLOOMBAS) && defined(INTRO_FLOOMBAS)
    LOAD_COMMON0(),

    // Load "Super Mario 64" logo
    ALLOC_LEVEL_POOL(),
    LOAD_MODEL_FROM_GEO(MODEL_GOOMBA, goomba_geo),
    AREA(/*index*/ 1, intro_geo_splash_screen),
        OBJECT(/*model*/ MODEL_GOOMBA, /*pos*/ -570, -480, 1500, /*angle*/ 0,  50, 0, /*behParam*/ BP(0x18, 0x00, 0x10, 0x0B), /*beh*/ bhvFloombaStartup),
        OBJECT(/*model*/ MODEL_GOOMBA, /*pos*/  570, -480, 1500, /*angle*/ 0, -50, 0, /*behParam*/ BP(0x18, 0x00, 0x90, 0x0B), /*beh*/ bhvFloombaStartup),
    END_AREA(),
    FREE_LEVEL_POOL(),

    // Start animation
    LOAD_AREA(/*area*/ 1),

    SET_MENU_MUSIC(/*seq*/ SEQ_SOUND_PLAYER),
    CALL(/*arg*/ LVL_INTRO_PLAY_ITS_A_ME_MARIO, /*func*/ lvl_intro_update),
    CALL(/*arg*/ 0, /*func*/ load_mario_area),
    
    JUMP_LINK_PUSH_ARG(75),
        UPDATE_OBJECTS(),
        SLEEP(/*frames*/ 1),
    JUMP_N_TIMES(),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0x00, 0x00, 0x00),
    JUMP_LINK_PUSH_ARG(16),
        UPDATE_OBJECTS(),
        SLEEP(/*frames*/ 1),
    JUMP_N_TIMES(),
#else
    // Load "Super Mario 64" logo
    ALLOC_LEVEL_POOL(),
    AREA(/*index*/ 1, intro_geo_splash_screen),
    END_AREA(),
    FREE_LEVEL_POOL(),

    // Start animation
    LOAD_AREA(/*area*/ 1),

    SET_MENU_MUSIC(/*seq*/ SEQ_SOUND_PLAYER),
    CALL(/*arg*/ LVL_INTRO_PLAY_ITS_A_ME_MARIO, /*func*/ lvl_intro_update),
    SLEEP(/*frames*/ 75),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 16),
#endif
    UNLOAD_AREA(/*area*/ 1),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 2),
    EXIT_AND_EXECUTE_WITH_CODE(/*seg*/ SEGMENT_MENU_INTRO, _introSegmentRomStart, _introSegmentRomEnd, level_intro_mario_head_regular, _introSegmentBssStart, _introSegmentBssEnd),
};

const LevelScript level_intro_mario_head_regular[] = {
    INIT_LEVEL(),
    BLACKOUT(/*active*/ TRUE),
    LOAD_GODDARD(),
#ifdef KEEP_MARIO_HEAD
    LOAD_MARIO_HEAD(/*loadHeadID*/ REGULAR_FACE),
    LOAD_BEHAVIOR_DATA(),
    LOAD_TITLE_SCREEN_BG(),

    ALLOC_LEVEL_POOL(),
    AREA(/*index*/ 1, intro_geo_mario_head_regular),
    END_AREA(),
    FREE_LEVEL_POOL(),

    SLEEP(/*frames*/ 2),
    BLACKOUT(/*active*/ FALSE),
    LOAD_AREA(/*area*/ 1),
    SET_MENU_MUSIC(/*seq*/ SEQ_MENU_TITLE_SCREEN),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_STAR, /*time*/ 20, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 20),
#else
    PUSH_POOL(),
    BLACKOUT(/*active*/ FALSE),
#endif
    CALL_LOOP(/*arg*/ LVL_INTRO_REGULAR, /*func*/ lvl_intro_update),
    JUMP_IF(/*op*/ OP_EQ, /*arg*/ LEVEL_FILE_SELECT,  script_intro_file_select),
    JUMP_IF(/*op*/ OP_EQ, /*arg*/ LEVEL_LEVEL_SELECT, script_intro_level_select),
    JUMP(script_intro_main_level_entry),
};

const LevelScript level_intro_mario_head_dizzy[] = {
    INIT_LEVEL(),
    BLACKOUT(/*active*/ TRUE),
    LOAD_GODDARD(),
#ifdef KEEP_MARIO_HEAD
    LOAD_MARIO_HEAD(/*loadHeadID*/ DIZZY_FACE),
#endif
    LOAD_BEHAVIOR_DATA(),
    LOAD_TITLE_SCREEN_BG(),
    ALLOC_LEVEL_POOL(),

    AREA(/*index*/ 1, intro_geo_mario_head_dizzy),
    END_AREA(),

    FREE_LEVEL_POOL(),
    SLEEP(/*frames*/ 2),
    BLACKOUT(/*active*/ FALSE),
    LOAD_AREA(/*area*/ 1),
    SET_MENU_MUSIC(/*seq*/ SEQ_MENU_GAME_OVER),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_STAR, /*time*/ 20, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 20),
    CALL_LOOP(/*arg*/ LVL_INTRO_GAME_OVER, /*func*/ lvl_intro_update),
    JUMP_IF(/*op*/ OP_EQ, /*arg*/ LEVEL_FILE_SELECT,  script_intro_file_select),
    JUMP_IF(/*op*/ OP_EQ, /*arg*/ LEVEL_LEVEL_SELECT, script_intro_level_select),
    JUMP(script_intro_main_level_entry),
};

const LevelScript level_intro_entry_level_select[] = {
    INIT_LEVEL(),
    LOAD_BEHAVIOR_DATA(),
    LOAD_TITLE_SCREEN_BG(),
    LOAD_YAY0(/*seg*/ SEGMENT_LEVEL_DATA, _debug_level_select_yay0SegmentRomStart, _debug_level_select_yay0SegmentRomEnd),
    FIXED_LOAD(/*loadAddr*/ _goddardSegmentStart, /*romStart*/ _goddardSegmentRomStart, /*romEnd*/ _goddardSegmentRomEnd),
    ALLOC_LEVEL_POOL(),

    AREA(/*index*/ 1, intro_geo_debug_level_select),
    END_AREA(),

    FREE_LEVEL_POOL(),
    LOAD_AREA(/*area*/ 1),
    SET_MENU_MUSIC(/*seq*/ SEQ_MENU_TITLE_SCREEN),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_FROM_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    CALL_LOOP(/*arg*/ LVL_INTRO_LEVEL_SELECT, /*func*/ lvl_intro_update),
    JUMP_IF(/*op*/ OP_EQ, /*arg*/ LEVEL_RESTART_GAME, script_intro_splash_screen),
    JUMP(script_intro_main_level_entry_stop_music),
};

// These should be static, but C doesn't allow non-sized forward declarations of static arrays

const LevelScript script_intro_file_select[] = {
    STOP_MUSIC(/*fadeOutTime*/ 0x00BE),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 2),
    SET_REG(/*value*/ START_LEVEL),
    EXIT_AND_EXECUTE(/*seg*/ SEGMENT_MENU_INTRO, _menuSegmentRomStart, _menuSegmentRomEnd, level_main_menu_entry_file_select),
};

const LevelScript script_intro_level_select[] = {
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 2),
    EXIT_AND_EXECUTE_WITH_CODE(/*seg*/ SEGMENT_MENU_INTRO, _introSegmentRomStart, _introSegmentRomEnd, level_intro_entry_level_select, _introSegmentBssStart, _introSegmentBssEnd),
};

const LevelScript script_intro_main_level_entry_stop_music[] = {
    STOP_MUSIC(/*fadeOutTime*/ 0x00BE),
    JUMP(script_intro_main_level_entry),
};

const LevelScript script_intro_main_level_entry[] = {
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0xFF, 0xFF, 0xFF),
    SLEEP(/*frames*/ 16),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 2),
    EXIT_AND_EXECUTE(/*seg*/ SEGMENT_GLOBAL_LEVEL_SCRIPT, _scriptsSegmentRomStart, _scriptsSegmentRomEnd, level_main_scripts_entry),
};

const LevelScript script_intro_splash_screen[] = {
    STOP_MUSIC(/*fadeOutTime*/ 0x00BE),
    TRANSITION(/*transType*/ WARP_TRANSITION_FADE_INTO_COLOR, /*time*/ 16, /*color*/ 0x00, 0x00, 0x00),
    SLEEP(/*frames*/ 16),
    CLEAR_LEVEL(),
    SLEEP(/*frames*/ 2),
    EXIT_AND_EXECUTE_WITH_CODE(/*seg*/ SEGMENT_MENU_INTRO, _introSegmentRomStart, _introSegmentRomEnd, level_intro_splash_screen, _introSegmentBssStart, _introSegmentBssEnd),
};
