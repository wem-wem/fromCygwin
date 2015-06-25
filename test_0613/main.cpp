#include "common.h"
#include "Player/Player.h"

int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

	PlayerSP player = PlayerSP(new Player);

	while (env.isOpen()) {

		player->update(env);

		env.setupDraw();

		player->draw();

		env.update();
	}
}
