#pragma once
#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include <string>

enum Window {
  WIDTH = 512,
  HEIGHT = 512
};


class Part{
protected:
  std::string game_part;

public:
  Part(){};

  // �e�p�[�g�̔w�i�\��
  virtual void drawBg() = 0;

  // ���̃p�[�g�ֈڍs����
  virtual void NextPart(AppEnv&) = 0;
};