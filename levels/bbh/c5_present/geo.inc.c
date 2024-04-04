#include "src/game/envfx_snow.h"

const GeoLayout c5_present_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(10, 128, 200),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, c5_present_Present_mesh_layer_6),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, c5_present_Present_mesh_layer_1),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
