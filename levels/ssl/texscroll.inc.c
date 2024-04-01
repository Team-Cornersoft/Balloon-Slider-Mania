void scroll_ssl_dl_0_SKYBOX_a_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 82;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_0_SKYBOX_a_mesh_layer_1_vtx_0);

	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_0_SKYBOX_a_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 82;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_0_SKYBOX_a_001_mesh_layer_1_vtx_0);

	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_0_SKYBOX_b_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 82;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_0_SKYBOX_b_mesh_layer_1_vtx_0);

	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_0_SKYBOX_b_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 82;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_0_SKYBOX_b_001_mesh_layer_1_vtx_0);

	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_0_SKYBOX_c_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 82;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_0_SKYBOX_c_mesh_layer_1_vtx_0);

	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_0_SKYBOX_c_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 82;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_0_SKYBOX_c_001_mesh_layer_1_vtx_0);

	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_0_SKYBOX_d_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 82;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_0_SKYBOX_d_mesh_layer_1_vtx_0);

	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_0_SKYBOX_d_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 82;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_0_SKYBOX_d_001_mesh_layer_1_vtx_0);

	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_A_Road_a_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 36;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_Road_a_mesh_layer_1_vtx_0);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_A_Road_a_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 295;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_Road_a_mesh_layer_1_vtx_2);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_A_Road_b_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 90;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_Road_b_mesh_layer_1_vtx_0);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_A_Road_b_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 692;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_Road_b_mesh_layer_1_vtx_3);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_A_Road_c_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 122;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_Road_c_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_A_Road_c_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 12;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_Road_c_mesh_layer_1_vtx_1);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_C_start_line_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_C_start_line_mesh_layer_5_vtx_0);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_C_start_line_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 24;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_C_start_line_mesh_layer_5_vtx_1);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_C_start_line_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 10;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_C_start_line_mesh_layer_5_vtx_2);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_StaR_road_a3_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 278;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_StaR_road_a3_mesh_layer_5_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_StaR_road_a3_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 271;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_StaR_road_a3_001_mesh_layer_5_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_StaR_road_a3_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 271;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_StaR_road_a3_002_mesh_layer_5_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_StaR_road_a3_003_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 271;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_StaR_road_a3_003_mesh_layer_5_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_StaR_road_a3_004_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 271;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_StaR_road_a3_004_mesh_layer_5_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_StaR_road_a3_005_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 271;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_StaR_road_a3_005_mesh_layer_5_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_0_stars_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 56;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_0_stars_mesh_layer_5_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_0_stars_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 48;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_0_stars_001_mesh_layer_5_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_0_stars_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 56;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_0_stars_002_mesh_layer_5_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_0_stars_003_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 62;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_0_stars_003_mesh_layer_5_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 384;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 200;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 384;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 200;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_4() {
	int i = 0;
	int count = 184;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_4);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_5() {
	int i = 0;
	int count = 184;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_5);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 36;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 32;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_3() {
	int i = 0;
	int count = 32;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_5() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_5);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_B_planet_f_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 256;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_B_planet_f_mesh_layer_1_vtx_1);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_B_planet_f_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 36;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_B_planet_f_mesh_layer_1_vtx_2);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ssl_dl_B_planet_g_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 256;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_B_planet_g_mesh_layer_1_vtx_1);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_B_planet_g_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 36;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_B_planet_g_mesh_layer_1_vtx_2);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_mat_ssl_dl_Cyber_floor_2_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Cyber_floor_2_layer1);
	static int interval_tex_ssl_dl_Cyber_floor_2_layer1 = 4;
	static int cur_interval_tex_ssl_dl_Cyber_floor_2_layer1 = 4;


	if (--cur_interval_tex_ssl_dl_Cyber_floor_2_layer1 <= 0) {
		shift_s(mat, 11, PACK_TILESIZE(0, 96));
		shift_t(mat, 11, PACK_TILESIZE(0, 192));
		cur_interval_tex_ssl_dl_Cyber_floor_2_layer1 = interval_tex_ssl_dl_Cyber_floor_2_layer1;
	}
	shift_s_down(mat, 16, PACK_TILESIZE(0, 96));
	shift_t(mat, 16, PACK_TILESIZE(0, 192));

};

void scroll_gfx_mat_ssl_dl_Cyber_floor_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Cyber_floor_layer1);
	static int interval_tex_ssl_dl_Cyber_floor_layer1 = 4;
	static int cur_interval_tex_ssl_dl_Cyber_floor_layer1 = 4;


	if (--cur_interval_tex_ssl_dl_Cyber_floor_layer1 <= 0) {
		shift_s(mat, 11, PACK_TILESIZE(0, 96));
		shift_t(mat, 11, PACK_TILESIZE(0, 192));
		cur_interval_tex_ssl_dl_Cyber_floor_layer1 = interval_tex_ssl_dl_Cyber_floor_layer1;
	}
	shift_s_down(mat, 16, PACK_TILESIZE(0, 96));
	shift_t(mat, 16, PACK_TILESIZE(0, 192));

};

void scroll_gfx_mat_ssl_dl_Planet_projection_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Planet_projection_layer5);


	shift_t_down(mat, 10, PACK_TILESIZE(0, 3));
	shift_s(mat, 15, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ssl_dl_Building_plus_window() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Building_plus_window);
	static int interval_tex_ssl_dl_Building_plus_window = 8;
	static int cur_interval_tex_ssl_dl_Building_plus_window = 8;

	if (--cur_interval_tex_ssl_dl_Building_plus_window <= 0) {
		shift_s(mat, 9, PACK_TILESIZE(0, 192));
		shift_t(mat, 9, PACK_TILESIZE(0, 64));
		cur_interval_tex_ssl_dl_Building_plus_window = interval_tex_ssl_dl_Building_plus_window;
	}

};

void scroll_gfx_mat_ssl_dl_Billboard_b1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_b1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_b2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_b2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_a2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_a2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_a1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_a1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_g2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_g2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_f2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_f2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_f1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_f1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_g1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_g1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_h1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_h1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_h2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_h2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_c1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_c1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_c2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_c2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_i2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_i2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_i1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_i1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_e2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_e2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_e1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_e1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_d2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_d2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Billboard_d1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Billboard_d1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ssl_dl_Star_projection_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Star_projection_layer5);

	static int interval_tex_ssl_dl_Star_projection_layer5 = 8;
	static int cur_interval_tex_ssl_dl_Star_projection_layer5 = 8;
	shift_t_down(mat, 10, PACK_TILESIZE(0, 3));

	if (--cur_interval_tex_ssl_dl_Star_projection_layer5 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 64));
		cur_interval_tex_ssl_dl_Star_projection_layer5 = interval_tex_ssl_dl_Star_projection_layer5;
	}

};

void scroll_gfx_mat_ssl_dl_Wormhole_platform_2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Wormhole_platform_2_layer5);


	shift_t_down(mat, 10, PACK_TILESIZE(0, 3));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ssl_dl_Wormhole_crosses_layer4() {
	Gfx *mat = segmented_to_virtual(mat_ssl_dl_Wormhole_crosses_layer4);

	shift_t(mat, 15, PACK_TILESIZE(0, 1));

};

void scroll_ssl() {
	scroll_ssl_dl_0_SKYBOX_a_mesh_layer_1_vtx_0();
	scroll_ssl_dl_0_SKYBOX_a_001_mesh_layer_1_vtx_0();
	scroll_ssl_dl_0_SKYBOX_b_mesh_layer_1_vtx_0();
	scroll_ssl_dl_0_SKYBOX_b_001_mesh_layer_1_vtx_0();
	scroll_ssl_dl_0_SKYBOX_c_mesh_layer_1_vtx_0();
	scroll_ssl_dl_0_SKYBOX_c_001_mesh_layer_1_vtx_0();
	scroll_ssl_dl_0_SKYBOX_d_mesh_layer_1_vtx_0();
	scroll_ssl_dl_0_SKYBOX_d_001_mesh_layer_1_vtx_0();
	scroll_ssl_dl_A_Road_a_mesh_layer_1_vtx_0();
	scroll_ssl_dl_A_Road_a_mesh_layer_1_vtx_2();
	scroll_ssl_dl_A_Road_b_mesh_layer_1_vtx_0();
	scroll_ssl_dl_A_Road_b_mesh_layer_1_vtx_3();
	scroll_ssl_dl_A_Road_c_mesh_layer_1_vtx_0();
	scroll_ssl_dl_A_Road_c_mesh_layer_1_vtx_1();
	scroll_ssl_dl_C_start_line_mesh_layer_5_vtx_0();
	scroll_ssl_dl_C_start_line_mesh_layer_5_vtx_1();
	scroll_ssl_dl_C_start_line_mesh_layer_5_vtx_2();
	scroll_ssl_dl_StaR_road_a3_mesh_layer_5_vtx_0();
	scroll_ssl_dl_StaR_road_a3_001_mesh_layer_5_vtx_0();
	scroll_ssl_dl_StaR_road_a3_002_mesh_layer_5_vtx_0();
	scroll_ssl_dl_StaR_road_a3_003_mesh_layer_5_vtx_0();
	scroll_ssl_dl_StaR_road_a3_004_mesh_layer_5_vtx_0();
	scroll_ssl_dl_StaR_road_a3_005_mesh_layer_5_vtx_0();
	scroll_ssl_dl_0_stars_mesh_layer_5_vtx_0();
	scroll_ssl_dl_0_stars_001_mesh_layer_5_vtx_0();
	scroll_ssl_dl_0_stars_002_mesh_layer_5_vtx_0();
	scroll_ssl_dl_0_stars_003_mesh_layer_5_vtx_0();
	scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_0();
	scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_1();
	scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_2();
	scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_3();
	scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_4();
	scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_1_vtx_5();
	scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_0();
	scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_1();
	scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_2();
	scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_3();
	scroll_ssl_dl_A_wormhole_a4_a_mesh_layer_5_vtx_5();
	scroll_ssl_dl_B_planet_f_mesh_layer_1_vtx_1();
	scroll_ssl_dl_B_planet_f_mesh_layer_1_vtx_2();
	scroll_ssl_dl_B_planet_g_mesh_layer_1_vtx_1();
	scroll_ssl_dl_B_planet_g_mesh_layer_1_vtx_2();
	scroll_gfx_mat_ssl_dl_Cyber_floor_2_layer1();
	scroll_gfx_mat_ssl_dl_Cyber_floor_layer1();
	scroll_gfx_mat_ssl_dl_Planet_projection_layer5();
	scroll_gfx_mat_ssl_dl_Building_plus_window();
	scroll_gfx_mat_ssl_dl_Billboard_b1_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_b2_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_a2_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_a1_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_g2_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_f2_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_f1_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_g1_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_h1_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_h2_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_c1_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_c2_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_i2_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_i1_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_e2_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_e1_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_d2_layer5();
	scroll_gfx_mat_ssl_dl_Billboard_d1_layer5();
	scroll_gfx_mat_ssl_dl_Star_projection_layer5();
	scroll_gfx_mat_ssl_dl_Wormhole_platform_2_layer5();
	scroll_gfx_mat_ssl_dl_Wormhole_crosses_layer4();
};
