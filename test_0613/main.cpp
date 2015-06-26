#include "common.h"
#include "GameManager/GameManager.h"

int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

	GameManagerSP game = GameManagerSP(new GameManager);
	//std::make_shared<GameManagerSP> (game);
	
	while (env.isOpen()) {

		game->update(env);


		env.setupDraw();

		game->draw();

		env.update();
	}
}
