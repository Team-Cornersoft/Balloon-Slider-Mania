#include "src/game/envfx_snow.h"

const GeoLayout point_balloon_popped_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
	  GEO_BILLBOARD(),
      GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_layer_transparency),
	  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_sploosh_kaboom_hit_piece_mesh_layer_4),
	  GEO_DISPLAY_LIST(LAYER_TRANSPARENT, custom_sploosh_kaboom_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
