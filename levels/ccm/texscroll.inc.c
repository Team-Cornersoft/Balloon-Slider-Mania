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

void scroll_ccm_dl_D_star_gate_a1_2_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 84;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_D_star_gate_a1_2_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
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
	int count = 44;
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
	int count = 44;
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
	int count = 44;
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
	int count = 44;
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
	int count = 44;
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
	int count = 44;
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
	int count = 44;
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
	int count = 44;
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
	int count = 44;
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

void scroll_gfx_mat_ccm_dl_Starry_floor_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Starry_floor_layer1);

	shift_s(mat, 9, PACK_TILESIZE(0, 1));
	shift_t(mat, 9, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ccm_dl_Starry_tiles_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Starry_tiles_layer1);

	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_t(mat, 10, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_ccm_dl_Billboard_g2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_g2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_f2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_f2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_f1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_f1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_g1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_g1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_h1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_h1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_h2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_h2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_c1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_c1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_c2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_c2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_b1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_b1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_b2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_b2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_a2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_a2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_a1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_a1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_i1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_i1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_i2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_i2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_d1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_d1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_d2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_d2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Star_projection_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Star_projection_layer5);

	static int interval_tex_ccm_dl_Star_projection_layer5 = 8;
	static int cur_interval_tex_ccm_dl_Star_projection_layer5 = 8;
	shift_t_down(mat, 10, PACK_TILESIZE(0, 2));

	if (--cur_interval_tex_ccm_dl_Star_projection_layer5 <= 0) {
		shift_s(mat, 15, PACK_TILESIZE(0, 64));
		cur_interval_tex_ccm_dl_Star_projection_layer5 = interval_tex_ccm_dl_Star_projection_layer5;
	}

};

void scroll_gfx_mat_ccm_dl_Billboard_e2_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_e2_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_ccm_dl_Billboard_e1_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_Billboard_e1_layer5);

	shift_t_down(mat, 14, PACK_TILESIZE(0, 2));

};

void scroll_ccm() {
	scroll_ccm_dl_A_Road_a_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_Road_b_mesh_layer_1_vtx_2();
	scroll_ccm_dl_A_Road_c_mesh_layer_1_vtx_1();
	scroll_ccm_dl_C_railings_a_mesh_layer_1_vtx_0();
	scroll_ccm_dl_C_railings_b_mesh_layer_1_vtx_0();
	scroll_ccm_dl_C_railings_c_mesh_layer_1_vtx_0();
	scroll_ccm_dl_C_railings_d_mesh_layer_1_vtx_0();
	scroll_ccm_dl_D_star_gate_a1_2_mesh_layer_1_vtx_0();
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
	scroll_gfx_mat_ccm_dl_Star_projection_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_e2_layer5();
	scroll_gfx_mat_ccm_dl_Billboard_e1_layer5();
};
