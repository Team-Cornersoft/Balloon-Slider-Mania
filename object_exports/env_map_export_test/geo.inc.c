#include "src/game/envfx_snow.h"

const GeoLayout env_map_export_test_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, env_map_export_test_Examples_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
