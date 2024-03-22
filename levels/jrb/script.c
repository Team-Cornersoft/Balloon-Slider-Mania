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
		WARP_NODE(0xC0, LEVEL_JRB, 0x01, 0xC1, WARP_NO_CHECKPOINT),
		WARP_NODE(0xC2, LEVEL_JRB, 0x02, 0xC0, WARP_NO_CHECKPOINT),
		WARP_NODE(0xC1, LEVEL_JRB, 0x01, 0xC1, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, -180, -14345, -537, 23442),
		OBJECT(MODEL_BSM_KEY_BALLOON, 0, 0, -50000, 0, 0, 0, 0x00000000, bhvKeyBalloon),
		OBJECT(MODEL_BSM_KEY_GATE, 0, 0, -50000, 0, -52, 0, 0x00020000, bhvKeyGate),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, 0, 0, 0x00050000, bhvPointBalloon),
		OBJECT(MODEL_BSM_TCS_TOKEN, 15339, -5387, 9131, 0, -70, 0, 0x00000000, bhvTCSToken),
		OBJECT(MODEL_NONE, -14345, -537, 23442, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -14345, -537, 23442, 0, -180, 0, 0x00F00000, bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, -14345, -537, 23442, 0, -180, 0, 0x00F10000, bhvDeathWarp),
		OBJECT(MODEL_NONE, 10991, -4599, 10000, 0, 90, 0, 0x00C10000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -1716, -6592, 9717, 0, 0, 0, 0xA0C00000, bhvWarp),
		OBJECT(MODEL_NONE, -7976, -11357, -23424, 0, 0, 0, 0xA0C20000, bhvWarp),
		TERRAIN(jrb_area_1_collision),
		ROOMS(jrb_area_1_collision_rooms),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_COURSE2_WATERWAYS),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, jrb_area_2),
		WARP_NODE(0x0A, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_JRB, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		WARP_NODE(0xC0, LEVEL_JRB, 0x02, 0xC0, WARP_NO_CHECKPOINT),
		WARP_NODE(0xC1, LEVEL_JRB, 0x02, 0xC2, WARP_NO_CHECKPOINT),
		WARP_NODE(0xC3, LEVEL_JRB, 0x02, 0xC4, WARP_NO_CHECKPOINT),
		WARP_NODE(0xC5, LEVEL_JRB, 0x03, 0xC0, WARP_NO_CHECKPOINT),
		WARP_NODE(0xC2, LEVEL_JRB, 0x02, 0xC2, WARP_NO_CHECKPOINT),
		WARP_NODE(0xC4, LEVEL_JRB, 0x02, 0xC4, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, 90, 0, 0x00040000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, 1, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, 1, 0, 0x00030000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_NONE, 13783, -9008, 10045, 0, -50, 0, 0x00C00000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -14696, -9050, -3175, 0, 129, 0, 0x00C20000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 9164, -8993, 2839, 0, 179, 0, 0x00C40000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 14167, -10386, -14752, 0, 0, 0, 0xA0C00000, bhvWarp),
		OBJECT(MODEL_NONE, -14239, -10733, 13511, 0, 0, 0, 0xA0C10000, bhvWarp),
		OBJECT(MODEL_NONE, -5003, -10741, 334, 0, 0, 0, 0xA0C30000, bhvWarp),
		OBJECT(MODEL_NONE, -8358, -10190, -14871, 0, 0, 0, 0xA0C30000, bhvWarp),
		OBJECT(MODEL_NONE, 6766, -10372, -15306, 0, 0, 0, 0xA0C50000, bhvWarp),
		TERRAIN(jrb_area_2_collision),
		ROOMS(jrb_area_2_collision_rooms),
		MACRO_OBJECTS(jrb_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_COURSE2_WATERWAYS),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, jrb_area_3),
		WARP_NODE(0x0A, LEVEL_JRB, 0x03, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_JRB, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x04, 0, 0, 0),
		WARP_NODE(0x0B, LEVEL_JRB, 0x03, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0xC0, LEVEL_JRB, 0x03, 0xC0, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, -89, 0, 0x00040000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, -89, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, -89, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, -89, 0, 0x00030000, bhvPointBalloon),
		OBJECT(MODEL_NONE, 0, 0, -50000, 0, -25, 0, 0x000B0000, bhvBSMCelebrationWarp),
		OBJECT(MODEL_NONE, -20726, 6338, -8443, 0, 90, 0, 0x00C00000, bhvInstantActiveWarp),
		OBJECT(MODEL_BSM_BOUNCY_SHROOM, -13768, 5485, -8537, 0, 0, 0, 0x00100000, bhvBouncyShroom),
		OBJECT(MODEL_BSM_BOUNCY_SHROOM, -10568, 3885, -10137, 0, 0, 0, 0x00100000, bhvBouncyShroom),
		OBJECT(MODEL_BSM_BOUNCY_SHROOM, -10568, 3885, -6937, 0, 0, 0, 0x00100000, bhvBouncyShroom),
		OBJECT(MODEL_BSM_BOUNCY_SHROOM, -7368, 2285, -11737, 0, 0, 0, 0x00100000, bhvBouncyShroom),
		OBJECT(MODEL_BSM_BOUNCY_SHROOM, -7368, 2285, -8537, 0, 0, 0, 0x00100000, bhvBouncyShroom),
		OBJECT(MODEL_BSM_BOUNCY_SHROOM, -4168, 685, -13337, 0, 0, 0, 0x00100000, bhvBouncyShroom),
		OBJECT(MODEL_BSM_BOUNCY_SHROOM, -4168, 685, -10137, 0, 0, 0, 0x00100000, bhvBouncyShroom),
		OBJECT(MODEL_BSM_BOUNCY_SHROOM, -4168, 685, -6937, 0, 0, 0, 0x00100000, bhvBouncyShroom),
		OBJECT(MODEL_BSM_BOUNCY_SHROOM, -968, -815, -11737, 0, 0, 0, 0x00100000, bhvBouncyShroom),
		OBJECT(MODEL_BSM_BOUNCY_SHROOM, -968, -815, -8537, 0, 0, 0, 0x00100000, bhvBouncyShroom),
		OBJECT(MODEL_BSM_BOUNCY_SHROOM, 2232, -2415, -10137, 0, 0, 0, 0x00100000, bhvBouncyShroom),
		OBJECT(MODEL_BSM_BOUNCY_SHROOM, 4432, -4015, -7937, 0, 0, 0, 0x00100000, bhvBouncyShroom),
		OBJECT(MODEL_BSM_BOUNCY_SHROOM, -4848, -7315, 12993, 0, 0, 0, 0xD0560000, bhvBouncyShroom),
		TERRAIN(jrb_area_3_collision),
		ROOMS(jrb_area_3_collision_rooms),
		MACRO_OBJECTS(jrb_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_COURSE2_WATERWAYS),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, jrb_area_4),
		WARP_NODE(0x0A, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_JRB, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x03, 0, 0, 0),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, -89, 0, 0x00040000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, -89, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, -89, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 0, -50000, 0, -89, 0, 0x00030000, bhvPointBalloon),
		TERRAIN(jrb_area_4_collision),
		ROOMS(jrb_area_4_collision_rooms),
		MACRO_OBJECTS(jrb_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_COURSE2_WATERWAYS),
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
