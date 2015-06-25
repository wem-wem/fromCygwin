#include "Bullet.h"

Bullet::Bullet(Vec2f player_pos, int player_direction){
	tex_ = Texture("res/shot.png");

	pos_ = player_pos;
	view_size_ = Vec2f(10, 20);
	start_tex_ = Vec2f(0.0f, 0.0f);
	tex_size_ = Vec2f(32.0f, 32.0f);


	if (player_direction == UP){
		draw_direction_ = UP;
		speed_ = Vec2f(0, 5.0f);
		draw_direction_ = PI;
	}

	if (player_direction == DOWN){
		draw_direction_ = DOWN;
		speed_ = Vec2f(0, -5.0f);
		draw_direction_ = PI * 2;
	}

	if (player_direction == LEFT){
		draw_direction_ = LEFT;
		speed_ = Vec2f(-5.0f, 0);
		draw_direction_ = (PI / 2) * 3;
	}

	if (player_direction == RIGHT){
		draw_direction_ = RIGHT;
		speed_ = Vec2f(5.0f, 0);
		draw_direction_ = PI / 2;
	}

	/* �v���C���[�̌����ƕ`��̊p�x���P�̕ϐ��ŏ������悤�Ƃ����� */
	/* ���菈���̎��Ɂuplayer_direction == PI * 2�v�Ƃ������Â炢�R�[�h�ɂȂ����̂� */
	/*�uUP�v�Ə����鏬��N�̃R�[�h�̊ۃR�s�Ɂc�����_����� */
}


void Bullet::update(){
	pos_ += speed_;
}


void Bullet::draw(){
	drawTextureBox(pos_.x(), pos_.y(),
		view_size_.x(), view_size_.y(),
		start_tex_.x(), start_tex_.y(),
		tex_size_.x(), tex_size_.y(),
		tex_, Color(1,1,1),
		draw_direction_, Vec2f(1, 1), Vec2f(view_size_ /2));
}
