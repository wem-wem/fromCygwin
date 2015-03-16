#include "Title.h"

Title::Title():
// ＳＥの呼び出し
Title_se("res/title.wav")
{
  game_part = "Title";

  isClick = false;

  // 画像の呼び出し位置を書き込み
  const char* tex_name[]{
    "res/title_bg.png",
      "res/logo.png",
      "res/click_to_start.png"
  };

  // 複数の画像を呼び出し
  for (int tex_Index = 0; tex_Index < TEX_NUM; tex_Index++){
    Title_Tex[tex_Index] = new Texture(tex_name[tex_Index]);
  }
}


// タイトル画面の背景表示
void Title::drawBg(){
  // 動きのない[Bg]と[Logo]の画像だけを表示
  for (int i = 0; i < 2; i++){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 512, 512,
      *Title_Tex[i], Color(1, 1, 1));
  }
}


// 次のパートへ移行する際の演出
void Title::NextPart(AppEnv env){
  if (env.isPushButton(Mouse::LEFT)){
    isClick = true;
  }

  // クリックされていなければ
  if (!isClick){
    drawTextureBox(-WIDTH/2, -128,
      WIDTH, 128,
      0, 0, 512, 128,
      *Title_Tex[Click_to_Start], Color(1,1,1));
  }

  // クリックされたら
  else{
    drawTextureBox(-WIDTH / 2, -128,
      WIDTH, 128,
      0, 0, 512, 128,
      *Title_Tex[Click_to_Start], Color(1, 1, 1));
  }
}
