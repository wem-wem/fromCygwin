#include "common.h"

void Disp_Title(AppEnv& env, int& game_mode, Texture& title){
  drawTextureBox(-100, -25, 200, 50,
    0, 0, 512, 128,
    title, Color(1,1,1));

  if (env.isPushButton(Mouse::LEFT)){
    game_mode = 1;
  }
}