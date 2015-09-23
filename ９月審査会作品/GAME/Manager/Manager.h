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

	// �����̓G�ƒe����������ׂɃ��X�g�ŊǗ�����
	std::list<EnemySP> enemy_obj;
	std::list<BulletSP> bullet_obj;

	// ���Ԋu�ō쓮����^�C�}�[
	int shot_timer_;
	int enemy_timer_;
	// �`�悷�鋗���𐧌�����
	float delete_line;
	float enemy_delete_line_;

	// �p�[�e�B�N���̕`�掞��
	int particle_timer;
public:
	Manager();

	void setup();
	void update(Vec2i&, bool&, unsigned int&, unsigned int&,
				audio::BufferPlayerNodeRef&, audio::BufferPlayerNodeRef&);
	void draw(gl::Material&, gl::Material&, gl::Material&);
	bool collision(EnemySP&, BulletSP&);
};

