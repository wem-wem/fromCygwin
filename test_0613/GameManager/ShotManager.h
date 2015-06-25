#pragma once
#include "../Player/Player.h"
#include "../Bullet/Bullet.h"

#include <list>

class ShotManager;
typedef std::shared_ptr<ShotManager> ShotManagerSP;

class ShotManager{
private:
	PlayerSP player = PlayerSP(new Player);

	std::list<BulletSP> shot_obj;

public:
	ShotManager() = default;

	void update(AppEnv&);
	void draw();
};