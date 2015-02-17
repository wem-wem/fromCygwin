#include "common.h"

enum{
  obj_width = 40,
  obj_height = 40
};

// 四角の表示
void Draw_Obj(Random& random, float& x, float& y, bool& hit, int& disp_time, int& game_time){
  if (game_time < 1800){

    if (disp_time > 0){
      drawFillBox(x, y, obj_width, obj_height, Color(1, 1, 1));
    }
    else {
      x = random.fromFirstToLast(-200.0f, 200.0f);
      y = random.fromFirstToLast(-200.0f, 200.0f);
      hit = false;
      disp_time = 20;
    }

  }
}

// クリック判定
void Click_Obj(AppEnv& env, float& mouse_x, float& mouse_y,
  float& obj_x, float& obj_y, bool& hit, int& disp_time, int& val,
  int& game_time, Media& hit_se, Random& random){
  if (game_time < 1800){

    if (mouse_x >= obj_x && mouse_x <= obj_x + obj_width){
      if (mouse_y >= obj_y && mouse_y <= obj_y + obj_height){
        if (!hit && env.isPushButton(Mouse::LEFT)){
          hit_se.play();
          hit = true;
          val++;
        }
      }
    }

    if (hit){
      disp_time--;
      obj_x = random.fromFirstToLast(obj_x + 2.0f, obj_x - 2.0f);
      obj_y = random.fromFirstToLast(obj_y + 2.0f, obj_y - 2.0f);
    }

  }
}

// 制限時間の表示
void Time_Limit(int& time){
  time++;
  drawFillBox(0, HEIGHT / 2 - 50,
    180 - time / 10, 40, Color(1, 1, 0));
}
