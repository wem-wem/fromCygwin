#include "Result.h"
Result::Result(){
	RESULT_rx = 0;
	SCORE_rx = 0;
	text_rx = 0;
	random_score = 0;
	touch_timer = 0;

	sccore_direction_RESULT = Vec2f(0, -120);
	sccore_direction_SCORE = Vec2f(0, -30);
	sccore_direction_TEXT = Vec2f(0, 100);
}

#pragma region フォントの読み込み用セットアップ
void Result::setup(){
	RESULT_font = Font(loadAsset("font/MyComSquare-Medium.otf"), 55);
	SCORE_font = Font(loadAsset("font/MyComSquare-Medium.otf"), 45);
	text_font = Font(loadAsset("font/MyComSquare-Medium.otf"), 40);
}
#pragma endregion


#pragma region キーを押された時の処理
void Result::getTouch(unsigned int& scene,
					 audio::BufferPlayerNodeRef& SELECT_SE,
					 const bool& istouch, unsigned int& score)
{
	if (touch_timer > 120)
	{
		if (istouch)
		{
			SELECT_SE->start();
			RESULT_rx = 0;
			SCORE_rx = 0;
			text_rx = 0;
			score = 0;
			random_score = 0;
			scene = TITLE;
			touch_timer = 0;
		}
	}
}
#pragma endregion

#pragma region 更新処理
void Result::update(unsigned int& score)
{
	touch_timer++;

	if (RESULT_rx < 180)
	{
		RESULT_rx += 2;
	}

	if (SCORE_rx < 180)
	{
		SCORE_rx++;
		random_score = randInt(0, 100);
	}
	else if (SCORE_rx == 180)
	{
		random_score = score;
	}

	if (text_rx < 180)
	{
		text_rx += 0.5;
	}
	player->setPos(Vec3f(0, 0, 0));
	camera->setAngle(0.0f);
}
#pragma endregion


#pragma region 描画処理
void Result::draw()
{
	// 【RESULT】表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::translate(Vec3f(-1.f, 2.f, -50.f));
	gl::rotate(Vec3f(0 + RESULT_rx, 0, 0));
	gl::scale(0.1f, 0.1f, 0.1f);
	gl::drawStringCentered(
		" R E S U L T ",
		Vec2f(0, -120), Color(1, 0.2f, 0.2f), RESULT_font);
	gl::popModelView();  // ここまで-------------------------------------


	// スコアの表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::translate(Vec3f(-1.f, 2.f, -50.f));
	gl::rotate(Vec3f(0 + SCORE_rx, 0, 0));
	gl::scale(0.1f, 0.1f, 0.1f);
	gl::drawStringCentered(
		"S C O R E : " + std::to_string(static_cast<unsigned int>(random_score)),
		Vec2f(0, -30), Color(1, 1, 1), SCORE_font);
	gl::popModelView();  // ここまで-------------------------------------


	// 操作表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::translate(Vec3f(-1.f, 2.f, -50.f));
	gl::rotate(Vec3f(0 + text_rx, 0, 0));
	gl::scale(0.1f, 0.1f, 0.1f);
	gl::drawStringCentered(
		" TOUCH TO TITLE",
		Vec2f(0, 100), Color(1, 1, 1), text_font);
	gl::popModelView();  // ここまで-------------------------------------

}
#pragma endregion
