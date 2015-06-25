#pragma once
#include "../Player/Player.h"
#include "../Bullet/Bullet.h"

#include <list>

class GameManager;
typedef std::shared_ptr<GameManager> GameManagerSP;

class GameManager{
private:
	// Player �N���X�ɂ���֐��𗘗p����̂ŗp��
	PlayerSP player = PlayerSP(new Player);

	// Bullet �N���X�ɂ���֐��𗘗p����ׂɗp��
	std::list<BulletSP> shot_obj;

public:
	GameManager() = default;

	void update(AppEnv&);
	void draw();
};