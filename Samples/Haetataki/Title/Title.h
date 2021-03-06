#pragma once
#include "../common.h"

class Title : public Part{
public:
  Title();

  // 画像呼び出し用の定数
  enum{
    Bg,
    Logo,
    Click_to_Start,
    TEX_NUM
  };

  // 画像と音の設定
  Texture* Title_Tex[TEX_NUM];
  Media Title_se;
  
  bool isClick;

  void drawBg();
  void NextPart(AppEnv&);
};