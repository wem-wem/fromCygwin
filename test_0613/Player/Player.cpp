#include "Player.h"

Player::Player(){
	rx = 0; 
	ry = 0;
	speed = Vec2f(1, 1);
	pos = Vec2f(0, 0);
	get_w = get_a = get_s = get_d = getKey_space = false;

	// 画像の読み込み
	player_image = loadImage(loadAsset("player.png"));
};


void Player::keyDown(KeyEvent event){
#pragma region 移動キー
	if (event.getCode() == KeyEvent::KEY_w){
		get_w = true;
	}

	if (event.getCode() == KeyEvent::KEY_a){
		get_a = true;
	}

	if (event.getCode() == KeyEvent::KEY_s){
		get_s = true;
	}

	if (event.getCode() == KeyEvent::KEY_d){
		get_d = true;
	}
#pragma endregion

	// ショット用キー
	if (event.getCode() == KeyEvent::KEY_SPACE){
		getKey_space = true;
	}
}


void Player::keyUp(KeyEvent event){
#pragma region 移動キー
	if (event.getCode() == KeyEvent::KEY_w){
		get_w = false;
	}

	if (event.getCode() == KeyEvent::KEY_a){
		get_a = false;
	}

	if (event.getCode() == KeyEvent::KEY_s){
		get_s = false;
	}

	if (event.getCode() == KeyEvent::KEY_d){
		get_d = false;
	}
#pragma endregion

	// ショット用キー
	if (event.getCode() == KeyEvent::KEY_SPACE){
		getKey_space = false;
	}
}

void Player::CreateBullet(){
	if (getKey_space){
		BulletSP newBullet = BulletSP(new Bullet());
	}
}


void Player::update(){

	console() << pos.y << std::endl;

	if (get_w){
		pos.y -= speed.y;
	}

	if (get_a){
		pos.x -= speed.x;
	}

	if (get_s){
		pos.y += speed.y;
	}

	if (get_d){
		pos.x += speed.x;
	}
}


void Player::draw(){
	player_image.bind();
	gl::pushModelView();
	gl::translate(Vec3f(pos, 0));
	gl::draw(player_image);
	gl::popModelView();
	player_image.unbind();

}

