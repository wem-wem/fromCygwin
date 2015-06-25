#include "Player.h"
#include "Player.h"

Player::Player(){
	pos_ = Vec2f(0, 0);					// �����ʒu
	speed_ = Vec2f(1.0f, 1.0f);			// �e�����ւ̈ړ����x
	view_size_ = Vec2f(50, 50);			// �\�����鎩�@�̃T�C�Y
	direction_ = 0.0f;					// ���@�̌���
	tex_ = Texture("res/player.png");	// �摜�̌Ăяo��

	start_tex_ = Vec2f(0.0f, 0.0f);		// �摜�̐؂�o���ʒu
	tex_size_ = Vec2f(64.0f, 64.0f);	// �摜�̐؂蔲���ʒu
}


bool Player::isPushKey_SPACE(AppEnv& env){
	return env.isPushKey(GLFW_KEY_SPACE);
}

void Player::update(AppEnv& env){
	if (env.isPushKey('W') || env.isPressKey('W')){
		pos_.y() += speed_.y();
		direction_ = PI * 2;
	}

	if (env.isPushKey('S') || env.isPressKey('S')){
		pos_.y() -= speed_.y();
		direction_ = PI;
	}

	if (env.isPushKey('D') || env.isPressKey('D')){
		pos_.x() += speed_.x();
		direction_ = (PI / 2) * 3;
	}

	if (env.isPushKey('A') || env.isPressKey('A')){
		pos_.x() -= speed_.x();
		direction_ = PI / 2;
	}
}

void Player::draw(){
	drawTextureBox(pos_.x(), pos_.y(),
				   view_size_.x(), view_size_.y(),
				   start_tex_.x(), start_tex_.y(),
				   tex_size_.x(), tex_size_.y(),
				   tex_, Color(1, 1, 1),
				   direction_, Vec2f(1, 1), Vec2f(view_size_/2));
}