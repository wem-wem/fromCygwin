#pragma once
#include "../Object/Object.h"

class Player;
typedef std::shared_ptr<Player> PlayerSP;

class Player : public Object{
public:
	Player();
	~Player(){};

	// ���̒��x�Ȃ炱���ɏ����Ă��ǂ��̂ł��傤���H
	inline Vec2f getPos(){ return pos_; };

	bool isPushKey_SPACE(AppEnv&);

	void update(AppEnv&);
	void draw();
};