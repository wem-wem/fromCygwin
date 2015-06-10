#include "Item.h"

Item::Item(){
#pragma region �ʏ�A�C�e��
#pragma region ���_���W
	// �����̂̒��_���W���w��--------------------------------------------------------
	Vec3f vertices[] = {
		{ -1, -1, -1 }, { 1, 1, -1 }, { 1, -1, -1 },
		{ -1, -1, -1 }, { -1, 1, -1 }, { 1, 1, -1 },

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
	i_mesh.appendVertices(&vertices[0], sizeof(vertices) / sizeof(vertices[0]));

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
		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },
		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },

		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },
		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },

		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },
		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },

		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },
		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },

		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },
		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },

		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },
		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },
	};
	i_mesh.appendColorsRgb(&colors[0], sizeof(colors) / sizeof(colors[0]));

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
	i_mesh.appendIndices(&box_indices[0], sizeof(box_indices) / sizeof(box_indices[0]));

	// �e�̒��_�ԍ�
	uint32_t shadow_indices[] = {
		0, 1, 2,
		3, 4, 5,
	};
	shadow_mesh.appendIndices(&shadow_indices[0], sizeof(shadow_indices) / sizeof(shadow_indices[0]));
#pragma endregion
#pragma endregion

	i_mesh.recalculateNormals();
	Rand::randomize();

	for (int i = 0; i < 10; i++){
		obj.push_back({ i_mesh, shadow_mesh, Vec3f(randFloat(-90.0f, 90.0f), randFloat(20.0f, 50.0f), randFloat(-90.0f, 90.0f)), Vec3f(5.0f, 5.0f, 5.0f), 5.0f, false });
	}

	rotate = Vec3f(0.0f, 0.0f, 0.0f);
}


#pragma region �X�V����
void Item::update(){
	rotate += Vec3f(0.5f, 0.5f, 0.0f);

	// �A�C�e���̎擾���肪���ꂽ�ꍇ�A�����ɕʂ̏ꏊ�֍Ĕz�u
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		if (obj[i].get_flag)
		{
			obj[i].pos = Vec3f(randFloat(-90.0f, 90.0f), randFloat(20.0f, 50.0f), randFloat(-90.0f, 90.0f));
			obj[i].get_flag = false;
		}
	}
}
#pragma endregion

#pragma region �`�揈��
void Item::draw(){
	for (auto ITEM : obj){
		auto pos = ITEM.pos;
		auto mesh = ITEM.item_mesh;
		auto shadow_mesh = ITEM.is_mesh;
		auto WIDTH = ITEM.shadow_width;

		// �L���[�u�̏��ƕ\��
		gl::pushModelView(); // ��������-------------------------------------
		gl::translate(pos.x, pos.y, pos.z);
		gl::scale(ITEM.size.x, ITEM.size.y, ITEM.size.z);
		gl::rotate(Vec3f(45.0f, 45.0f, 0.0f) + rotate);
		gl::draw(mesh);	// �|���S����`��
		gl::popModelView();  // �����܂�-------------------------------------

		// �e�̏��ƕ\��
		gl::pushModelView(); // ��������-------------------------------------
		gl::translate(pos.x, 5.0f, pos.z);
		gl::scale(WIDTH, 1.0f, WIDTH);
		gl::rotate(Vec3f(0.0f, 45.0f + rotate.y, 0.0f));
		gl::draw(shadow_mesh);	// �|���S����`��
		gl::popModelView();  // �����܂�-------------------------------------
	}
}
#pragma endregion