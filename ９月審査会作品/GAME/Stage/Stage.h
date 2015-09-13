#pragma once
#include "../../common.h"

class Stage;
typedef std::shared_ptr<Stage> StageSP;

struct Floor{
	Vec3f pos;
	Vec3f size;
};


class Stage{
private:
	Floor floor;

public:
	Stage()
	{
		floor = { Vec3f(0.0f, -3.0f, 0.0f),
				  Vec3f(20.0f, 1.0f, 150.0f) };
	}

	void draw()
	{
		gl::pushModelView();
		gl::drawCube(floor.pos, floor.size);
		gl::popModelView();
	}
};
