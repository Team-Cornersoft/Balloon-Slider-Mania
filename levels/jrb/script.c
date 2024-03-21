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
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _clouds_skybox_yay0SegmentRomStart, _clouds_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_LEFT_HALF_PART, jrb_geo_000978), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_LEFT_PART, jrb_geo_0009B0), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_RIGHT_HALF_PART, jrb_geo_0009E8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_RIGHT_PART, jrb_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP, jrb_geo_000990), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP_BACK, jrb_geo_0009C8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_ROCK, jrb_geo_000930), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SLIDING_BOX, jrb_geo_000960), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR, jrb_geo_000900), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR_BASE, jrb_geo_000918), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FLOATING_PLATFORM, jrb_geo_000948), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x02, -7000, 10000, -5000),
		MARIO_POS(0x01, -180, -14345, -537, 23442),
		OBJECT(MODEL_BSM_KEY_BALLOON, 0, 0, -50000, 0, 0, 0, 0x00000000, bhvKeyBalloon),
		OBJECT(MODEL_BSM_KEY_GATE, 0, 0, -50000, 0, -52, 0, 0x00020000, bhvKeyGate),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, 0, 0, 0x00050000, bhvPointBalloon),
		OBJECT(MODEL_NONE, -14345, -537, 23442, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -14345, -537, 23442, 0, -180, 0, 0x00F00000, bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, -14345, -537, 23442, 0, -180, 0, 0x00F10000, bhvDeathWarp),
		TERRAIN(jrb_area_1_collision),
		ROOMS(jrb_area_1_collision_rooms),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_COURSE2_WATERWAYS),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, jrb_area_2),
		WARP_NODE(0x0A, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x03, -77600, 19300, 0),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, 90, 0, 0x00040000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, 1, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, 1, 0, 0x00030000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, 0, 0, 0x00000000, bhvPointBalloon),
		TERRAIN(jrb_area_2_collision),
		ROOMS(jrb_area_2_collision_rooms),
		MACRO_OBJECTS(jrb_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SNOW),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, jrb_area_3),
		WARP_NODE(0x0A, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_WF, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x04, 0, 14000, 0),
		WARP_NODE(0x0B, LEVEL_WF, 0x03, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, -89, 0, 0x00040000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, -89, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, -89, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, -89, 0, 0x00030000, bhvPointBalloon),
		OBJECT(MODEL_NONE, 0, 0, -50000, 0, -25, 0, 0x000B0000, bhvBSMCelebrationWarp),
		OBJECT(MODEL_BSM_TCS_TOKEN, 0, 0, -50000, 0, 90, 0, 0x00050000, bhvTCSToken),
		TERRAIN(jrb_area_3_collision),
		ROOMS(jrb_area_3_collision_rooms),
		MACRO_OBJECTS(jrb_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SNOW),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, -14345, -537, 23442),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
