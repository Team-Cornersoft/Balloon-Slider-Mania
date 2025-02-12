void scroll_wf_dl_C_sart_line_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 8;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_C_sart_line_mesh_layer_5_vtx_0);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wf_dl_C_sart_line_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 8;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_C_sart_line_mesh_layer_5_vtx_1);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wf_dl_C_sart_line_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 4;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(wf_dl_C_sart_line_mesh_layer_5_vtx_2);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_wf_dl_C_Finish_line_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 36;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(wf_dl_C_Finish_line_mesh_layer_5_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_wf_dl_C_Finish_line_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 96;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_C_Finish_line_mesh_layer_5_vtx_1);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wf_dl_C_Finish_line_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 96;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_C_Finish_line_mesh_layer_5_vtx_2);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_mat_wf_dl_Flow_a_layer5() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_Flow_a_layer5);


	shift_s_down(mat, 14, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 14, PACK_TILESIZE(0, 5));
	shift_t_down(mat, 16, PACK_TILESIZE(0, 6));

};

void scroll_gfx_mat_wf_dl_Flow_b_layer5() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_Flow_b_layer5);


	shift_s(mat, 14, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 14, PACK_TILESIZE(0, 5));
	shift_t_down(mat, 16, PACK_TILESIZE(0, 6));

};

void scroll_gfx_mat_wf_dl_Water_a_layer5() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_Water_a_layer5);


	shift_s_down(mat, 14, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));
	shift_s(mat, 16, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_wf_dl_Water_b_layer5() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_Water_b_layer5);


	shift_s_down(mat, 14, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 14, PACK_TILESIZE(0, 1));
	shift_s(mat, 16, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 16, PACK_TILESIZE(0, 2));

};

void scroll_wf() {
	scroll_wf_dl_C_sart_line_mesh_layer_5_vtx_0();
	scroll_wf_dl_C_sart_line_mesh_layer_5_vtx_1();
	scroll_wf_dl_C_sart_line_mesh_layer_5_vtx_2();
	scroll_wf_dl_C_Finish_line_mesh_layer_5_vtx_0();
	scroll_wf_dl_C_Finish_line_mesh_layer_5_vtx_1();
	scroll_wf_dl_C_Finish_line_mesh_layer_5_vtx_2();
	scroll_gfx_mat_wf_dl_Flow_a_layer5();
	scroll_gfx_mat_wf_dl_Flow_b_layer5();
	scroll_gfx_mat_wf_dl_Water_a_layer5();
	scroll_gfx_mat_wf_dl_Water_b_layer5();
};
