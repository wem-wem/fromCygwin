#include "Manager.h"

Manager::Manager(){
	shot_timer_ = -1;
	delete_line = -10.0f;
}

void Manager::setup()
{
	player->setup();
	enemy->setup();
}

void Manager::update(Vec2i& direction, bool& istouch)
{
	player->update(direction);
	enemy->update();

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
			bullet_it = bullet_obj.erase(bullet_it++);
		}

		// 次の弾のアドレスへ移動
		bullet_it++;
	}
}


// プレイヤー・敵・弾の描画をまとめる
void Manager::draw()
{
	player->draw();
	enemy->draw();

	for (auto& bullets : bullet_obj)
	{
		bullets->draw();
	}
}
