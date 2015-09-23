#include "UI.h"

GameUI::GameUI(){
	_time = 20 * 60;
	_score = 0;
}

void GameUI::setup()
{
	font = Font(loadAsset("font/MyComSquare-Medium.otf"), 15);
}


void GameUI::update()
{
	_time -= 1;
}

void GameUI::draw()
{
	// 残り時間の表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::translate(Vec3f(-5.f, 10.f, -50.f));
	gl::rotate(Vec3f(160.f, 0, 0));
	gl::scale(0.2f, 0.2f, 0.2f);
	gl::drawStringRight(
		"TIME : " + std::to_string(_time / 60),
		Vec2f(0, -10.f), Color(1.f, 0.5f, 0), font);
	gl::popModelView();  // ここまで-------------------------------------


	// スコア表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::translate(Vec3f(25.f, 10.f, -50.f));
	gl::rotate(Vec3f(160.f, 0, 0));
	gl::scale(0.2f, 0.2f, 0.2f);
	gl::drawStringRight(
		std::to_string(_score) + " : POINT",
		Vec2f(0, -10.f), Color(1.f, 0, 0.5f), font);
	gl::popModelView();  // ここまで-------------------------------------
}

