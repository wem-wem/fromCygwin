#pragma once
#include "../Player/Player.h"
#include "../Bullet/Bullet.h"
#include "../Enemy/Enemy.h"
#include "../Camera/GameCamera.h"
#include "../UI/UI.h"
#include "../Particle/Particle.h"

#include <list>

class Manager;
typedef std::shared_ptr<Manager> ManagerSP;

class Manager{
private:
	PlayerSP player = PlayerSP(new Player);
	GameUISP UI = GameUISP(new GameUI);
	GameCameraSP camera = GameCameraSP(new GameCamera);
	ParticleSP particle = ParticleSP(new Particle);

	// 複数の敵と弾を処理する為にリストで管理する
	std::list<EnemySP> enemy_obj;
	std::list<BulletSP> bullet_obj;

	// 一定間隔で作動するタイマー
	int shot_timer_;
	int enemy_timer_;
	// 描画する距離を制限する
	float delete_line;
	float enemy_delete_line_;

	// パーティクルの描画時間
	int particle_timer;
public:
	Manager();

	void setup();
	void update(Vec2i&, bool&, unsigned int&, unsigned int&,
				audio::BufferPlayerNodeRef&, audio::BufferPlayerNodeRef&);
	void draw(gl::Material&, gl::Material&, gl::Material&);
	bool collision(EnemySP&, BulletSP&);
};

