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

	// �����̒e����������ׂɃ��X�g�ŊǗ�����
	std::list<BulletSP> bullet_obj;

	// �e�����Ԋu�Ŕ��˂����悤�Ƀ^�C�}�[���Z�b�g
	int shot_timer_;

	// �e��`�悷�鋗���𐧌�����
	float delete_line;

public:
	Manager();

	void setup();
	void update(Vec2i&, bool&);
	void draw();
};

