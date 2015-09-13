#pragma once
#include "common.h"
#include "GAME/Player/Player.h"

class Touch;
typedef std::shared_ptr<Touch> TouchSP;

class Touch : public AppNative {
private:
	PlayerSP player = PlayerSP(new Player);

};
