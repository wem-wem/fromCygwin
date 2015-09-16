#include "Bullet.h"

Bullet::Bullet(Vec3f player_pos){
	pos_ = player_pos;
	speed_ = Vec3f(0, 0, -0.1f);
	life = true;
	setup();
}

void Bullet::setup()
{
	obj = new ObjLoader(loadAsset("Player/bullet.obj"));
	obj->load(&mesh, true, true, false);
}


void Bullet::update()
{
	pos_ += speed_;
}


void Bullet::draw()
{
	gl::pushModelView();
	gl::translate(pos_);
	gl::scale(Vec3f(0.2f, 0.2f, 0.2f));
	gl::draw(mesh);
	gl::popModelView();
}
