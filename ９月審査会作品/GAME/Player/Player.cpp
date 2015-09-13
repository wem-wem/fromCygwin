#include "Player.h"

Player::Player(){
	pos_ = Vec3f(0, 0, 0);
	speed_ = Vec3f(0.02f, 0.02f, 0.0f);
	move_max = Vec2f(3.f, 2.f);
}


void Player::setup()
{
	obj = new ObjLoader(loadAsset("Player/Player.obj"));
	obj->load(&mesh, true, true, false);
}


void Player::update(Vec2i direction)
{
	// ˆÚ“®ˆ—
	if (direction.x == RIGHT && pos_.x < move_max.x)
	{
		pos_ += Vec3f(speed_.x, 0, 0);
	}

	if (direction.x == LEFT&& pos_.x > -move_max.x)
	{
		pos_ -= Vec3f(speed_.x, 0, 0);
	}


	if (direction.y == DOWN && pos_.y > -move_max.y)
	{
		pos_ -= Vec3f(0, speed_.y, 0);
	}

	if (direction.y == UP && pos_.y < move_max.y)
	{
		pos_ += Vec3f(0, speed_.y, 0);
	}
}


void Player::draw()
{
	// ©‹@
	gl::pushModelView();
	gl::translate(pos_);
	gl::scale(Vec3f(0.5f, 0.5f, 0.5f));
	gl::draw(mesh);
	gl::popModelView();
}
