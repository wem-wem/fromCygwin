#pragma once
#include "../Player/Player.h"
#include "../Bullet/Bullet.h"
#include "../Enemy/Enemy.h"

#include <list>

class Manager;
typedef std::shared_ptr<Manager> ManagerSP;

class Manager{
private:
	PlayerSP player = PlayerSP(new Player);
	EnemySP enemy = EnemySP(new Enemy);

	// 複数の弾を処理する為にリストで管理する
	std::list<BulletSP> bullet_obj;

	// 弾が一定間隔で発射されるようにタイマーをセット
	int shot_timer_;

	// 弾を描画する距離を制限する
	float delete_line;

public:
	Manager();

	void setup();
	void update(Vec2i&, bool&);
	void draw();
};

