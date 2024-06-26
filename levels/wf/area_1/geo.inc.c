#include "src/game/envfx_snow.h"

const GeoLayout wf_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(4, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, wf_dl_1_area1_geo),
			GEO_BRANCH(1, wf_dl_2_area1_geo),
			GEO_BRANCH(1, wf_dl_3_area1_geo),
		GEO_CLOSE_NODE(),
		GEO_SCENE_LIGHT(LIGHT_TYPE_AMBIENT, 80, 83, 82, 0, 0, 0),
		GEO_SCENE_LIGHT(LIGHT_TYPE_DIRECTIONAL, 120, 123, 122, 125, 125, 125),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_1_area1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -15000, 4554, 14423, wf_dl_A_Aqueduct_a_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -15000, 3887, 4846, wf_dl_A_Aqueduct_b_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -15000, 3218, -4730, wf_dl_A_Aqueduct_c_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -15000, 2500, -14312, wf_dl_A_Aqueduct_d_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -15000, 6205, 21996, wf_dl_A_Aqueduct_tower_a_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -15000, 3062, -20728, wf_dl_A_Aqueduct_tower_b_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1504, -5480, -18500, wf_dl_A_Environment_a_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -27322, 3582, -15463, wf_dl_A_Environment_b_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -16665, -5575, 23999, wf_dl_A_Environment_c_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 17542, -7302, 28296, wf_dl_A_Environment_d_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -31115, 483, -1424, wf_dl_A_Lake_floor_a_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9953, -11288, 2038, wf_dl_A_Lake_floor_b_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 13470, -23030, 8358, wf_dl_A_Lake_floor_c_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -7129, 5744, -19843, wf_dl_B_pine_tree_015_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_B_pine_tree_015_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -10829, 6194, -22243, wf_dl_B_pine_tree_016_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_B_pine_tree_016_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -20599, 6594, -23123, wf_dl_B_pine_tree_017_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_B_pine_tree_017_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 10651, 4334, -20843, wf_dl_B_pine_tree_018_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_B_pine_tree_018_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 11311, 4294, -18743, wf_dl_B_pine_tree_019_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_B_pine_tree_019_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 15871, 3414, -14523, wf_dl_B_pine_tree_020_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_B_pine_tree_020_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 15501, 3234, -11153, wf_dl_B_pine_tree_021_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, wf_dl_B_pine_tree_021_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 4460, 6470, -13159, wf_dl_B_Trees_a_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_B_Trees_a_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 3022, 6252, -21462, wf_dl_B_Trees_b_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_B_Trees_b_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -25000, 9363, -21642, wf_dl_B_Trees_c_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_B_Trees_c_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -20042, 12828, 28734, wf_dl_B_Trees_d_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_B_Trees_d_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 12778, 10214, 27527, wf_dl_B_Trees_e_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wf_dl_B_Trees_e_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -15000, 6142, 1286, wf_dl_C_rapids_a1_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 2150, 1368, -19992, wf_dl_C_rapids_a2_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -15000, 6142, 1286, wf_dl_C_rapids_b1_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 2150, 1368, -19992, wf_dl_C_rapids_b2_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -14716, 11016, 19459, wf_dl_C_sart_line_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -29220, 851, -1635, wf_dl_D_Backdrop_water_ar1_1a_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -29220, 851, -1635, wf_dl_D_Backdrop_water_ar1_1b_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 10448, -20574, 6975, wf_dl_D_Backdrop_water_ar1_2a_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 10448, -20574, 6975, wf_dl_D_Backdrop_water_ar1_2b_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -11776, -9874, 1722, wf_dl_D_backdrop_waterfall_ar1_1a_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -11776, -9874, 1722, wf_dl_D_backdrop_waterfall_ar1_1b_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_2_area1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_dl_3_area1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wf_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x431B),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 127, 65535, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, -140000, 0, 0, -140000, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, wf_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_RAIN, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
