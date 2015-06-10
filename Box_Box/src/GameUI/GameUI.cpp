#include "GameUI.h"

GameUI::GameUI(){
	_time = 20 * 60;
}

void GameUI::setup(){
	font = Font(loadAsset("font/MyComSquare-Medium.otf"), 15);
}


void GameUI::update(unsigned int& score, unsigned int& scene, Item& item, FallCube& cube){
	_time -= 1;
	_score = score;

	if (_time <= 0){
		scene = RESULT;
		_time = 20 * 60;
	}
}

void GameUI::draw(){
	// 残り時間の表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::rotate(Vec3f(160, 0, 0));
	gl::drawStringRight(
		"TIME : " + std::to_string(_time / 60),
		Vec2f(-65, -115), Color(1, 0, 0), font);
	gl::popModelView();  // ここまで-------------------------------------


	// スコア表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::rotate(Vec3f(160, 0, 0));
	gl::drawStringRight(
		std::to_string(_score) + " : POINT",
		Vec2f(160, -115), Color(1, 0, 0), font);
	gl::popModelView();  // ここまで-------------------------------------
}