void scroll_ddd_dl_0_stars_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 56;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_0_stars_mesh_layer_4_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_0_stars_001_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 48;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_0_stars_001_mesh_layer_4_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_0_stars_002_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 56;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_0_stars_002_mesh_layer_4_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_0_stars_003_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 62;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_0_stars_003_mesh_layer_4_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_C_start_line_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_start_line_mesh_layer_5_vtx_0);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ddd_dl_C_start_line_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 24;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_start_line_mesh_layer_5_vtx_1);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ddd_dl_C_start_line_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 10;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_start_line_mesh_layer_5_vtx_2);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_stage_a1_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_stage_a1_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_gfx_mat_ddd_dl_Dot_lights() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_Dot_lights);
	static int interval_tex_ddd_dl_Dot_lights = 12;
	static int cur_interval_tex_ddd_dl_Dot_lights = 12;

	if (--cur_interval_tex_ddd_dl_Dot_lights <= 0) {
		shift_s(mat, 8, PACK_TILESIZE(0, 64));
		cur_interval_tex_ddd_dl_Dot_lights = interval_tex_ddd_dl_Dot_lights;
	}

};

void scroll_ddd() {
	scroll_ddd_dl_0_stars_mesh_layer_4_vtx_0();
	scroll_ddd_dl_0_stars_001_mesh_layer_4_vtx_0();
	scroll_ddd_dl_0_stars_002_mesh_layer_4_vtx_0();
	scroll_ddd_dl_0_stars_003_mesh_layer_4_vtx_0();
	scroll_ddd_dl_C_start_line_mesh_layer_5_vtx_0();
	scroll_ddd_dl_C_start_line_mesh_layer_5_vtx_1();
	scroll_ddd_dl_C_start_line_mesh_layer_5_vtx_2();
	scroll_ddd_dl_stage_a1_mesh_layer_5_vtx_0();
	scroll_gfx_mat_ddd_dl_Dot_lights();
};
