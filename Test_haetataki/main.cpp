
#include "number_draw.h"
#include "score.h"
#include "Game.h"
#include "Title.h"


struct Box{
  Vec2f pos;
  int disp_time = 20;
}box;

int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);
  cNumber score;
  Random random;
  Vec2f mouse_pos;
  Media hit_se("res/hit.wav");
  Texture title("res/click_to_start.png");

  random.setSeed (u_int(time));

  Color col = Color(1, 1, 1);
  int val = 0;
  int time = 0;
  bool hit = false;

  int game_mode = 0;

  enum {
    TITLE,
    GAME,
    RESULT
  };

  while (env.isOpen()) {
    env.setupDraw();

    if (game_mode == TITLE){
      Disp_Title(env, game_mode, title);
    }

    if (game_mode == GAME){
      mouse_pos = env.mousePosition();

      // TIPS: 数字、座標を指定して、その位置にスコアを表示する
      score.draw(val, Vec2f(-WIDTH / 2, HEIGHT / 2 - 40));

      Click_Obj(env, mouse_pos.x(), mouse_pos.y(),
        box.pos.x(), box.pos.y(), hit, box.disp_time, val, time, hit_se, random);

      Draw_Obj(random, box.pos.x(), box.pos.y(),
        hit, box.disp_time, time);

      Time_Limit(time);
    }

      env.update();
  }
}
