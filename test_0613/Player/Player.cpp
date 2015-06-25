#include "Player.h"
#include "Player.h"

Player::Player(){
	pos_ = Vec2f(0, 0);					// �����ʒu
	speed_ = Vec2f(1.0f, 1.0f);			// �e�����ւ̈ړ����x
	view_size_ = Vec2f(50, 50);			// �\�����鎩�@�̃T�C�Y
	draw_direction_ = 0.0f;					// ���@�̌���
	tex_ = Texture("res/player.png");	// �摜�̌Ăяo��

	start_tex_ = Vec2f(0.0f, 0.0f);		// �摜�̐؂�o���ʒu
	tex_size_ = Vec2f(64.0f, 64.0f);	// �摜�̐؂蔲���ʒu

	obj_direction = UP;					// �N����������������X�^�[�g
}


bool Player::isPushKey_SPACE(AppEnv& env){
	return env.isPushKey(GLFW_KEY_SPACE);
}

// update()�Ŕ���Ə��������Ă���̂ŕ�����ׂ��ł���ˁc�ҏ�
void Player::update(AppEnv& env){
	if (env.isPushKey('W') || env.isPressKey('W')){
		pos_.y() += speed_.y();
		draw_direction_ = PI * 2;
		obj_direction = UP;
	}

	if (env.isPushKey('S') || env.isPressKey('S')){
		pos_.y() -= speed_.y();
		draw_direction_ = PI;
		obj_direction = DOWN;
	}

	if (env.isPushKey('D') || env.isPressKey('D')){
		pos_.x() += speed_.x();
		draw_direction_ = (PI / 2) * 3;
		obj_direction = RIGHT;
	}

	if (env.isPushKey('A') || env.isPressKey('A')){
		pos_.x() -= speed_.x();
		draw_direction_ = PI / 2;
		obj_direction = LEFT;
	}
}

void Player::draw(){
	drawTextureBox(pos_.x(), pos_.y(),
				   view_size_.x(), view_size_.y(),
				   start_tex_.x(), start_tex_.y(),
				   tex_size_.x(), tex_size_.y(),
				   tex_, Color(1, 1, 1),
				   draw_direction_, Vec2f(1, 1), Vec2f(view_size_/2));
}