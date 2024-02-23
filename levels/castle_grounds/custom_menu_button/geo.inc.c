#include "src/game/envfx_snow.h"

const GeoLayout custom_menu_button_geo[] = {
	GEO_TRANSLATE(LAYER_OPAQUE, 0, -118, 0),
	GEO_OPEN_NODE(),
		GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_bsm_menu_set_envcolor),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_button_model_mesh_layer_5),
		GEO_SWITCH_CASE(2, geo_switch_bparam2),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_menu_button_model_mesh_layer_1_stats),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_menu_button_model_mesh_layer_1_credits),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
