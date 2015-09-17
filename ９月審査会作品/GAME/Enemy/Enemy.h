#pragma once
#include "../../common.h"
#include "../Object.h"

class Enemy;
typedef std::shared_ptr<Enemy> EnemySP;

struct enemy_
{
	Vec3f g_AncLine0;
	Vec3f g_AncLine1;
	Vec3f g_AncLine2;
	Vec3f g_AncLine3;
};


class Enemy : public Object{
private:
	ObjLoader* obj;
	TriMesh mesh;
	Vec2f size;
	bool  is_dead;

	// ƒxƒWƒF‹Èü‚Å“G‚ð“®‚©‚µ‚Ä‚Ý‚é
	float g_t;
	enemy_ enemy_move;


public:
	Enemy();

	Vec3f WsbVec3BezierSpline(Vec3f*, Vec3f*, Vec3f*, Vec3f*, float);
	Vec2f& getSize(){ return size; }

	virtual void setup();
	virtual void update();
	virtual void draw();

	// ‚±‚ÌŠÖ”‚ªŒÄ‚Î‚ê‚½‚çŽ€–Sˆµ‚¢‚Æ‚·‚é
	void hit() { this->is_dead = true; }
	bool isDead() { return is_dead; }
};