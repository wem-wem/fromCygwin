#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include <time.h>

#define BALL_NUM (10)

enum Window {
  WIDTH  = 512,
  HEIGHT = 512
};

// ボールに必要な要素をまとめる
struct Ball{
  Vec2f pos;
  Vec2f speed;
  Color col;
};

Ball ball[BALL_NUM];
Random random;
Vec2f mouse_pos;

int i = 0;                                 // for文の条件に使用
unsigned int click_num = 10; // ボールの個数を制御する為の数値

float gravity = -1.0f;

int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

  for (i = 0; i < BALL_NUM; i++){

    // ボールの速度をランダムで設定
    ball[i].speed.x() = random.fromFirstToLast(2.0f, -2.0f);
    ball[i].speed.y() = random.fromFirstToLast(2.0f, -2.0f);

    // ボールの色もランダムで設定
    ball[i].col.red() = random.fromZeroToOne();
    ball[i].col.green() = random.fromZeroToOne();
    ball[i].col.blue() = random.fromZeroToOne();

  }


  while (env.isOpen()) {
    mouse_pos = env.mousePosition();  // マウスの位置を取得

    env.setupDraw();

    // 左クリックをしたら、マウスカーソルの位置にボールを出す
    if (env.isPushButton(Mouse::LEFT)){
      click_num--;
      ball[i].pos.x() = mouse_pos.x();
      ball[i].pos.y() = mouse_pos.y();
    }

    for (i = 0; i < BALL_NUM - click_num; i++){
      // ボールのポジションに、スピードを足して移動させる
      ball[i].pos.x() += ball[i].speed.x();
      ball[i].pos.y() += ball[i].speed.y();

      drawFillCircle(ball[i].pos.x(), ball[i].pos.y(),
        10, 10, 10, ball[i].col);

      // 壁に当たったら反射
      if (ball[i].pos.x() > WIDTH / 2){
        ball[i].pos.x() = WIDTH / 2;
        ball[i].speed.x() = ball[i].speed.x() * -1;
      }
      if (ball[i].pos.x() < -WIDTH / 2){
        ball[i].pos.x() = -WIDTH / 2;
        ball[i].speed.x() = ball[i].speed.x() * -1;
      }

      if (ball[i].pos.y() > HEIGHT / 2){
        ball[i].pos.y() = HEIGHT / 2;
        ball[i].speed.y() = ball[i].speed.y() * -1;
      }
      if (ball[i].pos.y() < -HEIGHT / 2){
        ball[i].pos.y() = -HEIGHT / 2;
        ball[i].speed.y() = ball[i].speed.y() * -1;
      }

      // 「Ｇ」キーで重力を加える
      if (env.isPressKey('G')){
//        ball[i].pos.y() += ball[i].speed.y() + 0.5 * gravity;
        ball[i].speed.y() += gravity;
      }
    }

    env.update();
  }
}
