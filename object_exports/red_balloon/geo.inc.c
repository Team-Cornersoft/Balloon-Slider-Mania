#include "src/game/envfx_snow.h"

const GeoLayout red_balloon_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, red_balloon_Red_balloon_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, red_balloon_Red_balloon_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
