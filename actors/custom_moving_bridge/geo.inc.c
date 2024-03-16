#include "src/game/envfx_snow.h"

const GeoLayout custom_moving_bridge_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_moving_bridge_Rotatable_platform_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
