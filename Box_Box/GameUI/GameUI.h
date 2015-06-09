#pragma once
#include <memory>
#include "cinder/Rand.h"
#include "../common.h"
#include "../Player/Player.h"

class GameUI{
private:
	Font font;

	unsigned int _time;
	unsigned int _score;

public:
	GameUI();
	~GameUI(){};

	void setup();
	void update(unsigned int& score, unsigned int& scene);
	void draw();
};