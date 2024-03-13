#include "src/game/envfx_snow.h"

const GeoLayout key_gate_01_Key_gate_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ROTATION_NODE_WITH_DL(LAYER_TRANSPARENT, 90, 0, 0, key_gate_01_Key_gate_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout key_gate_02_Key_gate_switch_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, key_gate_02_Key_gate_switch_mesh_layer_5),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout key_gate_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(2, geo_switch_anim_state),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, key_gate_01_Key_gate_geo),
			GEO_BRANCH(1, key_gate_02_Key_gate_switch_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
