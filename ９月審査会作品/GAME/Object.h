#pragma once
#include "../common.h"

// �S�ẴI�u�W�F�N�g�������
class Object{
protected:
	Vec3f pos_;
	Vec3f speed_;

public:
	Object() = default;
	virtual ~Object() {}

	// �l��n�������Ő��l�̕ύX�͂��Ȃ��ׁAconst��t����
	const Vec3f& getPos(){ return pos_; }

	virtual void setup() {}
	virtual void update() {}
	virtual void draw() {}
};
