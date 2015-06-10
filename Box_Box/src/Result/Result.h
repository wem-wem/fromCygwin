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
	float RESULT_rx;
	float SCORE_rx;
	float text_rx;

	unsigned int score_direct; // スコア表示の演出用
	unsigned int time_direct;  // 合計時間表示の演出用

public:
	Result();
	~Result(){};

	void keyDown(KeyEvent event, unsigned int& scene,
				unsigned int& time_count, unsigned int& score,
				audio::BufferPlayerNodeRef& SELECT_SE);

	void setup();
	void update(unsigned int& score, unsigned int& time_count);
	void draw();
};
