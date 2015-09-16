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


	// リストに弾の情報がある場合、その先頭アドレスを取得
	auto bullet_it = bullet_obj.begin();

	// リストの先頭から最後まで弾を処理していく
	while (bullet_it != bullet_obj.end())
	{
		(*bullet_it)->update();
		// 一定距離進んだら弾を消す処理
		if ((*bullet_it)->getPos().z < delete_line)
		{
			bullet_it = bullet_obj.erase(bullet_it);
		}

		// 敵に当たった場合の消滅判定
		else if((*bullet_it)->getPos().x < 0.f)
		{
		
		}

		else
		{	
			// 次の弾のアドレスへ移動
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

	auto enemy_it = enemy_obj.begin();

	// リストの先頭から最後まで弾を処理していく
	while (enemy_it != enemy_obj.end())
	{
		(*enemy_it)->update();

		// 一定距離進んだら敵を消す処理
		if ((*enemy_it)->getPos().z > enemy_delete_line_)
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


	//// 失敗１…iteratorを回してないので当然ですが、起動直後にエラーで停止
	//if ((*bullet_it)->getPos().x < (*enemy_it)->getPos().x + (*enemy_it)->getSize().x &&
	//	(*bullet_it)->getPos().x > (*enemy_it)->getPos().x - (*enemy_it)->getSize().x)
	//{
	//	bullet_it = bullet_obj.erase(bullet_it);
	//	enemy_it = enemy_obj.erase(enemy_it);
	//}
	//else
	//{
	//	bullet_it++;
	//	enemy_it++;
	//}


	//// 失敗２…上の別々に書いていた処理をまとめて、中で処理しようとしてみた結果大失敗
	////　　　　画面が表示されるもフリーズ
	//for (auto bullet_it = bullet_obj.begin(); bullet_it != bullet_obj.end();)
	//{
	//	for (auto enemy_it = enemy_obj.begin(); enemy_it != enemy_obj.end();)
	//	{
	//		(*bullet_it)->update();
	//		// 一定距離進んだら弾を消す処理
	//		if ((*bullet_it)->getPos().z < delete_line)
	//		{
	//			bullet_it = bullet_obj.erase(bullet_it);
	//		}
	//		else
	//		{
	//			// 次の弾のアドレスへ移動
	//			bullet_it++;
	//		}


	//		(*enemy_it)->update();
	//		// 一定距離進んだら敵を消す処理
	//		if ((*enemy_it)->getPos().z > enemy_delete_line_)
	//		{
	//			enemy_it = enemy_obj.erase(enemy_it);
	//		}
	//		else
	//		{
	//			// 次の弾のアドレスへ移動
	//			enemy_it++;
	//		}

	//		// 判定
	//		if ((*bullet_it)->getPos().x < (*enemy_it)->getPos().x + (*enemy_it)->getSize().x &&
	//			(*bullet_it)->getPos().x > (*enemy_it)->getPos().x - (*enemy_it)->getSize().x)
	//		{
	//			bullet_it = bullet_obj.erase(bullet_it);
	//			enemy_it = enemy_obj.erase(enemy_it);
	//		}
	//		else
	//		{
	//			bullet_it++;
	//			enemy_it++;
	//		}
	//	}
	//}
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
