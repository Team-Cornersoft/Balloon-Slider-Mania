#include "src/game/envfx_snow.h"

const GeoLayout bouncy_shroom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bouncy_shroom_Bouncy_shroom_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
