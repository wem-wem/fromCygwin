#pragma once
#include "../Object/Object.h"

class Player;
typedef std::shared_ptr<Player> PlayerSP;

class Player : public Object{
public:
	Player();
	~Player(){};

	// ‚±‚Ì’ö“x‚È‚ç‚±‚±‚É‘‚¢‚Ä‚à—Ç‚¢‚Ì‚Å‚µ‚å‚¤‚©H
	inline Vec2f getPos(){ return pos_; };

	bool isPushKey_SPACE(AppEnv&);

	void update(AppEnv&);
	void draw();
};