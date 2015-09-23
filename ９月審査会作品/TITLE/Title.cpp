#include "Title.h"

#pragma region �R���X�g���N�^
Title::Title(){
	// �ϐ��̏�����
	text_alpha = 0;
	text_color = ColorA(1, 1, 1, 0);
	title_text_color = ColorA(1, 1, 0, 1);
	touch_timer = 0;
	direction_timer = 120.0;

	title_direction_WIDE = Vec2f(-40, -70);
	title_direction_SHOT = Vec2f(40, -30);
}
#pragma endregion


#pragma region �t�H���g�̓ǂݍ��݂���main�Ŏ��s���Ă��炤
void Title::setup()
{
	font = Font(loadAsset("font/MyComSquare-Medium.otf"), 40);
}
#pragma endregion


#pragma region �^�b�`��������Q�[���J�n
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

#pragma region �X�V����
void Title::update(const bool& istouch,
				   unsigned int& scene,
				   audio::BufferPlayerNodeRef& SELECT_SE)
{
	touch_timer++;
	direction_timer--;

	getTouch(istouch, scene, SELECT_SE);

	// �^�C�g�����S���o
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

	// �\�������̓����x��ω�
	text_alpha += 0.05f;
}
#pragma endregion


#pragma region �\������
void Title::draw(){
	// �����̕\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::translate(Vec3f(-1.f, 2.f, -50.f));
	gl::rotate(Vec3f(180, 0, 0));
	gl::scale(0.2f, 0.2f, 0.2f);
	gl::drawStringCentered(
		"WIDE",
		title_direction_WIDE, title_text_color, font);
	gl::popModelView();  // �����܂�-------------------------------------


	gl::pushModelView(); // ��������-------------------------------------
	gl::translate(Vec3f(-1.f, 2.f, -50.f));
	gl::rotate(Vec3f(180, 0, 0));
	gl::scale(0.2f, 0.2f, 0.2f);
	gl::drawStringCentered(
		"SHOT",
		title_direction_SHOT, title_text_color, font);
	gl::popModelView();  // �����܂�-------------------------------------


	gl::pushModelView(); // ��������-------------------------------------
	gl::translate(Vec3f(-1.f, 2.f, -50.f));
	gl::rotate(Vec3f(180, 0, 0));
	gl::scale(0.1f, 0.1f, 0.1f);
	gl::drawStringCentered(
		"TOUCH TO START",
		Vec2f(0, 100), text_color + std::abs(std::sin(text_alpha)), font);
	gl::popModelView();  // �����܂�-------------------------------------
}
#pragma endregion