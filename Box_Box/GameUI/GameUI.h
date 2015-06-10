#pragma once
#include <memory>
#include "cinder/Rand.h"
#include "../common.h"
#include "../FallCube/FallCube.h"
#include "../Item/Item.h"

class GameUI{
private:
	Font font;
	FallCube fallcube;

	unsigned int _score;

public:
	unsigned int _time;

	GameUI();
	~GameUI(){};

	void setup();
	void update(unsigned int& score, unsigned int& scene, Item& item, FallCube& cube);
	void draw();
};