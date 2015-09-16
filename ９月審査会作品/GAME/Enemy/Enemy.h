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

	// ƒxƒWƒF‹Èü‚Å“G‚ğ“®‚©‚µ‚Ä‚İ‚é
	float g_t;
	enemy_ enemy_move;


public:
	Enemy();

	Vec3f WsbVec3BezierSpline(Vec3f*, Vec3f*, Vec3f*, Vec3f*, float);

	Vec2f getSize(){ return size; }
	Vec3f getPos(){ return pos_; }

	virtual void setup();
	virtual void update();
	virtual void draw();
};