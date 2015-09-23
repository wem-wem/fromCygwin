#include "Result.h"
Result::Result(){
	view_score = 0;
	touch_timer = 0;
	direction_timer_RESULT = 600;
	direction_timer_SCORE = 1200;
	direction_timer_TEXT = 1500;
}

#pragma region �t�H���g�̓ǂݍ��ݗp�Z�b�g�A�b�v
void Result::setup(){
	RESULT_font = Font(loadAsset("font/MyComSquare-Medium.otf"), 55);
	SCORE_font = Font(loadAsset("font/MyComSquare-Medium.otf"), 45);
	text_font = Font(loadAsset("font/MyComSquare-Medium.otf"), 40);
}
#pragma endregion


#pragma region �L�[�������ꂽ���̏���
void Result::getTouch(unsigned int& scene,
					  audio::BufferPlayerNodeRef& SELECT_SE,
					  const bool& istouch, unsigned int& score)
{
	if (touch_timer > 120)
	{
		if (istouch)
		{
			SELECT_SE->start();
			score = 0;
			view_score = 0;
			scene = TITLE;
			touch_timer = 0;
			direction_timer_RESULT = 600;
			direction_timer_SCORE = 1200;
			direction_timer_TEXT = 1500;
		}
	}
}
#pragma endregion

#pragma region �X�V����
void Result::update(unsigned int& score)
{
	touch_timer++;
	// ���U���g���o�p�^�C�}�[
	if (direction_timer_RESULT > 0) { direction_timer_RESULT -= 20; }
	else{ direction_timer_RESULT = 0; }

	if (direction_timer_SCORE > 0) { direction_timer_SCORE -= 20; }
	else{ direction_timer_SCORE = 0; }

	if (direction_timer_TEXT > 0) { direction_timer_TEXT -= 20; }
	else{ direction_timer_TEXT = 0; }

	view_score = score;

	player->setPos(Vec3f(0, 0, 0));
	camera->setAngle(0.0f);
}
#pragma endregion


#pragma region �`�揈��
void Result::draw()
{
	// �yRESULT�z�\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::translate(Vec3f(-1.f, 2.f, -50.f));
	gl::rotate(Vec3f(180, 0, 0));
	gl::scale(0.1f, 0.1f, 0.1f);
	gl::drawStringCentered(
		" R E S U L T ",
		Vec2f(0, -120 - direction_timer_RESULT), Color(1, 0.2f, 0.2f), RESULT_font);
	gl::popModelView();  // �����܂�-------------------------------------


	// �X�R�A�̕\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::translate(Vec3f(-1.f, 2.f, -50.f));
	gl::rotate(Vec3f(180, 0, 0));
	gl::scale(0.1f, 0.1f, 0.1f);
	gl::drawStringCentered(
		"S C O R E : " + std::to_string(static_cast<unsigned int>(view_score)),
		Vec2f(0 - direction_timer_SCORE, -30), Color(1, 1, 1), SCORE_font);
	gl::popModelView();  // �����܂�-------------------------------------


	// ����\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::translate(Vec3f(-1.f, 2.f, -50.f));
	gl::rotate(Vec3f(180, 0, 0));
	gl::scale(0.1f, 0.1f, 0.1f);
	gl::drawStringCentered(
		" TOUCH TO TITLE",
		Vec2f(0 + direction_timer_TEXT, 100), Color(1, 1, 1), text_font);
	gl::popModelView();  // �����܂�-------------------------------------
}
#pragma endregion
