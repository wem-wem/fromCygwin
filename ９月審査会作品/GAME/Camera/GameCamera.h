#pragma once
#include "../../common.h"
#include "../Player/Player.h"

class GameCamera;
typedef std::shared_ptr<GameCamera> GameCameraSP;

class GameCamera{
private:
	PlayerSP player;
	CameraPersp* camera;

	float angle_;
	float camera_move;
	float camera_angle_max;

public:
	GameCamera();
	~GameCamera();

	void setup();
	void update();
	void target_update(Vec2i direction);
	void SetCamera();
};

