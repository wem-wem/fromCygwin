// 読み込み・書き込みテスト.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>

#define TEXT_NUM (4)

std::ifstream inf("res/test.txt");

int _tmain(int argc, _TCHAR* argv[])
{
  // 読み込みをテキストの数だけ繰り返す
  for (int i = 0; i < TEXT_NUM; i++){
    std::string str;
    inf >> str;
    std::cout << str << std::endl;
  }

  return 0;
}

