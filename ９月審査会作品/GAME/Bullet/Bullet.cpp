#include "Bullet.h"

Bullet::Bullet(Vec3f player_pos){
	pos_ = player_pos;
	speed_ = Vec3f(0, 0, -0.1f);
	is_dead = false;
	size = Vec2f(1.0f, 1.0f);
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


void Bullet::hit()
{
	this->is_dead = true;
}

bool Bullet::isDead()
{
	return is_dead;
}