void scroll_ccm_dl_A_Road_a_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 458;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_Road_a_mesh_layer_1_vtx_2);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_A_Road_b_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 2296;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_Road_b_mesh_layer_1_vtx_2);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_A_Road_c_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 1048;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_Road_c_mesh_layer_1_vtx_1);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_C_railings_a_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 172;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_C_railings_a_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_C_start_line_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_C_start_line_mesh_layer_5_vtx_0);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_C_start_line_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 24;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_C_start_line_mesh_layer_5_vtx_1);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_C_start_line_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 10;
	int width = 128 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_C_start_line_mesh_layer_5_vtx_2);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_C_railings_b_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 258;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_C_railings_b_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_C_railings_c_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 172;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_C_railings_c_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_C_railings_d_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 258;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_C_railings_d_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_D_star_gate_a1_2_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 216;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_D_star_gate_a1_2_mesh_layer_1_vtx_1);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_A_area1_wormhole_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 272;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_area1_wormhole_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_area1_wormhole_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 264;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_area1_wormhole_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_area1_wormhole_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 264;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_area1_wormhole_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_area1_wormhole_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 272;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_area1_wormhole_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_area1_wormhole_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_area1_wormhole_mesh_layer_5_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_area1_wormhole_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_area1_wormhole_mesh_layer_5_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_area1_wormhole_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_area1_wormhole_mesh_layer_5_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_area1_wormhole_mesh_layer_5_vtx_3() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_area1_wormhole_mesh_layer_5_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_C_railings_d_a1_3_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 258;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_C_railings_d_a1_3_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_D_star_gate_a_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 80;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_D_star_gate_a_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_D_star_gate_b_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 80;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_D_star_gate_b_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_D_star_gate_c_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 80;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_D_star_gate_c_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_D_star_gate_d_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 80;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_D_star_gate_d_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_D_star_gate_e_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 80;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_D_star_gate_e_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_D_star_gate_f_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 80;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_D_star_gate_f_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_D_star_gate_g_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 80;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_D_star_gate_g_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_D_star_gate_h_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 80;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_D_star_gate_h_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_D_star_gate_i_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 80;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_D_star_gate_i_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_A_wormhole_a1_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 168;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a1_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a1_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 168;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a1_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a1_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 168;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a1_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a1_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 168;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a1_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a1_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a1_mesh_layer_5_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a1_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a1_mesh_layer_5_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a1_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a1_mesh_layer_5_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a1_mesh_layer_5_vtx_3() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a1_mesh_layer_5_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a2_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a2_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a2_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a2_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a2_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a2_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a2_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a2_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 120;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 120;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 120;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 120;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 184;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 184;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 184;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 184;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_mesh_layer_5_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_mesh_layer_5_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_mesh_layer_5_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_mesh_layer_5_vtx_3() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_mesh_layer_5_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b1_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 208;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b1_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b1_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 208;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b1_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b1_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 208;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b1_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b1_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 208;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b1_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b2_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 120;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b2_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b2_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 120;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b2_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b2_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 120;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b2_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b2_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 122;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b2_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b3_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b3_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b3_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b3_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b3_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b3_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b3_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b3_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b4_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 192;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b4_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b4_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 192;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b4_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b4_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 192;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b4_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_b4_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 192;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_b4_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c1_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 200;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c1_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c1_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 200;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c1_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c1_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 200;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c1_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c1_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 200;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c1_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c1_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c1_mesh_layer_5_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c1_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c1_mesh_layer_5_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c1_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c1_mesh_layer_5_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c1_mesh_layer_5_vtx_3() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c1_mesh_layer_5_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c2_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c2_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c2_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c2_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c2_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c2_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c2_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c2_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c3_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c3_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c3_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c3_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c3_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c3_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c3_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 104;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c3_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c4_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 168;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c4_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c4_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 168;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c4_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c4_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 168;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c4_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c4_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 168;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c4_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c4_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c4_mesh_layer_5_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c4_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c4_mesh_layer_5_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c4_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c4_mesh_layer_5_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_c4_mesh_layer_5_vtx_3() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_c4_mesh_layer_5_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_a3_skybox_a_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 71;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_a3_skybox_a_mesh_layer_1_vtx_0);

	deltaY = (int)(-0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_a3_skybox_b_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 71;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_a3_skybox_b_mesh_layer_1_vtx_0);

	deltaY = (int)(-0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_a3_skybox_c_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 71;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_a3_skybox_c_mesh_layer_1_vtx_0);

	deltaY = (int)(-0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_a3_skybox_d_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 76;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_a3_skybox_d_mesh_layer_1_vtx_0);

	deltaY = (int)(-0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3a_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 184;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3a_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3a_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 184;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3a_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3a_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 184;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3a_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3a_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 184;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3a_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3a_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3a_mesh_layer_5_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3a_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3a_mesh_layer_5_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3a_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3a_mesh_layer_5_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3a_mesh_layer_5_vtx_3() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3a_mesh_layer_5_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_D_star_gate_a3_a_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 400;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_D_star_gate_a3_a_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_D_star_gate_a3_b_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 80;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_D_star_gate_a3_b_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_D_star_gate_a3_c_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 80;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_D_star_gate_a3_c_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_A_wormhole_a3c_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 18;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3c_mesh_layer_5_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3c_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3c_mesh_layer_5_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3c_mesh_layer_5_vtx_3() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3c_mesh_layer_5_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3c_mesh_layer_5_vtx_4() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3c_mesh_layer_5_vtx_4);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3c_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 272;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3c_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3c_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 268;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3c_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3c_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 270;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3c_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3c_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 268;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3c_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3b_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 18;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3b_mesh_layer_5_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3b_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3b_mesh_layer_5_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3b_mesh_layer_5_vtx_3() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3b_mesh_layer_5_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3b_mesh_layer_5_vtx_4() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3b_mesh_layer_5_vtx_4);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3b_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 272;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3b_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3b_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 272;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3b_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3b_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 272;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3b_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a3b_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 272;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a3b_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_0_stars_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 56;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_0_stars_mesh_layer_4_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_0_stars_001_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 48;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_0_stars_001_mesh_layer_4_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_0_stars_002_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 56;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_0_stars_002_mesh_layer_4_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_0_stars_003_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 62;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_0_stars_003_mesh_layer_4_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 408;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 200;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 408;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 200;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_4() {
	int i = 0;
	int count = 208;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_4);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_5() {
	int i = 0;
	int count = 208;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_5);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 18;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_a_mesh_layer_5_vtx_0);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_a_mesh_layer_5_vtx_1);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_5_vtx_2() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_a_mesh_layer_5_vtx_2);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_5_vtx_3() {
	int i = 0;
	int count = 16;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_A_wormhole_a4_a_mesh_layer_5_vtx_3);

	deltaY = (int)(2.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ccm_dl_B_planet_f_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 256;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_B_planet_f_mesh_layer_1_vtx_1);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_B_planet_g_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 256;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_B_planet_g_mesh_layer_1_vtx_1);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_gfx_mat_ccm_dl_Starry_floor_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Starry_floor_layer1);

	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_t(mat, 10, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ccm_dl_Starry_tiles_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Starry_tiles_layer1);

	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_t(mat, 10, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ccm_dl_Billboard_g2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_g2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_f2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_f2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_f1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_f1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_g1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_g1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_h1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_h1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_h2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_h2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_c1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_c1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_c2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_c2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_b1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_b1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_b2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_b2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_a2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_a2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_a1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_a1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_i1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_i1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_i2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_i2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_d1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_d1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_d2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_d2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_e1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_e1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Billboard_e2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_e2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 3));

};

void scroll_gfx_mat_ccm_dl_Star_projection_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Star_projection_layer5);

	static int interval_tex_ccm_dl_Star_projection_layer5 = 8;
	static int cur_interval_tex_ccm_dl_Star_projection_layer5 = 8;
	shift_t_down(mat, 10, PACK_TILESIZE(0, 3));

	if (--cur_interval_tex_ccm_dl_Star_projection_layer5 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 64));
		cur_interval_tex_ccm_dl_Star_projection_layer5 = interval_tex_ccm_dl_Star_projection_layer5;
	}

};

void scroll_gfx_mat_ccm_dl_Wormhole_platform_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Wormhole_platform_layer5);


	shift_t_down(mat, 10, PACK_TILESIZE(0, 3));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ccm_dl_Wormhole_crosses_layer4() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Wormhole_crosses_layer4);

	shift_t(mat, 15, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ccm_dl_Wormhole_platform_2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Wormhole_platform_2_layer5);


	shift_t_down(mat, 10, PACK_TILESIZE(0, 3));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ccm_dl_Star_pattern_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Star_pattern_layer5);

	shift_t_down(mat, 10, PACK_TILESIZE(0, 3));

};

void scroll_ccm() {
	scroll_ccm_dl_A_Road_a_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_Road_b_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_Road_c_mesh_layer_1_vtx_1();
	scroll_ccm_dl_C_railings_a_mesh_layer_1_vtx_0();
	scroll_ccm_dl_C_start_line_mesh_layer_5_vtx_0();
	scroll_ccm_dl_C_start_line_mesh_layer_5_vtx_1();
	scroll_ccm_dl_C_start_line_mesh_layer_5_vtx_2();
	scroll_ccm_dl_C_railings_b_mesh_layer_1_vtx_0();
	scroll_ccm_dl_C_railings_c_mesh_layer_1_vtx_0();
	scroll_ccm_dl_C_railings_d_mesh_layer_1_vtx_0();
	scroll_ccm_dl_D_star_gate_a1_2_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_area1_wormhole_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_area1_wormhole_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_area1_wormhole_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_area1_wormhole_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_area1_wormhole_mesh_layer_5_vtx_0();
	scroll_ccm_dl_A_area1_wormhole_mesh_layer_5_vtx_1();
	scroll_ccm_dl_A_area1_wormhole_mesh_layer_5_vtx_2();
	scroll_ccm_dl_A_area1_wormhole_mesh_layer_5_vtx_3();
	scroll_ccm_dl_C_railings_d_a1_3_mesh_layer_1_vtx_0();
	scroll_ccm_dl_D_star_gate_a_mesh_layer_1_vtx_0();
	scroll_ccm_dl_D_star_gate_b_mesh_layer_1_vtx_0();
	scroll_ccm_dl_D_star_gate_c_mesh_layer_1_vtx_0();
	scroll_ccm_dl_D_star_gate_d_mesh_layer_1_vtx_0();
	scroll_ccm_dl_D_star_gate_e_mesh_layer_1_vtx_0();
	scroll_ccm_dl_D_star_gate_f_mesh_layer_1_vtx_0();
	scroll_ccm_dl_D_star_gate_g_mesh_layer_1_vtx_0();
	scroll_ccm_dl_D_star_gate_h_mesh_layer_1_vtx_0();
	scroll_ccm_dl_D_star_gate_i_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_a1_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_a1_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_a1_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_a1_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_a1_mesh_layer_5_vtx_0();
	scroll_ccm_dl_A_wormhole_a1_mesh_layer_5_vtx_1();
	scroll_ccm_dl_A_wormhole_a1_mesh_layer_5_vtx_2();
	scroll_ccm_dl_A_wormhole_a1_mesh_layer_5_vtx_3();
	scroll_ccm_dl_A_wormhole_a2_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_a2_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_a2_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_a2_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_a3_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_a3_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_a3_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_a3_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_a4_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_a4_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_a4_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_a4_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_a4_mesh_layer_5_vtx_0();
	scroll_ccm_dl_A_wormhole_a4_mesh_layer_5_vtx_1();
	scroll_ccm_dl_A_wormhole_a4_mesh_layer_5_vtx_2();
	scroll_ccm_dl_A_wormhole_a4_mesh_layer_5_vtx_3();
	scroll_ccm_dl_A_wormhole_b1_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_b1_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_b1_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_b1_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_b2_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_b2_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_b2_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_b2_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_b3_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_b3_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_b3_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_b3_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_b4_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_b4_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_b4_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_b4_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_c1_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_c1_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_c1_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_c1_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_c1_mesh_layer_5_vtx_0();
	scroll_ccm_dl_A_wormhole_c1_mesh_layer_5_vtx_1();
	scroll_ccm_dl_A_wormhole_c1_mesh_layer_5_vtx_2();
	scroll_ccm_dl_A_wormhole_c1_mesh_layer_5_vtx_3();
	scroll_ccm_dl_A_wormhole_c2_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_c2_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_c2_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_c2_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_c3_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_c3_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_c3_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_c3_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_c4_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_c4_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_c4_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_c4_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_c4_mesh_layer_5_vtx_0();
	scroll_ccm_dl_A_wormhole_c4_mesh_layer_5_vtx_1();
	scroll_ccm_dl_A_wormhole_c4_mesh_layer_5_vtx_2();
	scroll_ccm_dl_A_wormhole_c4_mesh_layer_5_vtx_3();
	scroll_ccm_dl_a3_skybox_a_mesh_layer_1_vtx_0();
	scroll_ccm_dl_a3_skybox_b_mesh_layer_1_vtx_0();
	scroll_ccm_dl_a3_skybox_c_mesh_layer_1_vtx_0();
	scroll_ccm_dl_a3_skybox_d_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_a3a_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_a3a_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_a3a_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_a3a_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_a3a_mesh_layer_5_vtx_0();
	scroll_ccm_dl_A_wormhole_a3a_mesh_layer_5_vtx_1();
	scroll_ccm_dl_A_wormhole_a3a_mesh_layer_5_vtx_2();
	scroll_ccm_dl_A_wormhole_a3a_mesh_layer_5_vtx_3();
	scroll_ccm_dl_D_star_gate_a3_a_mesh_layer_1_vtx_0();
	scroll_ccm_dl_D_star_gate_a3_b_mesh_layer_1_vtx_0();
	scroll_ccm_dl_D_star_gate_a3_c_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_a3c_mesh_layer_5_vtx_1();
	scroll_ccm_dl_A_wormhole_a3c_mesh_layer_5_vtx_2();
	scroll_ccm_dl_A_wormhole_a3c_mesh_layer_5_vtx_3();
	scroll_ccm_dl_A_wormhole_a3c_mesh_layer_5_vtx_4();
	scroll_ccm_dl_A_wormhole_a3c_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_a3c_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_a3c_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_a3c_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_a3b_mesh_layer_5_vtx_1();
	scroll_ccm_dl_A_wormhole_a3b_mesh_layer_5_vtx_2();
	scroll_ccm_dl_A_wormhole_a3b_mesh_layer_5_vtx_3();
	scroll_ccm_dl_A_wormhole_a3b_mesh_layer_5_vtx_4();
	scroll_ccm_dl_A_wormhole_a3b_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_a3b_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_a3b_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_a3b_mesh_layer_1_vtx_3();
	scroll_ccm_dl_0_stars_mesh_layer_4_vtx_0();
	scroll_ccm_dl_0_stars_001_mesh_layer_4_vtx_0();
	scroll_ccm_dl_0_stars_002_mesh_layer_4_vtx_0();
	scroll_ccm_dl_0_stars_003_mesh_layer_4_vtx_0();
	scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_0();
	scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_1();
	scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_3();
	scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_4();
	scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_1_vtx_5();
	scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_5_vtx_0();
	scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_5_vtx_1();
	scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_5_vtx_2();
	scroll_ccm_dl_A_wormhole_a4_a_mesh_layer_5_vtx_3();
	scroll_ccm_dl_B_planet_f_mesh_layer_1_vtx_1();
	scroll_ccm_dl_B_planet_g_mesh_layer_1_vtx_1();
	scroll_gfx_mat_ccm_dl_Starry_floor_layer1();
	scroll_gfx_mat_ccm_dl_Starry_tiles_layer1();
	scroll_gfx_mat_ccm_dl_Billboard_g2_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_f2_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_f1_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_g1_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_h1_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_h2_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_c1_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_c2_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_b1_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_b2_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_a2_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_a1_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_i1_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_i2_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_d1_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_d2_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_e1_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_e2_layer5();
	scroll_gfx_mat_ccm_dl_Star_projection_layer5();
	scroll_gfx_mat_ccm_dl_Wormhole_platform_layer5();
	scroll_gfx_mat_ccm_dl_Wormhole_crosses_layer4();
	scroll_gfx_mat_ccm_dl_Wormhole_platform_2_layer5();
	scroll_gfx_mat_ccm_dl_Star_pattern_layer5();
};
