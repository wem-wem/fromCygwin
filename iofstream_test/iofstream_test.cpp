// �ǂݍ��݁E�������݃e�X�g.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>

#define TEXT_NUM (4)

std::ifstream inf("res/test.txt");

int _tmain(int argc, _TCHAR* argv[])
{
  // �ǂݍ��݂��e�L�X�g�̐������J��Ԃ�
  for (int i = 0; i < TEXT_NUM; i++){
    std::string str;
    inf >> str;
    std::cout << str << std::endl;
  }

  return 0;
}

