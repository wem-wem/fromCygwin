#pragma once
#include <memory>
#include "cinder/Rand.h"
#include "../common.h"
#include "../GAME/Manager/Manager.h"
#include "../GAME/Player/Player.h"
#include "../GAME/Camera/GameCamera.h"
#include "../GAME/UI/UI.h"

class Result;
typedef std::shared_ptr<Result> ResultSP;

class Result{
private:
	Font RESULT_font; // �yRESULT�z�\���p�̃t�H���g�T�C�Y��p��
	Font SCORE_font;  // �X�R�A�\���p�̃t�H���g�T�C�Y
	Font text_font;   // ���̑��̕�����\������ׂ̃t�H���g�T�C�Y
	ManagerSP manager = ManagerSP(new Manager);
	GameUISP UI = GameUISP(new GameUI);
	PlayerSP player = PlayerSP(new Player);
	GameCameraSP camera = GameCameraSP(new GameCamera);

	// �X�R�A�\���̉��o�p
	unsigned int view_score;
	float direction_timer_RESULT;
	float direction_timer_SCORE;
	float direction_timer_TEXT;

	// ��ʂ��؂�ւ��������Ɍ���ăV�[����؂�ւ��Ȃ��ׂ̃^�C�}�[
	unsigned int touch_timer;
public:
	Result();
	~Result(){};

	void getTouch(unsigned int&, audio::BufferPlayerNodeRef&,
				  const bool&, unsigned int&);
	void setup();
	void update(unsigned int&);
	void draw();
};
