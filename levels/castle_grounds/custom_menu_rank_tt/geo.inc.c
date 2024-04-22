#include "src/game/envfx_snow.h"

const GeoLayout custom_menu_rank_tt_01_rank_tt_bronze_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_rank_tt_01_rank_tt_bronze_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout custom_menu_rank_tt_02_rank_tt_silver_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_rank_tt_02_rank_tt_silver_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout custom_menu_rank_tt_03_rank_tt_gold_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_rank_tt_03_rank_tt_gold_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout custom_menu_rank_tt_04_rank_tt_top_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_rank_tt_04_rank_tt_top_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout custom_menu_rank_tt_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, custom_menu_rank_tt_01_rank_tt_bronze_geo),
			GEO_BRANCH(1, custom_menu_rank_tt_02_rank_tt_silver_geo),
			GEO_BRANCH(1, custom_menu_rank_tt_03_rank_tt_gold_geo),
			GEO_BRANCH(1, custom_menu_rank_tt_04_rank_tt_top_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
