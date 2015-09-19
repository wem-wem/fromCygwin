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
}


void Manager::update(Vec2i& direction, bool& istouch)
{
	player->update(direction);

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
		else if (shot_timer_ > 60)
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
		// 一定距離進んだら弾を消す
		// 弾の衝突フラグがtrueになっても消す
		if ((*bullet_it)->getPos().z < delete_line ||
			(*bullet_it)->isDead())
		{
			bullet_it = bullet_obj.erase(bullet_it);
		}

		// 次の弾のアドレスへ移動
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

		// 一定距離進んだら敵を消す処理
		if ((*enemy_it)->getPos().z > enemy_delete_line_ ||
			(*enemy_it)->isDead())
		{
			enemy_it = enemy_obj.erase(enemy_it);
		}

		else
		{
			// 次の弾のアドレスへ移動
			enemy_it++;
		}
	}
#pragma endregion

	// 当たり判定
	for (auto& bullet : bullet_obj)
	{
		for (auto& enemy : enemy_obj)
		{
			if (collision(enemy, bullet))
			{
				bullet->hit();
				enemy->hit();
			}
		}
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
}
