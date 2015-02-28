#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include <time.h>

#define BALL_MAX (10) // ボールの最大個数を定数で定義

enum Window {
  WIDTH  = 512,
  HEIGHT = 512
};

struct Ball{
  Vec2f pos;
  Vec2f speed;
  Color col;

  bool active;
};

Ball CreateBall(AppEnv& env, Vec2f mouse_pos){
  Ball ball;
  ball.active = true;
  ball.pos = mouse_pos;

  return ball;
}

Random random;
Vec2f mouse_pos;

int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);
  Ball balls[BALL_MAX];
  random.setSeed(u_int(time));

  // ボールの位置情報以外を決定
  for (int i = 0; i < BALL_MAX; i++){
    balls[i].speed.x() = random.fromFirstToLast(5.0f, -5.0f);
    balls[i].speed.y() = random.fromFirstToLast(5.0f, -5.0f);

    balls[i].col.red() = random.fromZeroToOne();
    balls[i].col.green() = random.fromZeroToOne();
    balls[i].col.blue() = random.fromZeroToOne();

    balls[i].active = false;
  }

  while (env.isOpen()) {
    
    if (env.isPushButton(Mouse::LEFT)){
      for (int i = 0; i < BALL_MAX; i++){
        if (!balls[i].active){
          balls[i] = CreateBall(env, env.mousePosition());
          break;
        }
      }
    }

    env.setupDraw();

    for (int i = 0; i < BALL_MAX; i++){
      // trueになっていないボールの処理はスキップ
      if (!balls[i].active){
        continue;
      }

        balls[i].pos += balls[i].speed;

        drawFillCircle(balls[i].pos.x(), balls[i].pos.y(),
          10, 10, 10,
          balls[i].col);

        // 画面端で跳ね返る処理
        if (balls[i].pos.x() > WIDTH/2){
          balls[i].pos.x() = WIDTH / 2;
          balls[i].speed.x() *= -1;
        }
        if (balls[i].pos.x() < -WIDTH / 2){
          balls[i].pos.x() = -WIDTH / 2;
          balls[i].speed.x() *= -1;
        }
        if (balls[i].pos.y() > HEIGHT / 2){
          balls[i].pos.y() = HEIGHT / 2;
          balls[i].speed.y() *= -1;
        }
        if (balls[i].pos.y() < -HEIGHT / 2){
          balls[i].pos.y() = -HEIGHT / 2;
          balls[i].speed.y() *= -1;
        }
    }

    env.update();
  }
}
