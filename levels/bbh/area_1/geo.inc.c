#include "src/game/envfx_snow.h"

const GeoLayout bbh_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bbh_dl_1_area1_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -16000, 3371, -16000, bbh_dl_0_skybox_a_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 15998, 3371, -16000, bbh_dl_0_skybox_b_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -16000, 3371, 15959, bbh_dl_0_skybox_c_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 15998, 3371, 15959, bbh_dl_0_skybox_d_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, -15666, 5237, -15726, 6, 0, 0, bbh_dl_0_stars_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 15391, 6205, 18679, 6, 0, 0, bbh_dl_0_stars_001_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, -15667, 6119, 15622, 6, 0, 0, bbh_dl_0_stars_002_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 15694, 5323, -12668, 6, 0, 0, bbh_dl_0_stars_003_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -7975, 2413, 4566, bbh_dl_A_forest_a_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_A_forest_a_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -13755, 2770, -18682, bbh_dl_A_forest_b_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_A_forest_b_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -8307, -1412, 19253, bbh_dl_A_forest_c_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_A_forest_c_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, -31300, 3600, 0, bbh_dl_A_moon_glow_mesh_layer_5),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_ALPHA, -31200, 3600, 0, bbh_dl_A_the_fucking_moon_mesh_layer_4),
		GEO_SCENE_LIGHT(LIGHT_TYPE_AMBIENT, 56, 50, 68, 0, 0, 0),
		GEO_SCENE_LIGHT(LIGHT_TYPE_DIRECTIONAL, 200, 180, 210, -127, 100, 0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_dl_1_area1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 247, 4744, 1146, bbh_dl_A_area1_slide_a_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5071, 2394, -4943, bbh_dl_B_jolly_tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_B_jolly_tree_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_B_jolly_tree_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9030, 2094, -3969, bbh_dl_B_jolly_tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_B_jolly_tree_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_B_jolly_tree_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11910, 1674, -4344, bbh_dl_B_jolly_tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_B_jolly_tree_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_B_jolly_tree_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -12710, 1194, -2095, bbh_dl_B_jolly_tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_B_jolly_tree_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_B_jolly_tree_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -14970, 394, -225, bbh_dl_B_jolly_tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_B_jolly_tree_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_B_jolly_tree_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -15010, 894, -2495, bbh_dl_B_jolly_tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_B_jolly_tree_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_B_jolly_tree_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2930, 4594, -16459, bbh_dl_B_jolly_tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_B_jolly_tree_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_B_jolly_tree_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -240, 4594, -15369, bbh_dl_B_jolly_tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_B_jolly_tree_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_B_jolly_tree_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3190, 4394, -17039, bbh_dl_B_jolly_tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_B_jolly_tree_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_B_jolly_tree_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 990, 4494, -2139, bbh_dl_B_jolly_tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_B_jolly_tree_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_B_jolly_tree_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 9360, 5644, -6139, bbh_dl_B_jolly_tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_B_jolly_tree_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_B_jolly_tree_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5840, 6564, 1311, bbh_dl_B_jolly_tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_B_jolly_tree_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_B_jolly_tree_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -16900, -1956, 12225, bbh_dl_B_jolly_tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_B_jolly_tree_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_B_jolly_tree_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2560, -4786, 15835, bbh_dl_B_jolly_tree_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_B_jolly_tree_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bbh_dl_B_jolly_tree_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 21038, 6506, 4320, bbh_dl_C_start_line_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bbh_dl_C_start_line_mesh_layer_5),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 127, 65535, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, -70000, 0, 0, -70000, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bbh_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};