#include "Manager.h"

Manager::Manager(){
	shot_timer_ = -1;
	delete_line = -10.0f;

	enemy_timer_ = -1;
	enemy_delete_line_ = 1.f;
}


void Manager::setup()
{
	player->setup();
	UI->setup();
}


void Manager::update(Vec2i& direction, bool& istouch,
					 unsigned int& scene, unsigned int& score)
{
	player->update(direction);
	UI->update();
#pragma region 弾の発射と消滅
	// 画面をタッチして１秒毎に弾を発射する
	if (istouch)
	{
		shot_timer_++;
		if (shot_timer_ == 0)
		{
			// 弾を１つリストに追加する
			bullet_obj.push_back(BulletSP(new Bullet(player->getPos())));
		}

		// １秒経過したらタイマーをリセット
		else if (shot_timer_ > 25)
		{
			shot_timer_ = -1;
		}
	}
	// 指を離してもタイマーをリセット
	else
	{
		shot_timer_ = -1;
	}

	// イテレータ取得
	auto bullet_it = bullet_obj.begin();

	// リストの先頭から最後まで弾を処理していく
	while (bullet_it != bullet_obj.end())
	{
		(*bullet_it)->update();

		// 一定距離進むか、敵に当たったら削除 (追加：残り時間が０になったら)
		if ((*bullet_it)->getPos().z < delete_line ||
			(*bullet_it)->isDead() || UI->getTime() <= 0)
		{
			bullet_it = bullet_obj.erase(bullet_it);
		}
		else
		{
			bullet_it++;
		}
	}
#pragma endregion

#pragma region 敵の生成と消滅
	enemy_timer_++;
	if (enemy_timer_ == 0)
	{
		enemy_obj.push_back(EnemySP(new Enemy));
	}
	else if (enemy_timer_ >= 150)
	{
		enemy_timer_ = -1;
	}

	// イテレータ取得
	auto enemy_it = enemy_obj.begin();

	// リストの先頭から最後まで弾を処理していく
	while (enemy_it != enemy_obj.end())
	{
		(*enemy_it)->update();

		// 一定距離進むか、弾に当たったら削除 (追加：残り時間が０になったら)
		if ((*enemy_it)->getPos().z > enemy_delete_line_ ||
			(*enemy_it)->isDead() || UI->getTime() <= 0)
		{
			enemy_it = enemy_obj.erase(enemy_it);
		}
		else
		{
			enemy_it++;
		}
	}
#pragma endregion

	// 弾と敵の衝突判定を１つずつループで処理
	for (auto& bullet : bullet_obj)
	{
		for (auto& enemy : enemy_obj)
		{
			if (collision(enemy, bullet))
			{
				bullet->hit();
				enemy->hit();
				UI->setScore(UI->getScore() + enemy->AddScore());
			}
		}
	}


	// 残り時間が０になったらリザルトへ移動
	if (UI->getTime() <= 0)
	{
		scene = RESULT;
		UI->setTime(20 * 60);
		score = UI->getScore();
		UI->setScore(0);

		// プレイヤーの座標はリセット完了
		player->setPos(Vec3f(0.f, 0.f, 0.f));
		// ***** カメラアングルのリセットが出来ず…要修正 ***** //
		camera->setAngle(0.0f);
	}
}


// プレイヤー・敵・弾の描画をまとめる
void Manager::draw()
{
	player->draw();

	for (auto& enemys : enemy_obj)
	{
		enemys->draw();
	}

	for (auto& bullets : bullet_obj)
	{
		bullets->draw();
	}
	UI->draw();
}


// 敵と弾の衝突判定
bool Manager::collision(EnemySP& enemy, BulletSP& bullet)
{
	if (enemy->getPos().x + enemy->getSize().x > bullet->getPos().x &&
		enemy->getPos().x - enemy->getSize().x < bullet->getPos().x &&
		enemy->getPos().y + enemy->getSize().y > bullet->getPos().y &&
		enemy->getPos().y - enemy->getSize().y < bullet->getPos().y &&
		enemy->getPos().z + enemy->getSize().z > bullet->getPos().z &&
		enemy->getPos().z - enemy->getSize().z < bullet->getPos().z)
	{
		return true;
	}

	else
	{
		return false;
	}
}

