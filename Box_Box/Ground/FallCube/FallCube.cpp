#include "FallCube.h"

FallCube::FallCube(){
#pragma region ���_���W
	// �����̂̒��_���W���w��--------------------------------------------------------
	Vec3f vertices[] = {
		// ��O�̖�
		{ -1, -1, -1 }, { 1, 1, -1 }, { 1, -1, -1 },
		{ -1, -1, -1 }, { -1, 1, -1 }, { 1, 1, -1 },

		// ��̖�
		{ -1, 1, -1 }, { -1, 1, 1 }, { 1, 1, 1 },
		{ -1, 1, -1 }, { 1, 1, 1 }, { 1, 1, -1 },

		{ 1, -1, -1 }, { 1, 1, -1 }, { 1, 1, 1 },
		{ 1, -1, -1 }, { 1, 1, 1 }, { 1, -1, 1 },

		{ -1, -1, -1 }, { -1, -1, 1 }, { -1, 1, 1 },
		{ -1, -1, -1 }, { -1, 1, 1 }, { -1, 1, -1 },

		{ -1, -1, -1 }, { 1, -1, 1 }, { -1, -1, 1 },
		{ -1, -1, -1 }, { 1, -1, -1 }, { 1, -1, 1 },

		{ 1, 1, 1 }, { -1, 1, 1 }, { -1, -1, 1 },
		{ 1, 1, 1 }, { -1, -1, 1 }, { 1, -1, 1 },
	};
	c_mesh.appendVertices(&vertices[0], sizeof(vertices) / sizeof(vertices[0]));

	// �e�̕\���͈�ʂ����ŗǂ��̂ŕʂɗp��
	Vec3f shadow_vertices[] = {
		{ -1, 1, -1 }, { -1, 1, 1 }, { 1, 1, 1 },
		{ -1, 1, -1 }, { 1, 1, 1 }, { 1, 1, -1 },
	};
	shadow_mesh.appendVertices(&shadow_vertices[0], sizeof(shadow_vertices) / sizeof(shadow_vertices[0]));
#pragma endregion

#pragma region �F�w��
	// ���_��(��)�̐F���w��(�v���C���[)--------------------------------------------------------
	Color colors[] = {
		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },
		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },

		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },
		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },

		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },
		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },

		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },
		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },

		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },
		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },

		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },
		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },
	};
	c_mesh.appendColorsRgb(&colors[0], sizeof(colors) / sizeof(colors[0]));

	// �e�̐F
	Color shadow_colors[] = {
		{ 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
		{ 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
	};
	shadow_mesh.appendColorsRgb(&shadow_colors[0], sizeof(shadow_colors) / sizeof(shadow_colors[0]));
#pragma endregion

#pragma region ���_�ԍ�
	// ���_�ɔԍ�������U��--------------------------------------------------------
	uint32_t box_indices[] = {
		0, 1, 2,
		3, 4, 5,

		6, 7, 8,
		9, 10, 11,

		12, 13, 14,
		15, 16, 17,

		18, 19, 20,
		21, 22, 23,

		24, 25, 26,
		27, 28, 29,

		30, 31, 32,
		33, 34, 35,
	};
	c_mesh.appendIndices(&box_indices[0], sizeof(box_indices) / sizeof(box_indices[0]));

	// �e�̒��_�ԍ�
	uint32_t shadow_indices[] = {
		0, 1, 2,
		3, 4, 5,
	};
	shadow_mesh.appendIndices(&shadow_indices[0], sizeof(shadow_indices) / sizeof(shadow_indices[0]));
#pragma endregion

	c_mesh.recalculateNormals();

	gravity = 0.5f;

	for (int x = 0; x < 2; x++){
		for (int z = 0; z < 1; z++){
			float pos_x = -45;
			float pos_z = -45;
			cube.push_back({ c_mesh, shadow_mesh, Vec3f(pos_x + 20 * x, randFloat(100.0f, 1000.0f), pos_z + 20 * z), Vec3f(10.0f, 10.0f, 10.0f), 0.0f, Color(1, 0, 0), 0 });
		}
	}
}


#pragma region �X�V����
void FallCube::update(){
	for (auto& CUBE : cube){
		// �L���[�u�̗���
		if (CUBE.pos.y > 15.0f + ((CUBE.size.y * 2)*CUBE.steps)){
			CUBE.flash_color.g += 0.1;
			CUBE.flash_color.b += 0.1;
			CUBE.pos.y -= gravity;
		}
		// ground �ɒ��������~
		else{
			CUBE.pos.y = 15.0f;
		}


		// �e�̑傫���𐧌�
		if (CUBE.pos.y < 300.0f + ((CUBE.size.y * 2)*CUBE.steps) && CUBE.pos.y > 15.0f + ((CUBE.size.y * 2)*CUBE.steps)) {
			CUBE.shadow_width += 10.0f / (285.0f * 2.0f);
		}
		else if (CUBE.pos.y == 15.0f + ((CUBE.size.y * 2)*CUBE.steps)){
			CUBE.shadow_width = 10;
		}
	}
}
#pragma endregion


#pragma region �`�揈��
void FallCube::draw(){
	for (auto CUBE : cube){
		auto pos = CUBE.pos;
		auto mesh = CUBE.cube_mesh;
		auto shadow_mesh = CUBE.cs_mesh;
		auto WIDTH = CUBE.shadow_width;

		// �L���[�u�̏��ƕ\��
		gl::pushModelView(); // ��������-------------------------------------
		gl::translate(pos.x, pos.y, pos.z);
		gl::scale(CUBE.size.x, CUBE.size.y, CUBE.size.z);
		gl::rotate(Vec3f(0.0f, 0.0f, 0.0f));
		gl::draw(mesh);	// �|���S����`��
		gl::popModelView();  // �����܂�-------------------------------------

		// �e�̏��ƕ\��
		gl::pushModelView(); // ��������-------------------------------------
		gl::translate(pos.x, 5.0f, pos.z);
		gl::scale(WIDTH, 1.0f, WIDTH);
		gl::rotate(Vec3f(0.0f, 0.0f, 0.0f));
		gl::draw(shadow_mesh);	// �|���S����`��
		gl::popModelView();  // �����܂�-------------------------------------
	}
}
#pragma endregion