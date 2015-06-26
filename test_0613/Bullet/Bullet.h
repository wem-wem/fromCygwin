#pragma once

#include "../Object/Object.h"


class Bullet;
typedef std::shared_ptr<Bullet> BulletSP;

class Bullet : public Object{
public:
	Bullet(Vec2f, int);
	void update();
	void draw();
};
