#include "Result.h"
Result::Result(){}

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


#pragma region �X�V����
void Result::update(unsigned int& score, unsigned int& time_count){
	r_score = score;
	time = time_count / 60;


}
#pragma endregion


#pragma region �`�揈��
void Result::draw(){
	// �yRESULT�z�\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::rotate(Vec3f(160, 0, 0));
	gl::drawStringCentered(
		" R E S U L T ",
		Vec2f(0, -170), Color(1, 1, 1), RESULT_font);
	gl::popModelView();  // �����܂�-------------------------------------

	// �X�R�A�̕\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::rotate(Vec3f(160, 0, 0));
	gl::drawStringCentered(
		"S C O R E : " + std::to_string(r_score),
		Vec2f(0, -80), Color(1, 1, 1), SCORE_font);
	gl::popModelView();  // �����܂�-------------------------------------

	// ���v�v���C���Ԃ̕\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::rotate(Vec3f(160, 0, 0));
	gl::drawStringCentered(
		" TOTALTIME : " + std::to_string(time),
		Vec2f(0, -20), Color(1, 1, 1), SCORE_font);
	gl::popModelView();  // �����܂�-------------------------------------


	// ����L�[�̕\��
	gl::pushModelView(); // ��������-------------------------------------
	gl::rotate(Vec3f(160, 0, 0));
	gl::drawStringCentered(
		" NEXT GAME [G] KEY",
		Vec2f(0, 60), Color(1, 1, 1), text_font);
	gl::popModelView();  // �����܂�-------------------------------------

	gl::pushModelView(); // ��������-------------------------------------
	gl::rotate(Vec3f(160, 0, 0));
	gl::drawStringCentered(
		" BACK TITLE [T] KEY",
		Vec2f(0, 120), Color(1, 1, 1), text_font);
	gl::popModelView();  // �����܂�-------------------------------------

}
#pragma endregion