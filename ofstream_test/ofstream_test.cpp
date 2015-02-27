// 書き込みテスト.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

std::ofstream outf("test.txt");

int _tmain(int argc, _TCHAR* argv[])
{
    std::string str;
    str = "test txt\n";
    str += "fuga\n";
    str += "hoge\n";
    outf << str;

    std::ifstream inf("test.txt");
    for (int i = 0; i < 4; ++i){
      inf >> str;
      std::cout << str << std::endl;
    }

	return 0;
}

