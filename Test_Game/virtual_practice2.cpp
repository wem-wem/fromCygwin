// �p���̗��K.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <iostream>
#include <string>

// ���N���X
class Animal{
protected:
  std::string name_;

public:
  Animal(){}

  virtual void nameDisp() = 0;

  void ageDisp(int age){
    std::cout << "���̔N��� " << age << "�˂ł��B" << std::endl;
  }
};

// �h���N���X�P
class Dog : public Animal{
public:
  Dog(){
    name_ = "���͌��̃^���[�ł��B";
  }

  void nameDisp(){
    std::cout << name_ << std::endl;
  }
};

// �h���N���X�Q
class Cat : public Animal{
public:
  Cat(){
    name_ = "���͔L�̃W���[�ł��B";
  }

  void nameDisp(){
    std::cout << name_ << std::endl;
  }
};

int _tmain(int argc, _TCHAR* argv[])
{
  Animal* dog = new Dog;
  Animal* cat = new Cat;

  dog->nameDisp();
  dog->ageDisp(2);

  cat->nameDisp();
  cat->ageDisp(4);


  delete dog;
  delete cat;

	return 0;
}

