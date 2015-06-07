#pragma once
#include <memory>
#include "cinder/Rand.h"
#include "../common.h"

struct Cube{
	TriMesh cube_mesh;
	TriMesh cs_mesh;
	Vec3f pos;		  // キューブそれぞれのポジション
	Vec3f size;
	float shadow_width;
	Color flash_color;
	int steps;
};

class FallCube{
public:
	TriMesh c_mesh;
	TriMesh shadow_mesh; // 影用のメッシュ情報
	float gravity;    // 重力

	std::vector<Cube> cube;

	FallCube();
	~FallCube(){};

	void update();
	void draw();
};