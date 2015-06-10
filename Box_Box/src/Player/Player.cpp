#include "Player.h"

#pragma region �R���X�g���N�^
Player::Player(){
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
	p_mesh.appendVertices(&vertices[0], sizeof(vertices) / sizeof(vertices[0]));

	// �e�̕\���͈�ʂ����ŗǂ��̂ŕʂɗp��
	Vec3f shadow_vertices[] = {
		{ -1, 1, -1 }, { -1, 1, 1 }, { 1, 1, 1 },
		{ -1, 1, -1 }, { 1, 1, 1 }, { 1, 1, -1 },
	};
	shadow_mesh.appendVertices(&shadow_vertices[0], sizeof(shadow_vertices) / sizeof(shadow_vertices[0]));

	// ���_��(��)�̐F���w��(�v���C���[)--------------------------------------------------------
	Color colors[] = {
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
	p_mesh.appendColorsRgb(&colors[0], sizeof(colors) / sizeof(colors[0]));

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
	p_mesh.appendIndices(&box_indices[0], sizeof(box_indices) / sizeof(box_indices[0]));

	// �e�̒��_�ԍ�
	uint32_t shadow_indices[] = {
		0, 1, 2,
		3, 4, 5,
	};
	shadow_mesh.appendIndices(&shadow_indices[0], sizeof(shadow_indices) / sizeof(shadow_indices[0]));

	p_mesh.recalculateNormals();

	// �ϐ��̏�����
	pos = Vec3f(0, 15, 0);			// �v���C���[�̏����ʒu
	size = Vec3f(8.0f, 8.0f, 8.0f); // �v���C���[�̑傫��
	gravity = 0.0f;
	move_speed = 1.0f;
	get_A = get_S = get_D = get_W = get_SPACE = false;
	isjumping = false;
	shadow_size = 8.0f;
}
#pragma endregion


void Player::setup(){
	font = Font(loadAsset("font/MyComSquare-Medium.otf"), 15);
}

#pragma region �L�[�������ꂽ���̔���
void Player::keyDown(KeyEvent event, audio::BufferPlayerNodeRef& JUMP_SE){
	if (event.getCode() == KeyEvent::KEY_a){
		get_A = true;
	}

	if (event.getCode() == KeyEvent::KEY_d){
		get_D = true;
	}

	if (event.getCode() == KeyEvent::KEY_w){
		get_W = true;
	}

	if (event.getCode() == KeyEvent::KEY_s){
		get_S = true;
	}

	// �W�����v
	if (event.getCode() == KeyEvent::KEY_SPACE && !isjumping){
		JUMP_SE->start();
		get_SPACE = true;
		isjumping = true;
	}
}
#pragma endregion


#pragma region  �L�[�𗣂������̔���
void Player::keyUp(KeyEvent event){
	if (event.getCode() == KeyEvent::KEY_a){
		get_A = false;
	}

	if (event.getCode() == KeyEvent::KEY_d){
		get_D = false;
	}

	if (event.getCode() == KeyEvent::KEY_w){
		get_W = false;
	}

	if (event.getCode() == KeyEvent::KEY_s){
		get_S = false;
	}

	// �W�����v
	if (event.getCode() == KeyEvent::KEY_SPACE){
		get_SPACE = false;
	}
}
#pragma endregion


#pragma region �e�N���X�̃|�C���^���擾
void Player::SetReference(FallCube* fc_ref, Item* i_ref, GameUI* ui_ref){
	fallcube_ref = fc_ref;
	item_ref = i_ref;
	game_ui_ref = ui_ref;
}
#pragma endregion


#pragma region ���@���ʂ̓����蔻��
bool Player::isCollisionFallCube_A(){
	for (unsigned int i = 0; i < fallcube_ref->cube.size(); i++){
		// fallcube �̉��ӂƂ̓����蔻��
		if (fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y < pos.y + size.y &&
			fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y > pos.y - size.y){

			// fallcube �̉E�ʂƂ̓����蔻��
			if (fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x + move_speed / 2 > pos.x - size.x &&
				fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x - move_speed / 2 < pos.x - size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z > pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z < pos.z + size.z)
			{
				return true;
			}

			else
			{
				return false;
			}
		}
	}
	return false;
}
#pragma endregion


#pragma region ���@�E�ʂ̓����蔻��
bool Player::isCollisionFallCube_D(){
	for (unsigned int i = 0; i < fallcube_ref->cube.size(); i++){
		// fallcube �̉��ӂƂ̓����蔻��
		if (fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y < pos.y + size.y &&
			fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y > pos.y - size.y)
		{
			// fallcube �̍��ʂƂ̓����蔻��
			if (fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x - move_speed / 2 < pos.x + size.x &&
				fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x + move_speed / 2 > pos.x + size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z > pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z < pos.z + size.z)
			{
				return true;
			}

			else
			{
				return false;
			}
		}
	}
	return false;
}
#pragma endregion


#pragma region ���@�̉��̖ʂ̓����蔻��
bool Player::isCollisionFallCube_W(){
	for (unsigned int i = 0; i < fallcube_ref->cube.size(); i++){
		// fallcube �̉��ӂƂ̓����蔻��
		if (fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y < pos.y + size.y &&
			fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y > pos.y - size.y)
		{
			// fallcube �̎�O�̖ʂƂ̓����蔻��
			if (fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x > pos.x - size.x &&
				fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x < pos.x + size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z + move_speed / 2 > pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z - move_speed / 2 < pos.z + size.z)
			{
				return true;
			}

			else
			{
				return false;
			}
		}
	}
	return false;
}
#pragma endregion


#pragma region ���@�̎�O�̖ʂ̓����蔻��
bool Player::isCollisionFallCube_S(){
	for (unsigned int i = 0; i < fallcube_ref->cube.size(); i++){
		// fallcube �̉��ӂƂ̓����蔻��
		if (fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y < pos.y + size.y &&
			fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y > pos.y - size.y)
		{
			// fallcube �̉��̖ʂƂ̓����蔻��
			if (fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x > pos.x - size.x &&
				fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x < pos.x + size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z + move_speed / 2 > pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z - move_speed / 2 < pos.z + size.z)
			{
				return true;
			}

			else
			{
				return false;
			}
		}
	}
	return false;
}
#pragma endregion


#pragma region ���@�̒�ʂ̖ʂ̓����蔻��
bool Player::isCollisionFallCube_SPACE(){
	for (unsigned int i = 0; i < fallcube_ref->cube.size(); i++){
		// fallcube �̉��ӂƂ̓����蔻��
		if (fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y < pos.y + size.y &&
			fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y - gravity > pos.y + size.y)
		{
			// fallcube �̏�ʂƂ̓����蔻��
			if (fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x > pos.x - size.x &&
				fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x < pos.x + size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z + move_speed / 2 > pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z - move_speed / 2 < pos.z + size.z)
			{
				return true;
			}

			else
			{
				return false;
			}
		}
	}
	return false;
}
#pragma endregion


#pragma region �A�C�e���̎擾����
void Player::isCollisionItem(unsigned int& score, unsigned int& time, audio::BufferPlayerNodeRef& ITEM_GET_SE){
	for (unsigned int i = 0; i < item_ref->obj.size(); i++)
	{
		// �A�C�e���̒�ӂ������@�̏�ӂ�������
		if (pos.y + size.y >= item_ref->obj[i].pos.y &&
			pos.y - size.y <= item_ref->obj[i].pos.y)
		{
			// ���@�̍��E���ʂ̊�
			if (pos.x + size.x >= item_ref->obj[i].pos.x &&
				pos.x - size.x <= item_ref->obj[i].pos.x)
			{
				// ���@�̎�O�Ɖ��̖ʂ̊�
				if (pos.z + size.z >= item_ref->obj[i].pos.z &&
					pos.z - size.z <= item_ref->obj[i].pos.z)
				{
					item_ref->obj[i].get_flag = true;
					ITEM_GET_SE->start();
					score += 1;
					time += 30;
				}
			}
		}
	}
}
#pragma endregion


#pragma region �X�V����
void Player::update(unsigned int& score, unsigned int& scene, audio::BufferPlayerNodeRef& ITEM_GET_SE){
	float ground_end = 92.0f;
	isCollisionItem(score, game_ui_ref->_time, ITEM_GET_SE);

	if (get_A){
		if (pos.x > -ground_end){
			pos.x += -move_speed; // ���ړ�
		}
	}

	if (get_D){
		if (pos.x < ground_end){
			pos.x += move_speed; // �E�ړ�
		}
	}

	if (get_W){
		if (pos.z > -ground_end){
			pos.z += -move_speed; // ���ֈړ�
		}
	}

	if (get_S){
		if (pos.z < ground_end){
			pos.z += move_speed; // ��O�ֈړ�
		}
	}

	if (isCollisionFallCube_A() || isCollisionFallCube_D() ||
		isCollisionFallCube_S() || isCollisionFallCube_W() ||
		isCollisionFallCube_SPACE())
	{
		scene = RESULT;

	}


	// �W�����v���̋���
	if (get_SPACE){
		gravity = 10;
	}
	pos.y += gravity;
	gravity -= 1.0f;

	// �n�ʂɐG��Ă�����
	if (pos.y <= 15.0f){
		gravity = 0;
		pos.y = 15.0f;
		isjumping = false;
		shadow_size = 8.0f;
	}
	else{
		shadow_size += 8.0f / (2.0f * 2.0f);
		get_SPACE = false;
	}
}
#pragma endregion


#pragma region �`�揈��
void Player::draw(){
	// ���@�̏��ƕ\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::translate(pos.x, pos.y, pos.z);
	gl::scale(size.x, size.y, size.z);
	gl::rotate(Vec3f(0.0f, 0.0f, 0.0f));
	gl::draw(p_mesh);	// �|���S����`��
	gl::popModelView();  // �����܂�-------------------------------------

	// �e�̏��ƕ\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::translate(pos.x, 5.0f, pos.z);
	gl::scale(gravity, 1.0f, gravity);
	gl::rotate(Vec3f(0.0f, 0.0f, 0.0f));
	gl::draw(shadow_mesh);	// �|���S����`��
	gl::popModelView();  // �����܂�-------------------------------------
}
#pragma endregion
