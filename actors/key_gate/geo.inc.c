#include "src/game/envfx_snow.h"

const GeoLayout key_gate_Armature_switch[] = {
	GEO_NODE_START(),
	GEO_RETURN(),
};
const GeoLayout key_gate_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, key_gate_switch_child_mesh_layer_5),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, key_gate_Armature_switch),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
