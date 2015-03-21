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

  // 各パートの背景表示
  virtual void drawBg() = 0;

  // 次のパートへ移行する
  virtual void NextPart(AppEnv&) = 0;
};