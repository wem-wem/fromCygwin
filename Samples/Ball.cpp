//
// アプリ雛形
//
#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include <time.h>

enum Window {
  WIDTH  = 512,
  HEIGHT = 512
};

Random random;

int main() {
  AppEnv app_env(Window::WIDTH, Window::HEIGHT, false, false);

  // 実行した時の時間でランダムの数値を設定
  random.setSeed(u_int(time));

  // ボールに必要な要素を書きだす
  struct Ball{
    Vec2f pos;      // 表示座標(x, y)
    Vec2f speed;  // 移動速度(x, y)
  } ball;

  // ボールの位置・速度をランダムで開始する
  ball.pos.x() = random.fromFirstToLast(-200.0f, 200.0f);
  ball.pos.y() = random.fromFirstToLast(-200.0f, 200.0f);

  ball.speed.x() = random.fromFirstToLast(-5.0f, 5.0f);
  ball.speed.y() = random.fromFirstToLast(-5.0f, 5.0f);

  while (app_env.isOpen()) {

    // ボールを動かす
    ball.pos.x() += ball.speed.x();
    ball.pos.y() += ball.speed.y();

    // 画面端で跳ね返る
    if (ball.pos.x() > WIDTH / 2){
      ball.pos.x() = WIDTH / 2;
      ball.speed.x() *= -1;
    }
    if (ball.pos.y() > HEIGHT / 2){
      ball.pos.y() = HEIGHT / 2;
      ball.speed.y() *= -1;
    }

    if (ball.pos.x() < -WIDTH / 2){
      ball.pos.x() = -WIDTH / 2;
      ball.speed.x() *= -1;
    }
    if (ball.pos.y() < -HEIGHT / 2){
      ball.pos.y() = -HEIGHT / 2;
      ball.speed.y() *= -1;
    }

    // 追加機能(気付かなかった)
    // Ｇキーで重力を与える
    if (app_env.isPressKey('G')){
      ball.speed.y() += -1.0f;
    }

    app_env.setupDraw();

    drawFillCircle(ball.pos.x(), ball.pos.y(), 10, 10, 20, Color(1, 1, 1));

    app_env.update();
  }
}
