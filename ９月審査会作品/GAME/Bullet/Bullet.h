#pragma once
#include "../../common.h"
#include "../Object.h"

class Bullet;
typedef std::shared_ptr<Bullet> BulletSP;

// 弾１発分の処理に必要な変数・関数
class Bullet : public Object{
private:
	ObjLoader* obj;
	TriMesh mesh;

public:
	Bullet(Vec3f);
	virtual void setup();
	virtual void update();
	virtual void draw();
};
