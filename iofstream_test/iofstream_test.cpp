#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

std::ifstream inf("test.txt");    // �C���v�b�g�t�@�C��
std::ofstream outf("test.txt");// �A�E�g�v�b�g�t�@�C��(�����Œ�`����ƃ������̒��g����ɂ��Ă���Ă��郈�[�_)
std::string str;

int _tmain(int argc, _TCHAR* argv[])
{
  // �������̓��e��\��
  for (int i = 0; i < 2; ++i){
    inf >> str;
    std::cout << str << std::endl;
  }

  // ��������"hoge"����������
  // std::ofstream outf("test.txt");  �����Œ�`�������̕\���Ń������̒��g��������邱�Ƃ͂Ȃ�����
  str = "hoge";
  outf << str;

  // �ēx�������̓��e��\��
  inf >> str;
  std::cout << str << std::endl;

  return 0;
}

