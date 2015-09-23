#pragma once
#include <memory>
#include "../../common.h"

class GameUI;
typedef std::shared_ptr<GameUI> GameUISP;

class GameUI{
private:
	Font font;

	unsigned int _time;
	unsigned int _score;

public:

	GameUI();
	~GameUI(){};
	void setup();
	void update();
	void draw();
	unsigned int& getTime(){ return _time; }
	void setTime(unsigned int time) { _time = time; }
	unsigned int& getScore(){ return _score; }
	void setScore(unsigned int score) { _score = score; }
};