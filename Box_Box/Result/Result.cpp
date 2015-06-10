#include "Result.h"
Result::Result(){
	r_score = 0;
	time = 0;
	RESULT_rx = 0;
	SCORE_rx = 0;
	text_rx = 0;
}

#pragma region �t�H���g�̓ǂݍ��ݗp�Z�b�g�A�b�v
void Result::setup(){
	RESULT_font = Font(loadAsset("font/MyComSquare-Medium.otf"), 65);
	SCORE_font = Font(loadAsset("font/MyComSquare-Medium.otf"), 50);
	text_font = Font(loadAsset("font/MyComSquare-Medium.otf"), 30);
}
#pragma endregion


#pragma region �L�[�������ꂽ���̏���
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

#pragma region �X�V����
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


#pragma region �`�揈��
void Result::draw(){
	// �yRESULT�z�\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::rotate(Vec3f(0 + RESULT_rx, 0, 0));
	gl::drawStringCentered(
		" R E S U L T ",
		Vec2f(0, -170), Color(1, 0, 0), RESULT_font);
	gl::popModelView();  // �����܂�-------------------------------------


	// �X�R�A�̕\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::rotate(Vec3f(0 + SCORE_rx, 0, 0));
	gl::drawStringCentered(
		"S C O R E : " + std::to_string(static_cast<int>(score_direct)),
		Vec2f(0, -80), Color(1, 1, 1), SCORE_font);
	gl::popModelView();  // �����܂�-------------------------------------


	// ���v�v���C���Ԃ̕\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::rotate(Vec3f(0 + SCORE_rx, 0, 0));
	gl::drawStringCentered(
		" TOTALTIME : " + std::to_string(static_cast<int>(time_direct)),
		Vec2f(0, -20), Color(1, 1, 1), SCORE_font);
	gl::popModelView();  // �����܂�-------------------------------------


	// ����L�[�̕\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::rotate(Vec3f(0 + text_rx, 0, 0));
	gl::drawStringCentered(
		" NEXT GAME [G] KEY",
		Vec2f(0, 60), Color(1, 1, 1), text_font);
	gl::popModelView();  // �����܂�-------------------------------------

	gl::pushModelView(); // ��������-------------------------------------
	gl::rotate(Vec3f(0 + text_rx, 0, 0));
	gl::drawStringCentered(
		" BACK TITLE [T] KEY",
		Vec2f(0, 120), Color(1, 1, 1), text_font);
	gl::popModelView();  // �����܂�-------------------------------------

}
#pragma endregion
