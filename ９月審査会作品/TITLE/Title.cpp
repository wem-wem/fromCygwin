#include "Title.h"

#pragma region コンストラクタ
Title::Title(){
	// 変数の初期化
	text_alpha = 0;
	text_color = ColorA(1, 1, 1, 0);
	title_text_color = ColorA(1, 1, 0, 1);
	touch_timer = 0;
	direction_timer = 120.0;

	title_direction_WIDE = Vec2f(-40, -70);
	title_direction_SHOT = Vec2f(40, -30);
}
#pragma endregion


#pragma region フォントの読み込みだけmainで実行してもらう
void Title::setup()
{
	font = Font(loadAsset("font/MyComSquare-Medium.otf"), 40);
}
#pragma endregion


#pragma region タッチをしたらゲーム開始
void Title::getTouch(const bool& istouch,
					 unsigned int& scene,
					 audio::BufferPlayerNodeRef& SELECT_SE)
{
	if (touch_timer > 120)
	{
		if (istouch)
		{
			SELECT_SE->start();
			scene = GAME;
			touch_timer = 0;
			direction_timer = 120;
		}
	}
}
#pragma endregion

#pragma region 更新処理
void Title::update(const bool& istouch,
				   unsigned int& scene,
				   audio::BufferPlayerNodeRef& SELECT_SE)
{
	touch_timer++;
	direction_timer--;

	getTouch(istouch, scene, SELECT_SE);

	// タイトルロゴ演出
	if (direction_timer < 120 && direction_timer > 1)
	{
		title_direction_WIDE = Vec2f(randFloat(-40.f * (direction_timer / 2), -40.f * (-direction_timer / 2)),
									  -70.f);

		title_direction_SHOT = Vec2f(randFloat(40.f * (direction_timer / 2), 40.f * (-direction_timer / 2)),
									 -30.f);
	}

	else if (direction_timer <= 1)
	{
		direction_timer = 1;
		title_direction_WIDE = Vec2f(-40, -70);
		title_direction_SHOT = Vec2f(40, -30);
	}

	// 表示文字の透明度を変化
	text_alpha += 0.05f;
}
#pragma endregion


#pragma region 表示処理
void Title::draw(){
	// 文字の表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::translate(Vec3f(-1.f, 2.f, -50.f));
	gl::rotate(Vec3f(180, 0, 0));
	gl::scale(0.2f, 0.2f, 0.2f);
	gl::drawStringCentered(
		"WIDE",
		title_direction_WIDE, title_text_color, font);
	gl::popModelView();  // ここまで-------------------------------------


	gl::pushModelView(); // ここから-------------------------------------
	gl::translate(Vec3f(-1.f, 2.f, -50.f));
	gl::rotate(Vec3f(180, 0, 0));
	gl::scale(0.2f, 0.2f, 0.2f);
	gl::drawStringCentered(
		"SHOT",
		title_direction_SHOT, title_text_color, font);
	gl::popModelView();  // ここまで-------------------------------------


	gl::pushModelView(); // ここから-------------------------------------
	gl::translate(Vec3f(-1.f, 2.f, -50.f));
	gl::rotate(Vec3f(180, 0, 0));
	gl::scale(0.1f, 0.1f, 0.1f);
	gl::drawStringCentered(
		"TOUCH TO START",
		Vec2f(0, 100), text_color + std::abs(std::sin(text_alpha)), font);
	gl::popModelView();  // ここまで-------------------------------------
}
#pragma endregion