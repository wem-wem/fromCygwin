#pragma once
#include "../common.h"

class Title : public Part{
public:
  Title();

  // �摜�Ăяo���p�̒萔
  enum{
    Bg,
    Logo,
    Click_to_Start,
    TEX_NUM
  };

  // �摜�Ɖ��̐ݒ�
  Texture* Title_Tex[TEX_NUM];
  Media Title_se;
  
  bool isClick;

  void drawBg();
  void NextPart(AppEnv);
};