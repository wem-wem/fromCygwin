#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

std::ifstream inf("test.txt");    // インプットファイル
std::ofstream outf("test.txt");// アウトプットファイル(ここで定義するとメモ帳の中身を空にしてくれているヨーダ)
std::string str;

int _tmain(int argc, _TCHAR* argv[])
{
  // メモ帳の内容を表示
  for (int i = 0; i < 2; ++i){
    inf >> str;
    std::cout << str << std::endl;
  }

  // メモ帳に"hoge"を書き込む
  // std::ofstream outf("test.txt");  ここで定義したら上の表示でメモ帳の中身が消されることはなかった
  str = "hoge";
  outf << str;

  // 再度メモ帳の内容を表示
  inf >> str;
  std::cout << str << std::endl;

  return 0;
}

