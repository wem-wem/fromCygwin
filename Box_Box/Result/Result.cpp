#include "Result.h"
Result::Result(){
	r_score = 0;
	time = 0;
	RESULT_rx = 0;
	SCORE_rx = 0;
	text_rx = 0;
}

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
		score = 0;
		time_count = 0;
		RESULT_rx = 0;
		SCORE_rx = 0;
		text_rx = 0;
		score_direct = 0;
		scene = GAME;
	}

	if (event.getCode() == KeyEvent::KEY_t){
		score = 0;
		time_count = 0;
		RESULT_rx = 0;
		SCORE_rx = 0;
		text_rx = 0;
		score_direct = 0;
		scene = TITLE;
	}
}
#pragma endregion

#pragma region 更新処理
void Result::update(unsigned int& score, unsigned int& time_count){
	r_score = score;
	time = time_count / 60;

	if (RESULT_rx < 160){
		RESULT_rx += 2;
	}

	if (SCORE_rx < 160){
		SCORE_rx++;
		score_direct = randInt(0, 1000);
		time_direct = randInt(0, 1000);
	}
	else if (SCORE_rx == 160){
		score_direct = score;
		time_direct = time_count / 60;
	}
	
	if (text_rx < 160){
		text_rx += 0.5;
	}

}
#pragma endregion


#pragma region 描画処理
void Result::draw(){
	// 【RESULT】表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::rotate(Vec3f(0 + RESULT_rx, 0, 0));
	gl::drawStringCentered(
		" R E S U L T ",
		Vec2f(0, -170), Color(1, 0, 0), RESULT_font);
	gl::popModelView();  // ここまで-------------------------------------


	// スコアの表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::rotate(Vec3f(0 + SCORE_rx, 0, 0));
	gl::drawStringCentered(
		"S C O R E : " + std::to_string(static_cast<int>(score_direct)),
		Vec2f(0, -80), Color(1, 1, 1), SCORE_font);
	gl::popModelView();  // ここまで-------------------------------------


	// 合計プレイ時間の表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::rotate(Vec3f(0 + SCORE_rx, 0, 0));
	gl::drawStringCentered(
		" TOTALTIME : " + std::to_string(static_cast<int>(time_direct)),
		Vec2f(0, -20), Color(1, 1, 1), SCORE_font);
	gl::popModelView();  // ここまで-------------------------------------


	// 操作キーの表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::rotate(Vec3f(0 + text_rx, 0, 0));
	gl::drawStringCentered(
		" NEXT GAME [G] KEY",
		Vec2f(0, 60), Color(1, 1, 1), text_font);
	gl::popModelView();  // ここまで-------------------------------------

	gl::pushModelView(); // ここから-------------------------------------
	gl::rotate(Vec3f(0 + text_rx, 0, 0));
	gl::drawStringCentered(
		" BACK TITLE [T] KEY",
		Vec2f(0, 120), Color(1, 1, 1), text_font);
	gl::popModelView();  // ここまで-------------------------------------

}
#pragma endregion
