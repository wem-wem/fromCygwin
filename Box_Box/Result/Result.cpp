#include "Result.h"
Result::Result(){}

#pragma region フォントの読み込み用セットアップ
void Result::setup(){
	RESULT_font = Font(loadAsset("font/MyComSquare-Medium.otf"), 65);
	SCORE_font = Font(loadAsset("font/MyComSquare-Medium.otf"), 50);
	text_font = Font(loadAsset("font/MyComSquare-Medium.otf"), 30);
}
#pragma endregion


#pragma region キーを押された時の処理
void Result::keyDown(KeyEvent event, unsigned int& scene, unsigned int& time_count, unsigned int& score){
	if (event.getCode() == KeyEvent::KEY_g){
		scene = GAME;
		time_count = 0;
		score = 0;
	}

	if (event.getCode() == KeyEvent::KEY_t){
		scene = TITLE;
		time_count = 0;
		score = 0;
	}
}


#pragma region 更新処理
void Result::update(unsigned int& score, unsigned int& time_count){
	r_score = score;
	time = time_count / 60;


}
#pragma endregion


#pragma region 描画処理
void Result::draw(){
	// 【RESULT】表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::rotate(Vec3f(160, 0, 0));
	gl::drawStringCentered(
		" R E S U L T ",
		Vec2f(0, -170), Color(1, 1, 1), RESULT_font);
	gl::popModelView();  // ここまで-------------------------------------

	// スコアの表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::rotate(Vec3f(160, 0, 0));
	gl::drawStringCentered(
		"S C O R E : " + std::to_string(r_score),
		Vec2f(0, -80), Color(1, 1, 1), SCORE_font);
	gl::popModelView();  // ここまで-------------------------------------

	// 合計プレイ時間の表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::rotate(Vec3f(160, 0, 0));
	gl::drawStringCentered(
		" TOTALTIME : " + std::to_string(time),
		Vec2f(0, -20), Color(1, 1, 1), SCORE_font);
	gl::popModelView();  // ここまで-------------------------------------


	// 操作キーの表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::rotate(Vec3f(160, 0, 0));
	gl::drawStringCentered(
		" NEXT GAME [G] KEY",
		Vec2f(0, 60), Color(1, 1, 1), text_font);
	gl::popModelView();  // ここまで-------------------------------------

	gl::pushModelView(); // ここから-------------------------------------
	gl::rotate(Vec3f(160, 0, 0));
	gl::drawStringCentered(
		" BACK TITLE [T] KEY",
		Vec2f(0, 120), Color(1, 1, 1), text_font);
	gl::popModelView();  // ここまで-------------------------------------

}
#pragma endregion