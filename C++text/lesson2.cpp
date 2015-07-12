#include <iostream>
using namespace std;

int main(){

	cout << "123\n"
		<< "\\100もらった\n"
		<< "またあした" << endl;

	// 10進数
	cout << "10進数なら\n"
		<< 6 << "\n"
		<< 20 << "\n"
		<< 13 << endl;

	// 8進数
	cout << "８進数なら\n"
		<< 006 << "\n"
		<< 024 << "\n"
		<< 015 << endl;

	// 16進数
	cout << "16進数なら\n"
		<< 0x6 << "\n"
		<< 0x14 << "\n"
		<< 0xD << endl;

	return 0;
}