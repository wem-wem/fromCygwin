#pragma once
#include <memory>
#include "cinder/Rand.h"
#include "../common.h"

class Title;
typedef std::shared_ptr<Title> TitleSP;

class Title{
public:
	Font font;
	ColorA text_color;
	ColorA title_text_color;
	float text_alpha;

	// タイトルロゴ演出用変数
	Vec2f title_direction_WIDE;
	Vec2f title_direction_SHOT;
	float direction_timer;

	// 画面が切り替わった直後に誤ってシーンを切り替えない為のタイマー
	unsigned int touch_timer;

	Title();
	~Title(){};

	void getTouch(const bool&, unsigned int&,
				  audio::BufferPlayerNodeRef&);
	void setup();
	void update(const bool&, unsigned int&,
				audio::BufferPlayerNodeRef&);
	void draw();
};