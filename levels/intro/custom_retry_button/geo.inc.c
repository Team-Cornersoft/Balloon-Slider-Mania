#include "src/game/envfx_snow.h"

const GeoLayout custom_retry_button_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo_bsm_retry_menu_set_clownfont_color),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_retry_button_model_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
