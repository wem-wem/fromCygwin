// 継承の練習.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <string>

// 基底クラス
class Animal{
protected:
  std::string name_;

public:
  Animal(){}

  virtual void nameDisp() = 0;

  void ageDisp(int age){
    std::cout << "私の年齢は " << age << "才です。" << std::endl;
  }
};

// 派生クラス１
class Dog : public Animal{
public:
  Dog(){
    name_ = "私は犬のタローです。";
  }

  void nameDisp(){
    std::cout << name_ << std::endl;
  }
};

// 派生クラス２
class Cat : public Animal{
public:
  Cat(){
    name_ = "私は猫のジローです。";
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

