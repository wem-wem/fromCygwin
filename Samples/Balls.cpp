#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include <time.h>

#define BALL_NUM (5)

enum Window {
  WIDTH  = 512,
  HEIGHT = 512
};

// ボール一つに必要な要素をまとめる
struct Ball{
  Vec2f pos;
  Vec2f speed;
  Color col;
};

// ボールを定数で宣言した数だけ用意
Ball ball[BALL_NUM];

// ボールのサイズは一律とする
const int size = 10;

// ボールにかける重力も変動しないので定数
const float gravity = -1.0f;

int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);
  Random random;
  random.setSeed(u_int(time));

  // ボールに必要な要素を全てランダム数値で用意
  for (int i = 0; i < BALL_NUM; i++){
    ball[i].pos.x() = random.fromFirstToLast(-200.0f, 200.0f);
    ball[i].pos.y() = random.fromFirstToLast(-200.0f, 200.0f);
    ball[i].speed.x() = random.fromFirstToLast(-5.0f, 5.0f);
    ball[i].speed.y() = random.fromFirstToLast(-5.0f, 5.0f);
    ball[i].col.red() = random.fromZeroToOne();
    ball[i].col.green() = random.fromZeroToOne();
    ball[i].col.blue() = random.fromZeroToOne();
  }

  while (env.isOpen()) {
    env.setupDraw();
    for (int i = 0; i < BALL_NUM; i++){
      // ボールの位置にスピードをそれぞれ加算
      ball[i].pos.x() += ball[i].speed.x();
      ball[i].pos.y() += ball[i].speed.y();

      // 「Ｇ」キーを押したら重力をかける
      if (env.isPressKey('G')){
        ball[i].speed.y() += gravity;
        ball[i].pos.y() += ball[i].speed.y() + 0.5*gravity;
      }

      // 上記で用意された数値を適用したボール５つを表示
      drawFillCircle(ball[i].pos.x(), ball[i].pos.y(),
        size, size,
        10, ball[i].col);

      // もしボールが右端に行ったら
      if (ball[i].pos.x() > WIDTH/2){
        ball[i].pos.x() = WIDTH / 2;
        ball[i].speed.x() *= -1;
      }

      // もしボールが左端に行ったら
      if (ball[i].pos.x() < -WIDTH / 2){
        ball[i].pos.x() = -WIDTH / 2;
        ball[i].speed.x() *= -1;
      }

      // もしボールが上端に行ったら
      if (ball[i].pos.y() > HEIGHT / 2){
        ball[i].pos.y() = HEIGHT / 2;
        ball[i].speed.y() *= -1;
      }

      // もしボールが下端に行ったら
      if (ball[i].pos.y() < -HEIGHT / 2){
        ball[i].pos.y() = -HEIGHT / 2;
        ball[i].speed.y() *= -1;
      }
    }
    env.update();
  }
}
