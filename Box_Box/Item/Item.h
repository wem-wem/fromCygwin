#pragma once
#include <memory>
#include "cinder/Rand.h"
#include "../common.h"

struct Item_obj{
	TriMesh item_mesh;
	TriMesh is_mesh;
	Vec3f pos;		  // �L���[�u���ꂼ��̃|�W�V����
	Vec3f size;
	float shadow_width;
	bool get_flag;
};

class Item{
public:
	TriMesh i_mesh;
	TriMesh shadow_mesh; // �e�p�̃��b�V�����
	std::vector<Item_obj> obj;
	Vec3f rotate;

	Item();
	~Item(){};

	void update();
	void draw();
};