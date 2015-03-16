#pragma once
#include "../common.h"

class Title : public Part{
public:
  Title();

  // ‰æ‘œŒÄ‚Ño‚µ—p‚Ì’è”
  enum{
    Bg,
    Logo,
    Click_to_Start,
    TEX_NUM
  };

  // ‰æ‘œ‚Æ‰¹‚Ìİ’è
  Texture* Title_Tex[TEX_NUM];
  Media Title_se;
  
  bool isClick;

  void drawBg();
  void NextPart(AppEnv);
};