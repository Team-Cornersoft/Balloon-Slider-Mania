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

void scroll_ddd_dl_B_stage_a1_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_B_stage_a1_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_C_rainbow_pipe_a1_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_rainbow_pipe_a1_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_C_rainbow_pipe_a1_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 234;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_rainbow_pipe_a1_mesh_layer_1_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

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

void scroll_ddd_dl_C_Portal_a1_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 8;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_Portal_a1_001_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_C_Portal_a1_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 51;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_Portal_a1_001_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_C_Rainbow_pipe_a1_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 234;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_Rainbow_pipe_a1_mesh_layer_1_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_C_Rainbow_pipe_a1_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_Rainbow_pipe_a1_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_EvoQ_Stage1_Backdrop_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 6;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_EvoQ_Stage1_Backdrop_mesh_layer_5_vtx_0);

	deltaY = (int)(0.20000000298023224 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ddd_dl_EvoQ_Stage1_water_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 41;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_EvoQ_Stage1_water_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ddd_dl_EvoQ_stage1_waterfall_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 8;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_EvoQ_stage1_waterfall_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ddd_dl_EvoQ_Stage2_water_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 28;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_EvoQ_Stage2_water_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ddd_dl_EvoQ_Stage2_waterfall_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 8;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_EvoQ_Stage2_waterfall_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ddd_dl_EvoQ_Stage3_Backdrop_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 12;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_EvoQ_Stage3_Backdrop_mesh_layer_5_vtx_0);

	deltaY = (int)(0.20000000298023224 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ddd_dl_EvoQ_Stage3_toxic_waste_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 15;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_EvoQ_Stage3_toxic_waste_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ddd_dl_EvoQ_Stage3_watefall_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 8;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_EvoQ_Stage3_watefall_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ddd_dl_Rainbow_pipe_a2_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 234;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_Rainbow_pipe_a2_mesh_layer_1_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_Rainbow_pipe_a2_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_Rainbow_pipe_a2_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_Rainbow_pipe_a2_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_Rainbow_pipe_a2_001_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_Rainbow_pipe_a2_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 234;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_Rainbow_pipe_a2_001_mesh_layer_1_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_Rainbow_road_a2_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 169;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_Rainbow_road_a2_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_Rainbow_pipe_a3_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 240;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_Rainbow_pipe_a3_mesh_layer_1_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_Rainbow_pipe_a3_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_Rainbow_pipe_a3_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_Rainbow_pipe_a3_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_Rainbow_pipe_a3_001_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_Rainbow_pipe_a3_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 234;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_Rainbow_pipe_a3_001_mesh_layer_1_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_0_stars_004_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 62;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_0_stars_004_mesh_layer_4_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_0_stars_005_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 56;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_0_stars_005_mesh_layer_4_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_0_stars_006_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 48;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_0_stars_006_mesh_layer_4_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_0_stars_007_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 56;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_0_stars_007_mesh_layer_4_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_A_MvsWW_a4_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 14;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_A_MvsWW_a4_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_A_MvsWW_a4_backdrop_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 28;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_A_MvsWW_a4_backdrop_mesh_layer_5_vtx_0);

	deltaX = (int)(-0.05000000074505806 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_C_Rainbow_pipe_a4_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_Rainbow_pipe_a4_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_C_Rainbow_pipe_a4_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 234;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_Rainbow_pipe_a4_mesh_layer_1_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_A_rainbow_road_A5_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 78;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_A_rainbow_road_A5_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_B_dress_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 52;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_B_dress_mesh_layer_5_vtx_1);

	deltaX = (int)(0.20000000298023224 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_B_eyes_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 112;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_B_eyes_mesh_layer_1_vtx_0);

	deltaX = (int)(-0.20000000298023224 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_C_Flower_guide_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_Flower_guide_mesh_layer_5_vtx_0);

	deltaX = (int)(0.20000000298023224 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_C_Flower_guide_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_Flower_guide_001_mesh_layer_5_vtx_0);

	deltaX = (int)(0.20000000298023224 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_C_Flower_guide_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_Flower_guide_002_mesh_layer_5_vtx_0);

	deltaX = (int)(0.20000000298023224 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_C_Flower_guide_003_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_C_Flower_guide_003_mesh_layer_5_vtx_0);

	deltaX = (int)(0.20000000298023224 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_F_Sun_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 86;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_F_Sun_mesh_layer_5_vtx_1);

	deltaX = (int)(-0.20000000298023224 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_A_rainbow_road_A8_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 60;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_A_rainbow_road_A8_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_Rainbow_pipe_a2_002_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 234;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_Rainbow_pipe_a2_002_mesh_layer_1_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_Rainbow_pipe_a2_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_Rainbow_pipe_a2_002_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd_dl_Z_Rainglow_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 22;
	int width = 16 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_Z_Rainglow_mesh_layer_5_vtx_0);

	deltaX = (int)(0.05000000074505806 * 0x20) % width;

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

void scroll_gfx_mat_ddd_dl_Water_A_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_Water_A_layer5);


	shift_s_down(mat, 14, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 14, PACK_TILESIZE(0, 1));
	shift_s(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ddd_dl_Water_B_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_Water_B_layer5);


	shift_s_down(mat, 14, PACK_TILESIZE(0, 1));
	shift_s(mat, 16, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ddd_dl_Sparkles_A_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_Sparkles_A_layer5);


	shift_s_down(mat, 14, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 14, PACK_TILESIZE(0, 1));
	shift_s(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ddd_dl_Sparkles_B_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_Sparkles_B_layer5);


	shift_s_down(mat, 14, PACK_TILESIZE(0, 1));
	shift_s(mat, 16, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ddd_dl_MvsWW_Mario_a2_layer4() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_MvsWW_Mario_a2_layer4);
	static int interval_tex_ddd_dl_MvsWW_Mario_a2_layer4 = 8;
	static int cur_interval_tex_ddd_dl_MvsWW_Mario_a2_layer4 = 8;

	if (--cur_interval_tex_ddd_dl_MvsWW_Mario_a2_layer4 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 128));
		cur_interval_tex_ddd_dl_MvsWW_Mario_a2_layer4 = interval_tex_ddd_dl_MvsWW_Mario_a2_layer4;
	}

};

void scroll_gfx_mat_ddd_dl_MvsWW_Wario_a2_layer4() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_MvsWW_Wario_a2_layer4);
	static int interval_tex_ddd_dl_MvsWW_Wario_a2_layer4 = 8;
	static int cur_interval_tex_ddd_dl_MvsWW_Wario_a2_layer4 = 8;

	if (--cur_interval_tex_ddd_dl_MvsWW_Wario_a2_layer4 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 128));
		cur_interval_tex_ddd_dl_MvsWW_Wario_a2_layer4 = interval_tex_ddd_dl_MvsWW_Wario_a2_layer4;
	}

};

void scroll_gfx_mat_ddd_dl_MvsWW_Mario_a1_layer4() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_MvsWW_Mario_a1_layer4);
	static int interval_tex_ddd_dl_MvsWW_Mario_a1_layer4 = 8;
	static int cur_interval_tex_ddd_dl_MvsWW_Mario_a1_layer4 = 8;

	if (--cur_interval_tex_ddd_dl_MvsWW_Mario_a1_layer4 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 128));
		cur_interval_tex_ddd_dl_MvsWW_Mario_a1_layer4 = interval_tex_ddd_dl_MvsWW_Mario_a1_layer4;
	}

};

void scroll_gfx_mat_ddd_dl_MvsWW_Wario_a1_layer4() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_MvsWW_Wario_a1_layer4);
	static int interval_tex_ddd_dl_MvsWW_Wario_a1_layer4 = 8;
	static int cur_interval_tex_ddd_dl_MvsWW_Wario_a1_layer4 = 8;

	if (--cur_interval_tex_ddd_dl_MvsWW_Wario_a1_layer4 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 128));
		cur_interval_tex_ddd_dl_MvsWW_Wario_a1_layer4 = interval_tex_ddd_dl_MvsWW_Wario_a1_layer4;
	}

};

void scroll_gfx_mat_ddd_dl_MvsWW_Peach_b2_layer4() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_MvsWW_Peach_b2_layer4);
	static int interval_tex_ddd_dl_MvsWW_Peach_b2_layer4 = 8;
	static int cur_interval_tex_ddd_dl_MvsWW_Peach_b2_layer4 = 8;

	if (--cur_interval_tex_ddd_dl_MvsWW_Peach_b2_layer4 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 128));
		cur_interval_tex_ddd_dl_MvsWW_Peach_b2_layer4 = interval_tex_ddd_dl_MvsWW_Peach_b2_layer4;
	}

};

void scroll_gfx_mat_ddd_dl_MvsWW_Peach_b1_layer4() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_MvsWW_Peach_b1_layer4);
	static int interval_tex_ddd_dl_MvsWW_Peach_b1_layer4 = 8;
	static int cur_interval_tex_ddd_dl_MvsWW_Peach_b1_layer4 = 8;

	if (--cur_interval_tex_ddd_dl_MvsWW_Peach_b1_layer4 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 128));
		cur_interval_tex_ddd_dl_MvsWW_Peach_b1_layer4 = interval_tex_ddd_dl_MvsWW_Peach_b1_layer4;
	}

};

void scroll_ddd() {
	scroll_ddd_dl_0_stars_mesh_layer_4_vtx_0();
	scroll_ddd_dl_0_stars_001_mesh_layer_4_vtx_0();
	scroll_ddd_dl_0_stars_002_mesh_layer_4_vtx_0();
	scroll_ddd_dl_0_stars_003_mesh_layer_4_vtx_0();
	scroll_ddd_dl_B_stage_a1_mesh_layer_5_vtx_0();
	scroll_ddd_dl_C_rainbow_pipe_a1_mesh_layer_5_vtx_0();
	scroll_ddd_dl_C_rainbow_pipe_a1_mesh_layer_1_vtx_0();
	scroll_ddd_dl_C_start_line_mesh_layer_5_vtx_0();
	scroll_ddd_dl_C_start_line_mesh_layer_5_vtx_1();
	scroll_ddd_dl_C_start_line_mesh_layer_5_vtx_2();
	scroll_ddd_dl_C_Portal_a1_001_mesh_layer_5_vtx_0();
	scroll_ddd_dl_C_Portal_a1_001_mesh_layer_1_vtx_0();
	scroll_ddd_dl_C_Rainbow_pipe_a1_mesh_layer_1_vtx_0();
	scroll_ddd_dl_C_Rainbow_pipe_a1_mesh_layer_5_vtx_0();
	scroll_ddd_dl_EvoQ_Stage1_Backdrop_mesh_layer_5_vtx_0();
	scroll_ddd_dl_EvoQ_Stage1_water_mesh_layer_5_vtx_0();
	scroll_ddd_dl_EvoQ_stage1_waterfall_mesh_layer_5_vtx_0();
	scroll_ddd_dl_EvoQ_Stage2_water_mesh_layer_5_vtx_0();
	scroll_ddd_dl_EvoQ_Stage2_waterfall_mesh_layer_5_vtx_0();
	scroll_ddd_dl_EvoQ_Stage3_Backdrop_mesh_layer_5_vtx_0();
	scroll_ddd_dl_EvoQ_Stage3_toxic_waste_mesh_layer_5_vtx_0();
	scroll_ddd_dl_EvoQ_Stage3_watefall_mesh_layer_5_vtx_0();
	scroll_ddd_dl_Rainbow_pipe_a2_mesh_layer_1_vtx_0();
	scroll_ddd_dl_Rainbow_pipe_a2_mesh_layer_5_vtx_0();
	scroll_ddd_dl_Rainbow_pipe_a2_001_mesh_layer_5_vtx_0();
	scroll_ddd_dl_Rainbow_pipe_a2_001_mesh_layer_1_vtx_0();
	scroll_ddd_dl_Rainbow_road_a2_mesh_layer_5_vtx_0();
	scroll_ddd_dl_Rainbow_pipe_a3_mesh_layer_1_vtx_0();
	scroll_ddd_dl_Rainbow_pipe_a3_mesh_layer_5_vtx_0();
	scroll_ddd_dl_Rainbow_pipe_a3_001_mesh_layer_5_vtx_0();
	scroll_ddd_dl_Rainbow_pipe_a3_001_mesh_layer_1_vtx_0();
	scroll_ddd_dl_0_stars_004_mesh_layer_4_vtx_0();
	scroll_ddd_dl_0_stars_005_mesh_layer_4_vtx_0();
	scroll_ddd_dl_0_stars_006_mesh_layer_4_vtx_0();
	scroll_ddd_dl_0_stars_007_mesh_layer_4_vtx_0();
	scroll_ddd_dl_A_MvsWW_a4_mesh_layer_5_vtx_0();
	scroll_ddd_dl_A_MvsWW_a4_backdrop_mesh_layer_5_vtx_0();
	scroll_ddd_dl_C_Rainbow_pipe_a4_mesh_layer_5_vtx_0();
	scroll_ddd_dl_C_Rainbow_pipe_a4_mesh_layer_1_vtx_0();
	scroll_ddd_dl_A_rainbow_road_A5_mesh_layer_5_vtx_0();
	scroll_ddd_dl_B_dress_mesh_layer_5_vtx_1();
	scroll_ddd_dl_B_eyes_mesh_layer_1_vtx_0();
	scroll_ddd_dl_C_Flower_guide_mesh_layer_5_vtx_0();
	scroll_ddd_dl_C_Flower_guide_001_mesh_layer_5_vtx_0();
	scroll_ddd_dl_C_Flower_guide_002_mesh_layer_5_vtx_0();
	scroll_ddd_dl_C_Flower_guide_003_mesh_layer_5_vtx_0();
	scroll_ddd_dl_F_Sun_mesh_layer_5_vtx_1();
	scroll_ddd_dl_A_rainbow_road_A8_mesh_layer_5_vtx_0();
	scroll_ddd_dl_Rainbow_pipe_a2_002_mesh_layer_1_vtx_0();
	scroll_ddd_dl_Rainbow_pipe_a2_002_mesh_layer_5_vtx_0();
	scroll_ddd_dl_Z_Rainglow_mesh_layer_5_vtx_0();
	scroll_gfx_mat_ddd_dl_Dot_lights();
	scroll_gfx_mat_ddd_dl_Water_A_layer5();
	scroll_gfx_mat_ddd_dl_Water_B_layer5();
	scroll_gfx_mat_ddd_dl_Sparkles_A_layer5();
	scroll_gfx_mat_ddd_dl_Sparkles_B_layer5();
	scroll_gfx_mat_ddd_dl_MvsWW_Mario_a2_layer4();
	scroll_gfx_mat_ddd_dl_MvsWW_Wario_a2_layer4();
	scroll_gfx_mat_ddd_dl_MvsWW_Mario_a1_layer4();
	scroll_gfx_mat_ddd_dl_MvsWW_Wario_a1_layer4();
	scroll_gfx_mat_ddd_dl_MvsWW_Peach_b2_layer4();
	scroll_gfx_mat_ddd_dl_MvsWW_Peach_b1_layer4();
};
