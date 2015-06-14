#include "Player.h"

Player::Player(){
	_rx = 0; 
	_ry = 0;
	_speed = Vec2f(1, 1);
	_pos = Vec2f(0, 0);
	_get_w = _get_a = _get_s = _get_d = _get_space = false;
};


void Player::setup(){
	player_image = loadImage(loadAsset("player.png"));
}


void Player::keyDown(KeyEvent event){
	if (event.getCode() == KeyEvent::KEY_w){
		_get_w = true;
	}

	if (event.getCode() == KeyEvent::KEY_a){
		_get_a = true;
	}

	if (event.getCode() == KeyEvent::KEY_s){
		_get_s = true;
	}

	if (event.getCode() == KeyEvent::KEY_d){
		_get_d = true;
	}

	if (event.getCode() == KeyEvent::KEY_SPACE){
		_get_space = true;
	}
}


void Player::keyUp(KeyEvent event){
	if (event.getCode() == KeyEvent::KEY_w){
		_get_w = false;
	}

	if (event.getCode() == KeyEvent::KEY_a){
		_get_a = false;
	}

	if (event.getCode() == KeyEvent::KEY_s){
		_get_s = false;
	}

	if (event.getCode() == KeyEvent::KEY_d){
		_get_d = false;
	}

	if (event.getCode() == KeyEvent::KEY_SPACE){
		_get_space = false;
	}
}


void Player::update(){

	console() << _pos.y << std::endl;

	if (_get_w){
		_pos.y -= _speed.y;
	}

	if (_get_a){
		_pos.x -= _speed.x;
	}

	if (_get_s){
		_pos.y += _speed.y;
	}

	if (_get_d){
		_pos.x += _speed.x;
	}
}


void Player::draw(){
	player_image.bind();

	gl::pushModelView();
	gl::translate(Vec3f(_pos, 0));
	gl::draw(player_image);
	gl::popModelView();

	player_image.unbind();
}

