#include "src/game/envfx_snow.h"

const GeoLayout custom_menu_stage_geo[] = {
	GEO_TRANSLATE(LAYER_OPAQUE, 0, -210, 0),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_bsm_menu_set_special_transparency),
		GEO_SWITCH_CASE(3, geo_bsm_menu_switch_alpha_stage),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_menu_stage_model_mesh_layer_1_before),
				GEO_SWITCH_CASE(9, geo_switch_bparam2),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_menu_stage_model_mesh_layer_1_dl1),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_menu_stage_model_mesh_layer_1_dl2),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_menu_stage_model_mesh_layer_1_dl3),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_menu_stage_model_mesh_layer_1_dl4),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_menu_stage_model_mesh_layer_1_dl5),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_menu_stage_model_mesh_layer_1_dl6),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_menu_stage_model_mesh_layer_1_dl7),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_menu_stage_model_mesh_layer_1_dl8),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_menu_stage_model_mesh_layer_1_dl9),
				GEO_CLOSE_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_menu_stage_model_mesh_layer_1_after),
			GEO_CLOSE_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_1_before),
				GEO_SWITCH_CASE(9, geo_switch_bparam2),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_1_dl1),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_1_dl2),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_1_dl3),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_1_dl4),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_1_dl5),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_1_dl6),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_1_dl7),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_1_dl8),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_1_dl9),
				GEO_CLOSE_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_1_after),
			GEO_CLOSE_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ASM(0, geo_bsm_menu_video_scene),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_5_before),
			GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_bsm_menu_set_envcolor),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_5_unlocked),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_5_locked),
			GEO_CLOSE_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_stage_model_mesh_layer_5_after),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
