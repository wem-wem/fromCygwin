#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include <fstream>  // ifstream・ofstreamの使用に必要
#include <iostream>
#include <time.h>

#define RANK_NUM (10)

enum Window {
  WIDTH  = 512,
  HEIGHT = 512
};

// ランキングの表示
void Disp_Score(Texture& One_Point, Texture& Ten_Point, int& point, int& ranking){
    for (int i = 0; i < point / 10; i++){
      drawTextureBox(-WIDTH / 2 + (25 * i), -HEIGHT / 2 + (42 * ranking), 42, 42,
        0, 0, 75, 75,
        Ten_Point, Color(1, 1, 1));
  }

    for (int i = 0; i < point % 10; i++){
      drawTextureBox(-WIDTH / 2 + (20 * i) + ((point/10) * 25), -HEIGHT / 2 + (42 * ranking),
        30, 30,
        0, 0, 75, 75,
        One_Point, Color(1, 1, 1));
  }
}

// 自分のスコア表示
void Disp_MyScore(Texture& One_Point, Texture& Ten_Point, int& point){
  for (int i = 0; i < point / 10; i++){
    drawTextureBox(-WIDTH / 2 + (25 * i), HEIGHT / 2 - 42,
      42, 42,
      0, 0, 75, 75,
      Ten_Point, Color(1, 1, 1));
  }

  for (int i = 0; i < point % 10; i++){
    drawTextureBox(-WIDTH / 2 + (20 * i) + ((point / 10) * 25), HEIGHT / 2 - 42,
      30, 30,
      0, 0, 75, 75,
      One_Point, Color(1, 1, 1));
  }
}


std::ifstream inf("res/score.txt");
Random random;
int score[11];
int random_score;

int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);
  random.setSeed(u_int(time));
  score[10] = random_score = random.fromFirstToLast(1, 40); // score[10]に一度１～40の数値を入れる
  Texture One_Point("res/miku_point_1.png");
  Texture Ten_Point("res/miku_point.png");


  while (env.isOpen()) {

    // score[0～9]にtxtの数値を代入
    if (inf){
      for (int i = 0; i < RANK_NUM; i++){
        inf >> score[i];
      }
    }

    // 左クリックでscore[10]の数値を変更
    if (env.isPushButton(Mouse::LEFT)){
      score[10] = random_score = random.fromFirstToLast(1, 40);
    }

    env.setupDraw();

    // scoreを前後で比較して入れ替える
    for (int i = 0; i < RANK_NUM + 1; i++){
        if (score[i] > score[i + 1]){
          std::swap(score[i], score[i + 1]);
      }

      Disp_Score(One_Point, Ten_Point, score[i], i);
      Disp_MyScore(One_Point, Ten_Point, random_score);
    }

    env.update();
  }
}
