#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include <vector>

enum Window {
  WIDTH  = 512,
  HEIGHT = 512
};

struct Ball{
  Vec2f pos;
  Vec2f speed;
  Color col;
};

Ball CreateBall(Vec2f pos, Random& random){
  Ball ball;

  ball.pos = pos;
  ball.speed.x() = random.fromFirstToLast(5.0f, -5.0f);
  ball.speed.y() = random.fromFirstToLast(5.0f, -5.0f);

  ball.col.red() = random.fromZeroToOne();
  ball.col.green() = random.fromZeroToOne();
  ball.col.blue() = random.fromZeroToOne();
  return ball;
}

std::vector<Ball> Ball_Num;

float gravity = -1.0f;

int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);
  Random random;
  Ball ball;

  while (env.isOpen()) {
    Vec2f mouse_pos = env.mousePosition();

    env.setupDraw();
    
    // クリックの数だけBall_Num[？]の数が増える
    if (env.isPushButton(Mouse::LEFT)){
      Ball_Num.push_back(CreateBall(mouse_pos, random));
    }
    
    // 増えたBall_Num[？]の分だけ繰り返す
    for (int i = 0; i < Ball_Num.size(); i++){

      Ball_Num[i].pos += Ball_Num[i].speed;

      if (env.isPressKey('G')){
        Ball_Num[i].pos.y() += gravity + 0.5 * Ball_Num[i].speed.y();
        Ball_Num[i].speed.y() += gravity;
      }

      // ボールが画面端で跳ね返る
      if (Ball_Num[i].pos.x() > WIDTH/2){
        Ball_Num[i].pos.x() = WIDTH / 2;
        Ball_Num[i].speed.x() *= -1;
      }
      if (Ball_Num[i].pos.x() < -WIDTH / 2){
        Ball_Num[i].pos.x() = -WIDTH / 2;
        Ball_Num[i].speed.x() *= -1;
      }

      if (Ball_Num[i].pos.y() > HEIGHT / 2){
        Ball_Num[i].pos.y() = HEIGHT / 2;
        Ball_Num[i].speed.y() *= -1;
      }
      if (Ball_Num[i].pos.y() < -HEIGHT / 2){
        Ball_Num[i].pos.y() = -HEIGHT / 2;
        Ball_Num[i].speed.y() *= -1;
      }

      // ボールの表示
      drawFillCircle(Ball_Num[i].pos.x(), Ball_Num[i].pos.y(),
        10, 10, 10,
        Ball_Num[i].col);

    }


    env.update();
  }
}
