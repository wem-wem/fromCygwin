#pragma once
#include "../Object/Object.h"

class Player;
typedef std::shared_ptr<Player> PlayerSP;

class Player : public Object{
public:
	Player();

	// この程度ならここに書いても良いのでしょうか？
	inline Vec2f getPos(){ return pos_; };
	inline int getDirection(){ return obj_direction; };

	bool isPushKey_SPACE(AppEnv&);

	void update(AppEnv&);
	void draw();
};