#include "Bullet.h"

Bullet::Bullet(){
	// 画像の読み込み
	bullet_image = loadImage(loadAsset("shot.png"));
}

// 更新処理(必要なもの書き出し中)
void Bullet::update(){ 
	//// スペースキーが押されたら弾を作る
	//if (getKey_space){
	//	PlayerSP player = PlayerSP(new Player());
	//	obj.push_back({ player->pos, Vec2f(0, 1), true });
	//}

	//// 弾の pos を speed の分だけ移動させる
	//for (auto& itr : obj){
	//	pos += speed;
	//}

	//// 画面外に出たら弾を消す
	//for (auto itr : obj){
	//	if (itr.pos.x > getWindowWidth() || itr.pos.x < 0){
	//		if (itr.pos.y > getWindowHeight() || itr.pos.y < 0){
	//			obj.erase;
	//		}
	//	}
	//}
}


void Bullet::draw(){
	// 弾の数だけ表示させる
//	for (auto& itr : obj ){
		gl::pushModelView();
		gl::translate(Vec3f(pos + speed, 0));
		gl::draw(bullet_image);
		gl::popModelView();
//	}
}
