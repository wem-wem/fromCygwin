#pragma once
#include "../../common.h"
#include "../Object.h"

class Player;
typedef std::shared_ptr<Player> PlayerSP;

class Player : public Object{
private:
	ObjLoader* obj;
	TriMesh mesh;

	// プレイヤーの移動範囲を制限
	Vec2f move_max;

public:
	Player();

	virtual void setup();
	virtual void update(Vec2i);
	virtual void draw();
	void setPos(Vec3f resetPos){ pos_ = resetPos; }
};

