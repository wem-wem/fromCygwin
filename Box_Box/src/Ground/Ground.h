#pragma once
#include "../common.h"

class Ground{
public:
	TriMesh g_mesh; // 地面用のメッシュ情報
	Vec2f size;

	Ground();
	~Ground(){};

	void draw();
};