#include "src/game/envfx_snow.h"

const GeoLayout custom_moving_dragon_bridge_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_moving_dragon_bridge_Platform_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
