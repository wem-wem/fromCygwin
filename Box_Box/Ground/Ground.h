#pragma once
#include "../common.h"

class Ground{
public:
	TriMesh g_mesh; // �n�ʗp�̃��b�V�����
	Vec2f size;

	Ground();
	~Ground(){};

	void draw();
};