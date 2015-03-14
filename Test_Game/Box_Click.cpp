// 画面上のボックスをクリックして消していくゲーム
// 円の判定に失敗した為、ボックスに変更

#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include <time.h>

#define BOX_MAX (10)      // ボックスの個数を定数で決める
#define BOX_STATUS (40) // ボックスの大きさ

enum Window {
  WIDTH  = 512,
  HEIGHT = 512
};


// ボックスに必要な要素
struct Box{
  Vec2f pos;     // 位置
  Vec2f speed; // 速さ
  Color col;     // 色

  bool isActive;  // クリックされたかどうかの判定
};


// 初期化関数
void Init(Box& box, Random& random){
    // 画面の外に出ないような初期値に設定
    box.pos.x() = random.fromFirstToLast(250.0f, -250.0f);
    box.pos.y() = random.fromFirstToLast(250.0f, -250.0f);

    // ボール毎のスピード
    box.speed.x() = random.fromFirstToLast(5.0f, -5.0f);
    box.speed.y() = random.fromFirstToLast(5.0f, -5.0f);

    // ボール毎の色
    box.col.red() = random.fromZeroToOne();
    box.col.green() = random.fromZeroToOne();
    box.col.blue() = random.fromZeroToOne();

    // ボールを全てアクティブの状態に初期化
    box.isActive = true;
}


// オブジェクトの内側にマウスカーソルが入っているかの判定
bool  isInside(Vec2f pos, Box& box){
  if (pos.x() > box.pos.x() &&
    pos.x() < box.pos.x() + BOX_STATUS &&
    pos.y() > box.pos.y() &&
    pos.y() < box.pos.y() + BOX_STATUS){
    return true;
  }

  else{
    return false;
  }
}


int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);
  Random random;
  Box box[BOX_MAX];

  // マウスの位置を保存する変数
  Vec2f mouse_pos;

  // ランダムの値を実行時の時間で設定
  random.setSeed(u_int(time));

  // ボールの初期化
  for (int i = 0; i < BOX_MAX; i++){
    Init(box[i], random);
  }

  while (env.isOpen()) {
    // ループ開始時にマウスの座標を更新
    mouse_pos = env.mousePosition();

    env.setupDraw();

    for (int i = 0; i < BOX_MAX; i++){
      // 既に消されているボールの処理はスキップ
      if (!box[i].isActive) continue;

        // ボールの位置に速さを足し続ける
        box[i].pos += box[i].speed;

        // 画面端で跳ね返る
        if (box[i].pos.x() > WIDTH/2 - BOX_STATUS/2){
          box[i].pos.x() = WIDTH / 2 - BOX_STATUS / 2;
          box[i].speed.x() *= -1;
        }
        if (box[i].pos.x() < -WIDTH / 2){
          box[i].pos.x() = -WIDTH / 2;
          box[i].speed.x() *= -1;
        }
        if (box[i].pos.y() > HEIGHT / 2 - BOX_STATUS / 2){
          box[i].pos.y() = HEIGHT / 2 - BOX_STATUS / 2;
          box[i].speed.y() *= -1;
        }
        if (box[i].pos.y() < -HEIGHT / 2){
          box[i].pos.y() = -HEIGHT / 2;
          box[i].speed.y() *= -1;
        }

        // オブジェクトの内側でクリックしたら、そのオブジェクトを非表示にする
        if (isInside(mouse_pos, box[i])){
          if (env.isPushButton(Mouse::LEFT)){
            box[i].isActive = false;
          }
        }

        if (box[i].isActive){
          drawFillBox(box[i].pos.x(), box[i].pos.y(),
            BOX_STATUS, BOX_STATUS,
            box[i].col);
        }
    }
    
    
    env.update();
  }
}
