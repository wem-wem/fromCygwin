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
	Vec3f size;
	bool  is_dead;
	unsigned int point;

	// ベジェ曲線で敵を動かしてみる
	float g_t;
	enemy_ enemy_move;


public:
	Enemy();

	Vec3f WsbVec3BezierSpline(Vec3f*, Vec3f*, Vec3f*, Vec3f*, float);
	Vec3f& getSize(){ return size; }

	virtual void setup();
	virtual void update();
	virtual void draw();

	// 得点加算
	int AddScore();

	// この関数が呼ばれたら死亡扱いとする
	void hit() { this->is_dead = true; }
	bool isDead() { return is_dead; }
};