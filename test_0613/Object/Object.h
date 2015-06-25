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
	float direction_;
	Texture tex_;

	Vec2f start_tex_;
	Vec2f tex_size_;

public:
	Object();
	virtual ~Object(){};	// �f�X�g���N�^�̗������R�����c

	void update();
	void draw();
};
