#pragma once
#include <memory>
#include "cinder/Rand.h"
#include "../common.h"

struct Cube{
	TriMesh cube_mesh;
	TriMesh cs_mesh;
	Vec3f pos;		  // �L���[�u���ꂼ��̃|�W�V����
	float shadow_width;
};

class FallCube{
public:
	TriMesh c_mesh;
	TriMesh shadow_mesh; // �e�p�̃��b�V�����
	float gravity;    // �d��

	std::vector<Cube> cube;

	FallCube();
	~FallCube(){};

	void update();
	void draw();
};