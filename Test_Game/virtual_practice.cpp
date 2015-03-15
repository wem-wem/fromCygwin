#include "lib/defines.hpp"
#include "lib/appEnv.hpp"


enum Window {
  WIDTH  = 512,
  HEIGHT = 512
};

// 基底クラス(親クラス)
class Object{
protected :
  Color col;

public:
  Object(){}

  // 純粋仮想関数
  virtual void drawObject() = 0;
};

// 派生クラス(子クラス)１
class Circle : public Object{
public:
  Circle(){
    col = Color(1, 1, 1);
  }

  // 基底クラスにある仮想関数に処理する内容を与える
  void drawObject(){
    drawFillCircle(0, 0, 20, 20, 10, col);
  }
};


// 派生クラス(子クラス)２
class Box : public Object{
public:
  Box(){
    col = Color(1, 1, 0);
  }

  // 派生クラス１で与えた処理内容とは異なる内容を与える事ができる
  void drawObject(){
    drawFillBox(-20, -20, 40, 40, col);
  }
};


// 画像の切り替え用
bool SwitchObj = false;


int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);
  Object* circle = new Circle();
  Object* box = new Box();

  while (env.isOpen()) {
    env.setupDraw();

    // 表示する画像の切り替え
    if (env.isPushButton(Mouse::LEFT)){
      if (SwitchObj){
        SwitchObj = false;
      }
      else{
        SwitchObj = true;
      }
    }

    if (SwitchObj){
      circle->drawObject();
    }
    else{
      box->drawObject();
    }

    // Ｅキーで終了
    if (env.isPushKey('E')){
      // new をしたら delete を忘れてはいけない(戒め
      delete circle;
      delete box;

      return 0;
    }
    env.update();
  }
}
