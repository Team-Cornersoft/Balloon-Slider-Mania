#include "src/game/envfx_snow.h"

const GeoLayout point_balloon_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, point_balloon_Balloons_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, point_balloon_Balloons_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
