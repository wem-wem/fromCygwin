#include "common.h"
#include "Title/Title.h"


int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);
  Part* title = new Title();

  while (env.isOpen()) {
    env.setupDraw();

    title->drawBg();
    title->NextPart(env); // 削除された関数です。って出る(´・ω・｀)
    // Ｅキーで終了
    if (env.isPushKey('E')){
      delete title;
      return 0;
    }

    env.update();
  }
}
