#include "src/game/envfx_snow.h"

const GeoLayout balloon_pop_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, balloon_pop_model_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};