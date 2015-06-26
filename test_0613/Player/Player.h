#pragma once
#include "../Object/Object.h"

class Player;
typedef std::shared_ptr<Player> PlayerSP;

class Player : public Object{
public:
	Player();
	bool isPushKey_SPACE(AppEnv&);

	void update(AppEnv&);
	void draw();
};