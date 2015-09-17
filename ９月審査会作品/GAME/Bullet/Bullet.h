#pragma once
#include "../../common.h"
#include "../Object.h"

class Bullet;
typedef std::shared_ptr<Bullet> BulletSP;

// �e�P�����̏����ɕK�v�ȕϐ��E�֐�
class Bullet : public Object{
private:
	bool  is_dead;
	Vec2f size;
	ObjLoader* obj;
	TriMesh mesh;

public:
	Bullet(Vec3f);
	Vec2f& getSize(){ return size; }
	virtual void setup();
	virtual void update();
	virtual void draw();

	// ���̊֐����Ă΂ꂽ�玀�S�����Ƃ���
	void hit();
	bool isDead();
};
