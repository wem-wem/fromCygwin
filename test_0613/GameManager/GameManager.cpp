#include "GameManager.h"

void GameManager::update(AppEnv& env){
	// Player‚ÌŒ»Ý’n‚ðXV‚·‚éˆ×‚É update() ‚ðŒÄ‚Ô
	player->update(env);

	// Player‚ªƒXƒy[ƒXƒL[‚ð‰Ÿ‚µ‚½‚©”»’è
	// ‰Ÿ‚µ‚½ê‡ABullet‚ð‚P‚Â¶¬
	// (‚»‚ÌÛ‚ÉPlayer‚Ì À•W ‚Æ •\Ž¦Œü‚« ‚ðŽæ“¾)
	if (player->isPushKey_SPACE(env)){
		shot_obj.push_back(BulletSP(new Bullet(player->getPos(),
			player->getDirection())));
	}

	// ‰æ–Ê‚É’e‚ª‚P‚ÂˆÈã‚ ‚éê‡A’e‚Ìæ“ªƒAƒhƒŒƒX‚ðŽæ“¾
	auto shot_it = shot_obj.begin();

	// ’e‚ð‚P‚Â–Ú‚©‚çˆ—B
	// ‚OŒÂ‚Ìê‡‚à”»’è‚Í‚³‚ê‚é‚ª’†‚Í’Ê‚ç‚È‚¢
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

		// ŽŸ‚Ì’e‚ÌƒAƒhƒŒƒX‚ÖˆÚ“®
		shot_it++;

	}
}

void GameManager::draw(){
	// ƒvƒŒƒCƒ„[‚Æ’e‚Ì•`‰æˆ—‚ð‚Ü‚Æ‚ß‚Ä‘‚­
	player->draw();

	// update() ‚Æ“¯‚¶‚æ‚¤‚ÉA’e‚Ìæ“ª—v‘f‚©‚ç‡‚É•`‰æˆ—
	for (auto& shots : shot_obj){
		shots->draw();
	}
}