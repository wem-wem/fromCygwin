#pragma once
#include "../Player/Player.h"
#include "../Bullet/Bullet.h"

#include <list>

class GameManager;
typedef std::shared_ptr<GameManager> GameManagerSP;

class GameManager{
private:
	// Player クラスにある関数を利用するので用意
	PlayerSP player = PlayerSP(new Player);

	// Bullet クラスにある関数を利用する為に用意
	std::list<BulletSP> shot_obj;

public:
	GameManager() = default;

	void update(AppEnv&);
	void draw();
};