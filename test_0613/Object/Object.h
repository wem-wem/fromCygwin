#pragma once
#include "../common.h"

class Object{
	// private�ł͗��p�o���Ȃ��̂�
	// protected �Ő錾(���X)
protected:
	// �p������N���X�ɕK�v�ȕϐ���錾
	Vec2f pos_;
	Vec2f speed_;
	Vec2f view_size_;
	float draw_direction_;	// �`��̌������w��
	Texture tex_;

	Vec2f start_tex_;
	Vec2f tex_size_;

	// ���@�ƃV���b�g�̌����̔����
	int obj_direction;
	enum direction_num{
		UP,
		DOWN,
		LEFT,
		RIGHT,
	};

public:
	Object();
	virtual ~Object(){};	// �f�X�g���N�^�̗������R�����c

	void update();
	void draw();
};
