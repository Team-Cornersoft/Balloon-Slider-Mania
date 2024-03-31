void scroll_gfx_mat_custom_portal_globe_Planet_projection_layer5() {
	Gfx *mat = segmented_to_virtual(mat_custom_portal_globe_Planet_projection_layer5);


	shift_t_down(mat, 10, PACK_TILESIZE(0, 3));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));

};

void scroll_ssl_level_geo_custom_portal_globe() {
	scroll_gfx_mat_custom_portal_globe_Planet_projection_layer5();
};
