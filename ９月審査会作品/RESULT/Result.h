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
	Font RESULT_font; // 【RESULT】表示用のフォントサイズを用意
	Font SCORE_font;  // スコア表示用のフォントサイズ
	Font text_font;   // その他の文字を表示する為のフォントサイズ
	ManagerSP manager = ManagerSP(new Manager);
	GameUISP UI = GameUISP(new GameUI);
	PlayerSP player = PlayerSP(new Player);
	GameCameraSP camera = GameCameraSP(new GameCamera);

	// スコア表示の演出用
	unsigned int view_score;
	float direction_timer_RESULT;
	float direction_timer_SCORE;
	float direction_timer_TEXT;

	// 画面が切り替わった直後に誤ってシーンを切り替えない為のタイマー
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
