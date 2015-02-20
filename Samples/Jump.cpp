#include "lib/defines.hpp"
#include "lib/appEnv.hpp"


enum Window {
  WIDTH  = 512,
  HEIGHT = 512
};

struct Jump{
  float y;
  float vy;

  bool isJumping;
};

const float Jump_Height = 20.0f;
const float Gravity = -1.0f;

int main() {
  AppEnv app_env(Window::WIDTH, Window::HEIGHT, false, false);
  Jump jump{
    0.0f, 0.0f,
    false
  };
  
  while (app_env.isOpen()) {

    // ジャンプしていない状態で左クリックをしたらジャンプ
    if (app_env.isPushButton(Mouse::LEFT)){
      if (!jump.isJumping){
        jump.isJumping = true;
        jump.vy = Jump_Height;
      }
    }

    // ジャンプしている間、ジャンプ力による上昇と重力の影響を受ける
    //------------TIPS---------------//
    //     等加速運動の法則を利用     //
    //  s = v0 * t + 0.5 * a * t^2   //ここよく分からんです
    //   v = v0 + a * t                     //
    //--------------------------------//
    if (jump.isJumping){
      jump.y += jump.vy + 0.5 * Gravity;
      jump.vy += Gravity;
    }

    // 元の座標(y = 0)に戻ったら、ジャンプ状態を解除
    // 下に落ちないように元の座標で固定
    if (jump.y < 0.0){
      jump.y = 0.0f;
      jump.isJumping = false;
    }

    app_env.setupDraw();

    // ボールの表示
    drawFillCircle(0.0f, jump.y,
      20, 20,
      10, Color(1, 1, 1));

    app_env.update();
  }
}
