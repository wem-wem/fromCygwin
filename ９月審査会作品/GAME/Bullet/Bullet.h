#pragma once
#include "../../common.h"
#include "../Object.h"

class Bullet;
typedef std::shared_ptr<Bullet> BulletSP;

// ’e‚P”­•ª‚Ìˆ—‚É•K—v‚È•Ï”EŠÖ”
class Bullet : public Object{
private:
	bool  is_dead;
	Vec2f size;
	ObjLoader* obj;
	TriMesh mesh;

public:
	Bullet(Vec3f);
	Vec2f& getSize(){ return size; }
	virtual void setup();
	virtual void update();
	virtual void draw();

	// ‚±‚ÌŠÖ”‚ªŒÄ‚Î‚ê‚½‚ç€–Sˆµ‚¢‚Æ‚·‚é
	void hit();
	bool isDead();
};
