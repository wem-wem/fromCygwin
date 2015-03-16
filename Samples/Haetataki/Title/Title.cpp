#include "Title.h"

Title::Title():
// �r�d�̌Ăяo��
Title_se("res/title.wav")
{
  game_part = "Title";

  isClick = false;

  // �摜�̌Ăяo���ʒu����������
  const char* tex_name[]{
    "res/title_bg.png",
      "res/logo.png",
      "res/click_to_start.png"
  };

  // �����̉摜���Ăяo��
  for (int tex_Index = 0; tex_Index < TEX_NUM; tex_Index++){
    Title_Tex[tex_Index] = new Texture(tex_name[tex_Index]);
  }
}


// �^�C�g����ʂ̔w�i�\��
void Title::drawBg(){
  // �����̂Ȃ�[Bg]��[Logo]�̉摜������\��
  for (int i = 0; i < 2; i++){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 512, 512,
      *Title_Tex[i], Color(1, 1, 1));
  }
}


// ���̃p�[�g�ֈڍs����ۂ̉��o
void Title::NextPart(AppEnv env){
  if (env.isPushButton(Mouse::LEFT)){
    isClick = true;
  }

  // �N���b�N����Ă��Ȃ����
  if (!isClick){
    drawTextureBox(-WIDTH/2, -128,
      WIDTH, 128,
      0, 0, 512, 128,
      *Title_Tex[Click_to_Start], Color(1,1,1));
  }

  // �N���b�N���ꂽ��
  else{
    drawTextureBox(-WIDTH / 2, -128,
      WIDTH, 128,
      0, 0, 512, 128,
      *Title_Tex[Click_to_Start], Color(1, 1, 1));
  }
}
