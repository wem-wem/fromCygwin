#include "common.h"
#include "GameManager/GameManager.h"

int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

	GameManagerSP game = GameManagerSP(new GameManager);

	while (env.isOpen()) {

		game->update(env);


		env.setupDraw();

		game->draw();

		env.update();
	}
}
