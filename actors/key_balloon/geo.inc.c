#include "src/game/envfx_snow.h"

const GeoLayout key_balloon_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, key_balloon_Key_balloon_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, key_balloon_Key_balloon_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
