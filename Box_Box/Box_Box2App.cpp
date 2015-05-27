#include "common.h"


void Box_Box2App::setup()
{
	// �����̂̒��_���W���w��--------------------------------------------------------
	Vec3f box_vertices[] = {
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
	ground_mesh.appendVertices(&box_vertices[0], sizeof(box_vertices) / sizeof(box_vertices[0]));
	player_mesh.appendVertices(&box_vertices[0], sizeof(box_vertices) / sizeof(box_vertices[0]));

	// �e�̕\���͈�ʂ����ŗǂ��̂ŕʂɗp��
	Vec3f shadow_vertices[] = {
		{ -1, 1, -1 }, { -1, 1, 1 }, { 1, 1, 1 },
		{ -1, 1, -1 }, { 1, 1, 1 }, { 1, 1, -1 },
	};
	shadow_mesh.appendVertices(&shadow_vertices[0], sizeof(shadow_vertices) / sizeof(shadow_vertices[0]));


	// ���_��(��)�̐F���w��(�y��)--------------------------------------------------------
	Color ground_colors[] = {
		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },
		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },

		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },
		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },

		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },
		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },

		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },
		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },

		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },
		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },

		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },
		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },
	};
	ground_mesh.appendColorsRgb(&ground_colors[0], sizeof(ground_colors) / sizeof(ground_colors[0]));

	// ���_��(��)�̐F���w��(�v���C���[)--------------------------------------------------------
	Color player_colors[] = {
		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },

		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },

		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },

		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },

		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },

		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
	};
	player_mesh.appendColorsRgb(&player_colors[0], sizeof(player_colors) / sizeof(player_colors[0]));

	// �e�̐F
	Color shadow_colors[] = {
		{ 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
		{ 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
	};
	shadow_mesh.appendColorsRgb(&shadow_colors[0], sizeof(shadow_colors) / sizeof(shadow_colors[0]));


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
	ground_mesh.appendIndices(&box_indices[0], sizeof(box_indices) / sizeof(box_indices[0]));
	player_mesh.appendIndices(&box_indices[0], sizeof(box_indices) / sizeof(box_indices[0]));

	// �e�̒��_�ԍ�
	uint32_t shadow_indices[] = {
		0, 1, 2,
		3, 4, 5,
	};
	shadow_mesh.appendIndices(&shadow_indices[0], sizeof(shadow_indices) / sizeof(shadow_indices[0]));

	// ���_�̖@����Cinder�Ɍv�Z���Ă��炤
	ground_mesh.recalculateNormals();
	player_mesh.recalculateNormals();


	// ���C�g�̏���--------------------------------------------------------
	// ���s�������P�p��
	light = std::unique_ptr<gl::Light>(new gl::Light(gl::Light::DIRECTIONAL, 0));
	light->setAmbient(Color(0.0, 0.0, 0.0));
	light->setDiffuse(Color(1.0, 1.0, 1.0));
	light->setDirection(Vec3f(0.0, 1.0, 1.0)); // ���͐^�ォ��^�����Ƃ炷


	// �J�����̏���--------------------------------------------------------
	camera = CameraPersp(getWindowWidth(), getWindowHeight(),
		35.0, 200.0, 1000.0);

	camera.lookAt(Vec3f(0.0, 300.0, 300.0), // Z��700�̒n�_����
		Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)�̒n�_������J����


	// �ϐ��̏����l����--------------------------------------------------------
	ground_size = Vec2f(100.0f, 100.0f);

	ry = 45.0f; // �x��45�x�X����
	player_pos = Vec3f(0, 15, 0); // �v���C���[�̏����ʒu
	gravity = 0.0f;
	a = s = d = w = space = false;
	isjumping = false;



	// �J�����OON(��O�̖ʂ݂̂�\��)
	gl::enable(GL_CULL_FACE);

	// ���_�J���[��Ώۂɂ��ă��C�e�B���O�̌v�Z���s��
	gl::enable(GL_COLOR_MATERIAL);

	// ���C�e�B���OON
	gl::enable(GL_LIGHTING);

	// �@���𐳋K������
	gl::enable(GL_NORMALIZE);

	gl::enableDepthRead();
	gl::enableDepthWrite();
}

void Box_Box2App::keyDown(KeyEvent event)
{
	if (event.getCode() == KeyEvent::KEY_a){
		a = true;
	}

	if (event.getCode() == KeyEvent::KEY_d){
		d = true;
	}

	if (event.getCode() == KeyEvent::KEY_w){
		w = true;
	}

	if (event.getCode() == KeyEvent::KEY_s){
		s = true;
	}

	// �W�����v
	if (event.getCode() == KeyEvent::KEY_SPACE && !isjumping){
		space = true;
		isjumping = true;
	}
}

void Box_Box2App::keyUp(KeyEvent event){
	if (event.getCode() == KeyEvent::KEY_a){
		a = false;
	}

	if (event.getCode() == KeyEvent::KEY_d){
		d = false;
	}


	if (event.getCode() == KeyEvent::KEY_w){
		w = false;
	}

	if (event.getCode() == KeyEvent::KEY_s){
		s = false;
	}

	// �W�����v
	if (event.getCode() == KeyEvent::KEY_SPACE){
		space = false;
	}
}

void Box_Box2App::update()
{
	if (a){
		player_pos.x += -1.0f; // ���ړ�
	}
	if (d){
		player_pos.x += 1.0f; // ���ړ�
	}
	if (w){
		player_pos.z += -1.0f; // ���ړ�
	}
	if (s){
		player_pos.z += 1.0f; // ���ړ�
	}

	// �W�����v���̋���
	if (space){
		gravity = 10;
	}
	player_pos.y += gravity;
	gravity -= 1.0f;

	// �n�ʂɐG��Ă�����
	if (player_pos.y <= 15.0f){
		gravity = 0;
		player_pos.y = 15.0f;
		isjumping = false;
	}
	else{
		space = false;
	}
}

void Box_Box2App::draw()
{
	// clear out the window with black
	gl::clear(Color(0.2f, 0.2f, 0.2f));
	
	// �J�����̏�Ԃ���s����쐬
	// ���_���W�ϊ��p�Ɛ��K���f�o�C�X���W�ϊ��p�̂Q��p�ӂ���
	gl::setMatrices(camera);

	// ���C�e�B���O�J�n
	light->enable();

	// �y��̏��ƕ\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::scale(ground_size.x, 5.0f, ground_size.y);
	gl::rotate(Vec3f(0.0f, ry, 0.0f));
	gl::draw(ground_mesh);	// �|���S����`��
	gl::popModelView();  // �����܂�-------------------------------------

	// ���@�̏��ƕ\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::translate(player_pos.x, player_pos.y, player_pos.z);
	gl::scale(10.0f, 10.0f, 10.0f);
	gl::rotate(Vec3f(0.0f, ry, 0.0f));
	gl::draw(player_mesh);	// �|���S����`��
	gl::popModelView();  // �����܂�-------------------------------------

	// �e�̏��ƕ\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::translate(player_pos.x, 5.0f, player_pos.z);
	gl::scale(gravity, 1.0f, gravity);
	gl::rotate(Vec3f(0.0f, ry, 0.0f));
	gl::draw(shadow_mesh);	// �|���S����`��
	gl::popModelView();  // �����܂�-------------------------------------

	light->disable();
}

CINDER_APP_NATIVE(Box_Box2App, RendererGl)
