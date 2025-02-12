#include "src/game/envfx_snow.h"

const GeoLayout jrb_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(4, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, jrb_dl_1_area1_geo),
			GEO_BRANCH(1, jrb_dl_2_area1_geo),
			GEO_BRANCH(1, jrb_dl_3_area1_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -16000, 1371, -16000, jrb_dl_0_skybox_a_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 15998, 1371, -16000, jrb_dl_0_skybox_b_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -16000, 1371, 15959, jrb_dl_0_skybox_c_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 15998, 1371, 15959, jrb_dl_0_skybox_d_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, -15666, 3237, -15726, 6, 0, 0, jrb_dl_0_stars_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 15391, 4205, 18679, 6, 0, 0, jrb_dl_0_stars_001_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, -15667, 4119, 15622, 6, 0, 0, jrb_dl_0_stars_002_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 15694, 3323, -12668, 6, 0, 0, jrb_dl_0_stars_003_mesh_layer_4),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, 0, 0, -31300, jrb_dl_A_moon_glow_mesh_layer_5),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_ALPHA, 0, 0, -31200, jrb_dl_A_the_fucking_moon_mesh_layer_4),
		GEO_SCENE_LIGHT(LIGHT_TYPE_AMBIENT, 50, 35, 60, 0, 0, 0),
		GEO_SCENE_LIGHT(LIGHT_TYPE_DIRECTIONAL, 210, 200, 190, 0, 100, -127),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_1_area1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -18502, -5188, 7390, jrb_dl_A_environment_a1_a_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, jrb_dl_A_environment_a1_a_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 9609, 54, 28678, jrb_dl_A_environment_a1_b_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 16392, -4472, 1824, jrb_dl_A_environment_a1_c_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, jrb_dl_A_environment_a1_c_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 728, -8393, -22389, jrb_dl_A_environment_a1_d_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, jrb_dl_A_environment_a1_d_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 14544, -21243, 14067, jrb_dl_A_environment_a1_floor_a_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 16567, -21209, -17588, jrb_dl_A_environment_a1_floor_b_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -16382, -21220, -14562, jrb_dl_A_environment_a1_floor_c_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -15000, 300, -9400, jrb_dl_B_Giant_mushroom_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -17350, -50, 13700, jrb_dl_B_Mushrooms_a_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 11700, -3400, 3500, jrb_dl_B_Mushrooms_b_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1300, -7750, -18500, jrb_dl_B_Mushrooms_c_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -30735, 290, -1417, jrb_dl_B_Mushrooms_flat_a_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 30111, -1260, -3357, jrb_dl_B_Mushrooms_flat_b_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 18535, 590, 28412, 0, -90, 0, jrb_dl_B_Mushrooms_flat_b_001_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, -58, -5760, -31654, 0, 85, 0, jrb_dl_B_Mushrooms_flat_b_002_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -3476, -4212, 8278, jrb_dl_Bridge_a_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 9223, -7928, -10962, jrb_dl_Bridge_b_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 4084, -8403, -17418, 0, 66, 0, jrb_dl_C_cross_roads_sign_002_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, jrb_dl_C_cross_roads_sign_002_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 5534, -8403, -18202, 0, -4, 0, jrb_dl_C_cross_roads_sign_003_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, jrb_dl_C_cross_roads_sign_003_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 7703, -5133, 5535, 0, -64, 0, jrb_dl_C_cross_roads_sign_004_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, jrb_dl_C_cross_roads_sign_004_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -1100, -9500, 8000, -15, 90, 0, jrb_dl_C_pipe_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 10400, -4100, 10000, 95, 90, 0, jrb_dl_C_pipe_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -7900, -10900, -23347, 85, 45, 0, jrb_dl_C_pipe_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -14348, -712, 18927, jrb_dl_C_sart_line_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 17072, -6012, 3367, 0, -104, 0, jrb_dl_C_sart_line_001_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_2_area1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_dl_3_area1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 127, 65535, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, jrb_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
