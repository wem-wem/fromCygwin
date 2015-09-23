#pragma once
#include "../Player/Player.h"
#include "../Bullet/Bullet.h"
#include "../Enemy/Enemy.h"
#include "../Camera/GameCamera.h"
#include "../UI/UI.h"

#include <list>

class Manager;
typedef std::shared_ptr<Manager> ManagerSP;

class Manager{
private:
	PlayerSP player = PlayerSP(new Player);
	GameUISP UI = GameUISP(new GameUI);
	GameCameraSP camera = GameCameraSP(new GameCamera);

	// •¡”‚Ì“G‚Æ’e‚ğˆ—‚·‚éˆ×‚ÉƒŠƒXƒg‚ÅŠÇ—‚·‚é
	std::list<EnemySP> enemy_obj;
	std::list<BulletSP> bullet_obj;

	// ’e‚ªˆê’èŠÔŠu‚Å”­Ë‚³‚ê‚é‚æ‚¤‚Éƒ^ƒCƒ}[‚ğƒZƒbƒg
	int shot_timer_;
	// ’e‚ğ•`‰æ‚·‚é‹——£‚ğ§ŒÀ‚·‚é
	float delete_line;

	int enemy_timer_;
	float enemy_delete_line_;

public:
	Manager();

	void setup();
	void update(Vec2i&, bool&, unsigned int&, unsigned int&,
				audio::BufferPlayerNodeRef&, audio::BufferPlayerNodeRef&);
	void draw();
	bool collision(EnemySP&, BulletSP&);
};

