#include "ShotManager.h"

void ShotManager::update(AppEnv& env){
	player->update(env);

	if (player->isPushKey_SPACE(env)){
		shot_obj.push_back(BulletSP(new Bullet(player->getPos(),
											   player->getDirection())));
	}

	auto shot_it = shot_obj.begin();
	while (shot_it != shot_obj.end()){
		(*shot_it)->update();

		// ‰æ–ÊŠO‚Éo‚½‚çÁ‚¦‚éˆ—
		if ((*shot_it)->getPos().x() < -WIDTH / 2 ||
			(*shot_it)->getPos().x() > WIDTH / 2 ||
			(*shot_it)->getPos().y() < -HEIGHT / 2 ||
			(*shot_it)->getPos().y() > HEIGHT / 2)
		{
			shot_it = shot_obj.erase(shot_it++);
		}

		shot_it++;

	}
}

void ShotManager::draw(){
	player->draw();
	for (auto& shots : shot_obj){
		shots->draw();
	}
}