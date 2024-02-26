#include "src/game/envfx_snow.h"

const GeoLayout custom_menu_rank_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_rank_model_mesh_layer_5_before),
		GEO_SWITCH_CASE(7, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_rank_model_mesh_layer_5_rank_f),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_rank_model_mesh_layer_5_rank_d),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_rank_model_mesh_layer_5_rank_c),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_rank_model_mesh_layer_5_rank_b),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_rank_model_mesh_layer_5_rank_a),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_rank_model_mesh_layer_5_rank_s),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_rank_model_mesh_layer_5_rank_g),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_rank_model_mesh_layer_5_after),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
