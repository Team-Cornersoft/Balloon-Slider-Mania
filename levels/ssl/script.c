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
#include "levels/ssl/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ssl_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ssl_segment_7SegmentRomStart, _ssl_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _ssl_skybox_yay0SegmentRomStart, _ssl_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group5_yay0SegmentRomStart, _group5_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PALM_TREE, palm_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, ssl_geo_0005C0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, ssl_geo_0005D8), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PYRAMID_TOP, ssl_geo_000618), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_GRINDEL, ssl_geo_000734), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_SPINDEL, ssl_geo_000764), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_MOVING_PYRAMID_WALL, ssl_geo_000794), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PYRAMID_ELEVATOR, ssl_geo_0007AC), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_TOX_BOX, ssl_geo_000630), 
	LOAD_MODEL_FROM_GEO(MODEL_BSM_ROTATING_GLOBE, custom_portal_globe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ssl_area_1),
		WARP_NODE(0x0A, LEVEL_SSL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_SSL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_SSL, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCA, LEVEL_SSL, 0x02, 0xCA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCB, LEVEL_SSL, 0x04, 0xCA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCC, LEVEL_SSL, 0x05, 0xCA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xDA, LEVEL_SSL, 0x01, 0xDA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xDB, LEVEL_SSL, 0x01, 0xDB, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BSM_POINT_BALLOON, 18316, 8027, 3552, 0, -90, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -13284, 8744, -7918, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -13284, 9344, -842, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 21147, 6789, 7015, 0, 45, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 12026, 3677, -3952, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 7234, 3590, -87, 0, -180, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 13224, 5657, 3678, 0, 44, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 12505, 5657, 4373, 0, 44, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 12006, 4697, 252, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 10808, 3512, -6348, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 9628, 3512, -6348, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -13254, 10527, 13327, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 13004, 3817, -1960, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -13184, 9038, -4442, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -13284, 8583, -9818, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 7234, 3555, 713, 0, -180, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 10898, 2582, -10518, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 9552, 2582, -10518, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -13261, 10235, 9683, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 7216, 3113, 3655, 0, -180, 0, 0x00030000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 21616, 8567, 11352, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -12609, 9488, 858, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -12609, 8885, -6245, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -11386, 9699, 3300, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -11386, 9842, 4937, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -15183, 9842, 4937, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -15183, 9699, 3300, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 19816, 8571, 11382, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -12566, 10384, 11548, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -14026, 10097, 7970, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 21616, 6866, 8002, 0, 10, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 20241, 6704, 6552, 0, -100, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -13959, 9191, -2642, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -13284, 9977, 6480, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 19816, 8153, 5102, 0, 10, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 7234, 3625, -926, 0, -180, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 13187, 4697, 252, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 10834, 4697, 252, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 11985, 3512, -6348, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 8454, 3512, -6348, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -13959, 8885, -6245, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -12609, 9191, -2642, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -13959, 9488, 858, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -13967, 10385, 11558, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -12550, 10098, 7977, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 13943, 5657, 2983, 0, 44, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 11785, 5657, 5067, 0, 44, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 19841, 8350, 8118, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 16816, 6557, 6552, 0, -90, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 12094, 2662, -8928, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 8356, 2662, -8924, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 10825, 3723, -3251, 0, 45, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 11431, 3590, -5217, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 9012, 3590, -5217, 0, 0, 0, 0x00060000, bhvPointBalloon),
		MARIO_POS(0x01, -180, -13264, 12216, 24954),
		OBJECT(MODEL_BSM_ROTATING_GLOBE, -13284, 8521, -11861, 0, 0, 0, 0x00000000, bhvRotatingGlobe),
		OBJECT(MODEL_BSM_ROTATING_GLOBE, 10216, 2521, -13761, 0, 0, 0, 0x00000000, bhvRotatingGlobe),
		OBJECT(MODEL_BSM_ROTATING_GLOBE, 7216, 3171, 5536, 0, -180, 0, 0x00000000, bhvRotatingGlobe),
		OBJECT(MODEL_BSM_POINT_BALLOON, -13284, 10319, 4093, 0, 0, 0, 0x00050000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 10179, 3774, -2555, 0, 45, 0, 0x00050000, bhvPointBalloon),
		OBJECT(MODEL_NONE, -13264, 12216, 24954, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -13264, 12216, 24954, 0, -180, 0, 0x00F00000, bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, -13264, 12216, 24954, 0, -180, 0, 0x00F10000, bhvDeathWarp),
		OBJECT(MODEL_NONE, 20693, 8914, 17309, 0, -180, 0, 0x00DA0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -13284, 9121, -12061, 0, 0, 0, 0x40CA003C, bhvWarp),
		OBJECT(MODEL_NONE, 10216, 3121, -13961, 0, 0, 0, 0x40CB003C, bhvWarp),
		OBJECT(MODEL_NONE, 7216, 3771, 5736, 0, -180, 0, 0x40CB003C, bhvWarp),
		TERRAIN(ssl_area_1_collision),
		ROOMS(ssl_area_1_collision_rooms),
		MACRO_OBJECTS(ssl_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_COURSE8_CYBER),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		OBJECT(MODEL_BSM_POINT_BALLOON, 9015, 3720, -3250, 0, -90, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 7825, 3722, -2775, 0, -45, 0, 0x00000000, bhvPointBalloon),
		SET_BACKGROUND_MUSIC_WITH_REVERB(0x00, SEQ_CUSTOM_COURSE8_CYBER, BRPRESET_BSM_C4_GENERAL, BRPRESET_BSM_C4_GENERAL),
		SET_ECHO(0x18, 0x18),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ssl_area_2),
		WARP_NODE(0x0A, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCA, LEVEL_SSL, 0x02, 0xCA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCB, LEVEL_SSL, 0x04, 0xEA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xDA, LEVEL_SSL, 0x02, 0xDA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xDB, LEVEL_SSL, 0x06, 0xDB, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BSM_POINT_BALLOON, -11000, 304, -1822, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -10000, 453, 3180, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -9000, 1175, 8140, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -10000, -281, -6805, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 8700, 238, -7545, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 8700, 885, 2444, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 11300, 238, -7545, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 11300, 885, 2444, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -10000, -598, -14009, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 10600, 1209, 7439, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 12500, 562, -2550, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 7500, 562, -2550, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -9000, -95, -1787, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -11000, 1177, 8175, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 9400, 1209, 7439, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_KEY_BALLOON, 10002, 759, -3719, 0, 0, 0, 0x00000000, bhvKeyBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 10000, -78, -14749, 0, 0, 0, 0x00050000, bhvPointBalloon),
		OBJECT(MODEL_NONE, -10007, 1885, 17545, 0, -180, 0, 0x00CA0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 10009, 1919, 16850, 0, -180, 0, 0x00DA0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -10000, 14650, -18800, 0, 0, 0, 0x40CB00C3, bhvWarp),
		OBJECT(MODEL_NONE, 10000, 15250, -19800, 0, 0, 0, 0x40DB00C3, bhvWarp),
		TERRAIN(ssl_area_2_collision),
		ROOMS(ssl_area_2_collision_rooms),
		MACRO_OBJECTS(ssl_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_COURSE8_CYBER),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		SET_BACKGROUND_MUSIC_WITH_REVERB(0x00, SEQ_CUSTOM_COURSE8_CYBER, BRPRESET_BSM_C4_GENERAL, BRPRESET_BSM_C4_GENERAL),
		SET_ECHO(0x18, 0x18),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, ssl_area_3),
		WARP_NODE(0x0A, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCD, LEVEL_SSL, 0x03, 0xCD, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_SSL, 0x03, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BSM_POINT_BALLOON, 1415, -2800, -4307, 0, 135, 0, 0x00040000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 17304, 214, 5510, 0, 9, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 12508, -767, -4743, 0, 50, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 730, 2495, 27572, 0, -78, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 6147, -1820, -5865, 0, 90, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 13943, -478, 818, 0, 33, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 7440, 1827, 21764, 0, -47, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 4284, -2159, -5768, 0, 105, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 10866, -907, -2678, 0, 50, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 15665, -354, -343, 0, 33, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 2621, -2500, -5238, 0, 125, 0, 0x00030000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 14540, 1495, 18791, 0, -30, 0, 0x00030000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -2613, 2700, 27821, 0, -80, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 9899, -1200, -4898, 0, 65, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 16020, -100, 3187, 0, 15, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 13773, -700, -1515, 0, 40, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 11196, 1700, 20612, 0, -40, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 5069, 2100, 25481, 0, -55, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -5539, 2900, 27847, 0, -90, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 14961, 1100, 14961, 0, -20, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 16527, 500, 8655, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 8072, -1503, -5603, 0, 70, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 332, 2476, 25843, 0, -78, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 604, 2456, 26996, 0, -78, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 850, 2545, 28153, 0, -78, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 9392, 1850, 23894, 0, -47, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 8900, 1810, 23355, 0, -47, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 8360, 1787, 22794, 0, -47, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 11832, 1480, 17290, 0, -30, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 12394, 1455, 17612, 0, -30, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 13999, 1463, 18483, 0, -30, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 17262, 860, 12059, 0, -9, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 16630, 833, 11956, 0, -9, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 15334, 837, 11754, 0, -9, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 14875, 122, 5885, 0, 9, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 15732, 154, 5749, 0, 9, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 18028, 240, 5392, 0, 9, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 13414, -487, 1142, 0, 33, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 14479, -472, 454, 0, 33, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 16202, -274, -688, 0, 33, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 11255, -905, -3185, 0, 50, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 12096, -832, -4247, 0, 50, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 8280, -1447, -6168, 0, 70, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 7865, -1561, -5000, 0, 70, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 968, 2595, 28741, 0, -78, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 464, 2466, 26383, 0, -78, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 7892, 1807, 22265, 0, -47, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 9808, 1883, 24342, 0, -47, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 12905, 1432, 17910, 0, -30, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 13445, 1432, 18189, 0, -30, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 14684, 867, 11651, 0, -9, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 16514, 183, 5624, 0, 9, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 15059, -444, 17, 0, 33, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 11685, -900, -3711, 0, 50, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 8482, -1387, -6785, 0, 70, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 7667, -1616, -4412, 0, 70, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_NONE, 9526, 937, 5500, 0, 60, 0, 0x000B0000, bhvBSMCelebrationWarp),
		OBJECT(MODEL_BSM_POINT_BALLOON, 15980, 807, 11853, 0, -9, 0, 0x00050000, bhvPointBalloon),
		OBJECT(MODEL_NONE, -11173, 3300, 26974, 0, 84, 0, 0x00CD0000, bhvInstantActiveWarp),
		TERRAIN(ssl_area_3_collision),
		ROOMS(ssl_area_3_collision_rooms),
		MACRO_OBJECTS(ssl_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_COURSE8_CYBER),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		SET_BACKGROUND_MUSIC_WITH_REVERB(0x00, SEQ_CUSTOM_COURSE8_CYBER, BRPRESET_BSM_C4_GENERAL, BRPRESET_BSM_C4_GENERAL),
		SET_ECHO(0x18, 0x18),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, ssl_area_4),
		WARP_NODE(0x0A, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCA, LEVEL_SSL, 0x04, 0xCA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCB, LEVEL_SSL, 0x02, 0xDA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCC, LEVEL_SSL, 0x05, 0xEA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xDA, LEVEL_SSL, 0x04, 0xDA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xDB, LEVEL_SSL, 0x03, 0xCD, WARP_NO_CHECKPOINT),
		WARP_NODE(0xEA, LEVEL_SSL, 0x04, 0xEA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xEB, LEVEL_SSL, 0x01, 0xDA, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BSM_POINT_BALLOON, 19000, 258, 2422, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 21000, 258, 2422, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 20000, -868, -2101, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 20007, -1077, -4494, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 20000, -1286, -6883, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -600, 1292, 9321, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 600, 1013, 6133, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -600, 734, 2945, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -1200, 545, -1660, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 1200, 545, -1660, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -1200, -13, -8036, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 1200, -13, -8036, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -21000, 939, 2142, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -17000, -468, -2762, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -22000, 1175, 7140, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -19000, 578, 7192, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -21500, 516, -7875, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -22000, 100, -15070, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -18000, -2503, -14838, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 18500, 22, -2576, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 21500, 22, -2576, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -22500, 702, -2857, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 20000, -215, -7575, 0, 0, 0, 0x00030000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 20000, 36, 2642, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 20000, 455, 7424, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 19993, 245, 5024, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -18000, -1390, -7704, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -18000, 55, 2215, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 600, 1292, 9321, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -600, 1013, 6133, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 600, 734, 2945, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 545, -1660, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -1200, 266, -4848, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 1200, 266, -4848, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, -13, -8036, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 20000, -2382, -13817, 0, 0, 0, 0x00050000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 266, -4848, 0, 0, 0, 0x00050000, bhvPointBalloon),
		OBJECT(MODEL_BSM_TCS_TOKEN, 0, -262, -15031, 0, 0, 0, 0x00000000, bhvTCSToken),
		OBJECT(MODEL_NONE, -19991, 1885, 16548, 0, -180, 0, 0x00CA0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 6, 1884, 18530, 0, -180, 0, 0x00DA0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 20002, 1745, 16584, 0, -180, 0, 0x00EA0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -22000, 15450, -19800, 0, 0, 0, 0x40CB00C3, bhvWarp),
		OBJECT(MODEL_NONE, -18000, 12650, -19500, 0, 0, 0, 0x40CC00C3, bhvWarp),
		OBJECT(MODEL_NONE, 0, 14850, -19900, 0, 0, 0, 0x40DB00C3, bhvWarp),
		OBJECT(MODEL_NONE, 20000, 12850, -18600, 0, 0, 0, 0x40EB00C3, bhvWarp),
		TERRAIN(ssl_area_4_collision),
		ROOMS(ssl_area_4_collision_rooms),
		MACRO_OBJECTS(ssl_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_COURSE8_CYBER),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		SET_BACKGROUND_MUSIC_WITH_REVERB(0x00, SEQ_CUSTOM_COURSE8_CYBER, BRPRESET_BSM_C4_GENERAL, BRPRESET_BSM_C4_GENERAL),
		SET_ECHO(0x18, 0x18),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(5, ssl_area_5),
		WARP_NODE(0x0A, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCA, LEVEL_SSL, 0x05, 0xCA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCB, LEVEL_SSL, 0x04, 0xDA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCC, LEVEL_SSL, 0x05, 0xDA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xDA, LEVEL_SSL, 0x05, 0xDA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xDB, LEVEL_SSL, 0x03, 0xCD, WARP_NO_CHECKPOINT),
		WARP_NODE(0xEA, LEVEL_SSL, 0x05, 0xEA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xEB, LEVEL_SSL, 0x06, 0xDB, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BSM_POINT_BALLOON, 18400, 1085, 2427, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 21600, 1085, 2427, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 18800, 636, -7580, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 21200, 636, -7580, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -1200, -13, -8036, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 266, -4848, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -1200, 545, -1660, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 734, 2945, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 1200, 1013, 6133, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 1292, 9321, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -20500, 1275, 7131, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -19800, 1038, 2133, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -19000, 802, -2866, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -20500, 565, -7879, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -18000, -598, -15009, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 20000, 860, -2594, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -21500, -598, -15009, 0, 0, 0, 0x00030000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 17800, 860, -2576, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 22200, 860, -2576, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 19000, 1309, 7430, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 21000, 1309, 7430, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -18500, 565, -7879, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 1200, 1292, 9321, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 1013, 6133, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 1200, 734, 2945, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, 545, -1660, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -1200, 266, -4848, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, -13, -8036, 0, 0, 0, 0x00060000, bhvPointBalloon),
		OBJECT(MODEL_BSM_KEY_GATE, -19819, -997, -13618, 0, 90, 0, 0x00000000, bhvKeyGate),
		OBJECT(MODEL_BSM_KEY_GATE, -22619, -997, -9794, 0, 0, 0, 0x00000000, bhvKeyGate),
		OBJECT(MODEL_BSM_KEY_GATE, -20519, -997, -11006, 0, 60, 0, 0x00000000, bhvKeyGate),
		OBJECT(MODEL_BSM_KEY_GATE, -19819, -997, -16418, 0, 90, 0, 0x00000000, bhvKeyGate),
		OBJECT(MODEL_BSM_KEY_GATE, -19819, -997, -19218, 0, 90, 0, 0x00000000, bhvKeyGate),
		OBJECT(MODEL_BSM_KEY_GATE, -19819, 903, -13618, 0, 90, 0, 0x00000000, bhvKeyGate),
		OBJECT(MODEL_BSM_KEY_GATE, -22619, 903, -9794, 0, 0, 0, 0x00000000, bhvKeyGate),
		OBJECT(MODEL_BSM_KEY_GATE, -20519, 903, -11006, 0, 60, 0, 0x00000000, bhvKeyGate),
		OBJECT(MODEL_BSM_KEY_GATE, -19819, 903, -16418, 0, 90, 0, 0x00000000, bhvKeyGate),
		OBJECT(MODEL_BSM_KEY_GATE, -19819, 903, -19218, 0, 90, 0, 0x00000000, bhvKeyGate),
		OBJECT(MODEL_BSM_POINT_BALLOON, 20000, 221, -14775, 0, 0, 0, 0x00050000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 0, -312, -15040, 0, 0, 0, 0x00050000, bhvPointBalloon),
		OBJECT(MODEL_NONE, -19998, 1886, 16560, 0, -180, 0, 0x00CA0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -4, 1884, 18535, 0, -180, 0, 0x00DA0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 20007, 1920, 16856, 0, -180, 0, 0x00EA0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -22000, 14650, -19800, 0, 0, 0, 0x40CB00C3, bhvWarp),
		OBJECT(MODEL_NONE, -18000, 14650, -19800, 0, 0, 0, 0x40CC00C3, bhvWarp),
		OBJECT(MODEL_NONE, 0, 14950, -19800, 0, 0, 0, 0x40DB00C3, bhvWarp),
		OBJECT(MODEL_NONE, 20000, 15450, -19800, 0, 0, 0, 0x40EB00C3, bhvWarp),
		TERRAIN(ssl_area_5_collision),
		ROOMS(ssl_area_5_collision_rooms),
		MACRO_OBJECTS(ssl_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_COURSE8_CYBER),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		SET_BACKGROUND_MUSIC_WITH_REVERB(0x00, SEQ_CUSTOM_COURSE8_CYBER, BRPRESET_BSM_C4_GENERAL, BRPRESET_BSM_C4_GENERAL),
		SET_ECHO(0x18, 0x18),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(6, ssl_area_6),
		WARP_NODE(0x0A, LEVEL_SSL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_SSL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_SSL, 0x01, 0xF1, WARP_NO_CHECKPOINT),
		WARP_NODE(0xCC, LEVEL_SSL, 0x05, 0xCA, WARP_NO_CHECKPOINT),
		WARP_NODE(0xDB, LEVEL_SSL, 0x06, 0xDB, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BSM_POINT_BALLOON, -11520, 3181, 3104, 0, -165, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 3810, 5181, -5386, 0, 65, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 2837, 4556, -1781, 0, -80, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 4506, 3231, 2138, 0, -115, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -4426, 4281, -5806, 0, 15, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -9059, 4881, -8409, 0, -47, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -5465, 6806, -14285, 0, -58, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 4625, 2806, 5355, 0, -55, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 1291, 6806, -14510, 0, 60, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -9568, 2896, 4808, 0, 75, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -5695, 5931, -8313, 0, 20, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 1291, 5911, -9935, 0, -45, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -10333, 3481, 520, 0, -55, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -1258, 1284, 13761, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -2758, 1284, 13761, 0, 0, 0, 0x00010000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 2708, 6375, -12137, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 5417, 3024, 3740, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -6977, 6419, -11650, 0, -5, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -1999, -298, 19314, 0, 0, 0, 0x00020000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -1998, -946, 22229, 0, 0, 0, 0x00030000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -2501, 7915, -22200, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -4461, 1681, 10414, 0, 5, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -6582, 2531, 4501, 0, 95, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 2269, 3581, 2276, 0, -85, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -6935, 5481, -4776, 0, 110, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -1500, 7415, -18200, 0, 5, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 2153, 2506, 5461, 0, -90, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -1206, 1771, 9874, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -4867, 4081, -2609, 0, 155, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -9556, 5181, -5825, 0, 25, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -2501, 7415, -18200, 0, -5, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -7175, 3781, -380, 0, -65, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 540, 4281, -1478, 0, 120, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -1500, 7915, -22200, 0, 0, 0, 0x00000000, bhvPointBalloon),
		OBJECT(MODEL_BSM_ROTATING_GLOBE, -2000, -1038, 24363, 0, 0, 0, 0x00000000, bhvRotatingGlobe),
		OBJECT(MODEL_BSM_POINT_BALLOON, -2008, 835, 16568, 0, 0, 0, 0x00050000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, -6302, 4581, -8601, 0, 60, 0, 0x00050000, bhvPointBalloon),
		OBJECT(MODEL_BSM_POINT_BALLOON, 4799, 4881, -3152, 0, -15, 0, 0x00050000, bhvPointBalloon),
		OBJECT(MODEL_NONE, -1997, 8096, -26091, 0, 0, 0, 0x00DB0000, bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, -1994, -439, 24559, 0, 0, 0, 0x40CC003C, bhvWarp),
		TERRAIN(ssl_area_6_collision),
		ROOMS(ssl_area_6_collision_rooms),
		MACRO_OBJECTS(ssl_area_6_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_CUSTOM_COURSE8_CYBER),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		SET_BACKGROUND_MUSIC_WITH_REVERB(0x00, SEQ_CUSTOM_COURSE8_CYBER, BRPRESET_BSM_C4_GENERAL, BRPRESET_BSM_C4_GENERAL),
		SET_ECHO(0x18, 0x18),
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, -13264, 12216, 24954),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
