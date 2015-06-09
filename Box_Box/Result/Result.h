#pragma once
#include <memory>
#include "cinder/Rand.h"
#include "../common.h"
#include "../Player/Player.h"

class Result{
private:
	Font RESULT_font; // �yRESULT�z�\���p�̃t�H���g�T�C�Y��p��
	Font SCORE_font;  // �X�R�A�\���p�̃t�H���g�T�C�Y
	Font text_font;   // ���̑��̕�����\������ׂ̃t�H���g�T�C�Y
	Player player;

	unsigned int r_score;
	unsigned int time;

public:
	Result();
	~Result(){};

	void keyDown(KeyEvent event, unsigned int& scene, unsigned int& time_count, unsigned int& score);
	void setup();
	void update(unsigned int& score, unsigned int& time_count);
	void draw();
};
