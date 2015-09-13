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

	// �x�W�F�Ȑ��œG�𓮂����Ă݂�
	float g_t;
	std::vector<enemy_> enemy_move;


public:
	Enemy();

	Vec3f WsbVec3BezierSpline(const Vec3f*, const Vec3f*, const Vec3f*, const Vec3f*, float);

	virtual void setup();
	virtual void update();
	virtual void draw();
};