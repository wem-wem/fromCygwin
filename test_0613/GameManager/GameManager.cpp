#include "GameManager.h"

void GameManager::update(AppEnv& env){
	// Playerの現在地を更新する為に update() を呼ぶ
	player->update(env);

	// Playerがスペースキーを押したか判定
	// 押した場合、Bulletを１つ生成
	// (その際にPlayerの 座標 と 表示向き を取得)
	if (player->isPushKey_SPACE(env)){
		shot_obj.push_back(BulletSP(new Bullet(player->getPos(),
			player->getDirection())));
	}

	// 画面に弾が１つ以上ある場合、弾の先頭アドレスを取得
	auto shot_it = shot_obj.begin();

	// 弾を１つ目から処理。
	// ０個の場合も判定はされるが中は通らない
	while (shot_it != shot_obj.end()){
		(*shot_it)->update();

		// 画面外に出たら消える処理
		if ((*shot_it)->getPos().x() < -WIDTH / 2 ||
			(*shot_it)->getPos().x() > WIDTH / 2 ||
			(*shot_it)->getPos().y() < -HEIGHT / 2 ||
			(*shot_it)->getPos().y() > HEIGHT / 2)
		{
			shot_it = shot_obj.erase(shot_it++);
		}

		// 次の弾のアドレスへ移動
		shot_it++;

	}
}

void GameManager::draw(){
	// プレイヤーと弾の描画処理をまとめて書く
	player->draw();

	// update() と同じように、弾の先頭アドレスから順に描画処理
	for (auto& shots : shot_obj){
		shots->draw();
	}
}