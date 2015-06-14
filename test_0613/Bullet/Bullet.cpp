#include "Bullet.h"

Bullet::Bullet(){}

void Bullet::setup(){
	bullet_image = loadImage(loadAsset("shot.png"));
}


void Bullet::keyDown(KeyEvent event){
	if (event.getCode() == KeyEvent::KEY_SPACE){
		_getKey_space = true;
	}
}


void Bullet::keyUp(KeyEvent event){
	if (event.getCode() == KeyEvent::KEY_SPACE){
		_getKey_space = false;
	}
}


void Bullet::update(){ 
	// ‰æ–ÊŠO‚Éo‚½‚ç’e‚ðÁ‚·
	for (auto itr : obj){
		if (itr.pos.x > getWindowWidth() || itr.pos.x < 0){
			if (itr.pos.y > getWindowHeight() || itr.pos.y < 0){
				obj.erase;
			}
		}
	}
}


void Bullet::draw(){
	if (_getKey_space){
		PlayerSP player = PlayerSP(new Player());
		obj.push_back({ player->_pos, Vec2f(0, 1), true });
	}

	gl::pushModelView();
	gl::translate(Vec3f(_pos + _speed, 0));
	gl::draw(bullet_image);
	gl::popModelView();
}