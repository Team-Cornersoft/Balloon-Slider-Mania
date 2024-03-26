#include "src/game/envfx_snow.h"

const GeoLayout custom_gong_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_gong_Gong_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, custom_gong_Gong_mesh_layer_6),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
