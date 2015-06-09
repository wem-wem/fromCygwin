#pragma once
#include <memory>
#include "cinder/Rand.h"
#include "../common.h"
#include "../Player/Player.h"

class Result{
private:
	Font RESULT_font; // 【RESULT】表示用のフォントサイズを用意
	Font SCORE_font;  // スコア表示用のフォントサイズ
	Font text_font;   // その他の文字を表示する為のフォントサイズ
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
