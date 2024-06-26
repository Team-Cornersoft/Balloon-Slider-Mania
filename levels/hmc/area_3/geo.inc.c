#include "src/game/envfx_snow.h"

const GeoLayout hmc_area_3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_1_area3_geo),
		GEO_CLOSE_NODE(),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, 30000, 20500, 16000, hmc_dl_0_SKY_SUN_002_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -15991, -2600, -16000, hmc_dl_0_SKYBOX_a_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 16000, -2600, -16000, hmc_dl_0_SKYBOX_b_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -15991, -2600, 15947, hmc_dl_0_SKYBOX_c_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 16000, -2600, 15947, hmc_dl_0_SKYBOX_d_002_mesh_layer_1),
		GEO_SCENE_LIGHT(LIGHT_TYPE_AMBIENT, 70, 60, 80, 0, 0, 0),
		GEO_SCENE_LIGHT(LIGHT_TYPE_DIRECTIONAL, 226, 200, 210, 127, 127, 127),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_1_area3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -11510, 3906, 3833, 0, 10, 0, hmc_dl_A_dragon_a3_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 11560, 3906, 3833, 0, -10, 0, hmc_dl_A_dragon_a3_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -6247, 9382, 29147, 0, -130, 0, hmc_dl_B_Dragon_exit_a3_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_B_Dragon_exit_a3_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 6321, 9382, 29476, 0, 160, 0, hmc_dl_B_Dragon_exit_a3_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_B_Dragon_exit_a3_001_mesh_layer_6),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, 5869, 1559, -6389, 45, -35, 0, hmc_dl_C_finish_line_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT, -5819, 1559, -6389, 45, 35, 0, hmc_dl_C_finish_line_001_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 21, -366, -61, 0, -110, 0, hmc_dl_C_sakurai_tree_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_C_sakurai_tree_001_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -8859, 2234, -29121, 0, 145, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE_WITH_DL(LAYER_OPAQUE, 104858, hmc_dl_C_sakurai_tree_001_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_C_sakurai_tree_001_mesh_layer_4),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -28659, 2234, -17721, 0, 50, 0, hmc_dl_C_sakurai_tree_015_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_C_sakurai_tree_015_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 14741, 2234, -27921, 0, 15, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE_WITH_DL(LAYER_OPAQUE, 104858, hmc_dl_C_sakurai_tree_001_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_C_sakurai_tree_001_mesh_layer_4),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 28131, 2234, -21311, 0, 120, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE_WITH_DL(LAYER_OPAQUE, 104858, hmc_dl_C_sakurai_tree_001_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_C_sakurai_tree_001_mesh_layer_4),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -679, 3200, 129, hmc_dl_Forest_a3_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Forest_a3_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 77, -12600, -143, hmc_dl_Plateau_a3_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 21938, -10200, -24457, hmc_dl_Plateau_a3_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1076, -10700, 24367, hmc_dl_Plateau_a3_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -19592, -9700, -24478, hmc_dl_Plateau_a3_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 77, -12500, -143, hmc_dl_Water_a3_A_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 77, -12500, -143, hmc_dl_Water_a3_B_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_area_3[] = {
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
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, hmc_area_3_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
