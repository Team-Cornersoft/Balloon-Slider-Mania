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
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x02, 0, 18000, 0),
		MARIO_POS(0x01, -180, -16700, 10394, 17100),
		OBJECT(MODEL_NONE, -16700, 10394, 17100, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -16700, 10394, 17100, 0, -180, 0, 0x00F00000, bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, -16700, 10394, 17100, 0, -180, 0, 0x00F10000, bhvDeathWarp),
		TERRAIN(bob_area_1_collision),
		ROOMS(bob_area_1_collision_rooms),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SNOW),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		SET_BACKGROUND_MUSIC_WITH_REVERB(0x00, SEQ_CUSTOM_COURSE1_SNOWY, BRPRESET_BSM_C1_GENERAL, BRPRESET_BSM_C1_GENERAL),
		SET_ECHO(0x02, 0x02),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bob_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x03, 1000, 15300, -44000),
		OBJECT(MODEL_NONE, -10458, 9889, 9711, 0, 35, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -10458, 9889, 9711, 0, 35, 0, 0x00F00000, bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, -10458, 9889, 9711, 0, 35, 0, 0x00F10000, bhvDeathWarp),
		TERRAIN(bob_area_2_collision),
		ROOMS(bob_area_2_collision_rooms),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SNOW),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		SET_BACKGROUND_MUSIC_WITH_REVERB(0x00, SEQ_CUSTOM_COURSE1_SNOWY, BRPRESET_BSM_C1_A2, BRPRESET_BSM_C1_A2),
		SET_ECHO(0x20, 0x20),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, bob_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x04, 0, 14000, 0),
		OBJECT(MODEL_NONE, -7500, 3621, -17300, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -7500, 3621, -17300, 0, -180, 0, 0x00F00000, bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, -7500, 3621, -17300, 0, -180, 0, 0x00F10000, bhvDeathWarp),
		TERRAIN(bob_area_3_collision),
		ROOMS(bob_area_3_collision_rooms),
		MACRO_OBJECTS(bob_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SNOW),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		SET_BACKGROUND_MUSIC_WITH_REVERB(0x00, SEQ_CUSTOM_COURSE1_SNOWY, BRPRESET_BSM_C1_GENERAL, BRPRESET_BSM_C1_GENERAL),
		SET_ECHO(0x02, 0x02),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, bob_area_4),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x00F00000, bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x00F10000, bhvDeathWarp),
		TERRAIN(bob_area_4_collision),
		ROOMS(bob_area_4_collision_rooms),
		MACRO_OBJECTS(bob_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SNOW),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		SET_BACKGROUND_MUSIC_WITH_REVERB(0x00, SEQ_CUSTOM_COURSE1_SNOWY, BRPRESET_BSM_C1_GENERAL, BRPRESET_BSM_C1_GENERAL),
		SET_ECHO(0x02, 0x02),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, -16700, 10394, 17100),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
