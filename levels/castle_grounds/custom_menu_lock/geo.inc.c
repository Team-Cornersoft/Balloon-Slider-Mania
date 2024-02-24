#include "src/game/envfx_snow.h"

const GeoLayout custom_menu_lock_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_bsm_menu_set_envcolor),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_menu_lock_model_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
