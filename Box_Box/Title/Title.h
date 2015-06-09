#pragma once
#include <memory>
#include "cinder/Rand.h"
#include "../common.h"

struct TitleCube{
	TriMesh cube_mesh;
	Vec3f pos;
	Vec3f size;
	bool getStart;
};


class Title{
public:
	TriMesh title_mesh;
	TitleCube string_cube[52];
	Vec3f rogo_z;

	Font font;
	ColorA text_color;
	float text_alpha;

	Title();
	~Title(){};

	void keyDown(KeyEvent event, unsigned int& scene);
	void setup();
	void update();
	void draw();
};