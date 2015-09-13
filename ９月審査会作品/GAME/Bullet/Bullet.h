#pragma once
#include "../../common.h"
#include "../Object.h"

class Bullet;
typedef std::shared_ptr<Bullet> BulletSP;

// ’e‚P”­•ª‚Ìˆ—‚É•K—v‚È•Ï”EŠÖ”
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
