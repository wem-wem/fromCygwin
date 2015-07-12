#include <iostream>
using namespace std;

int main(){
	float pi;
	cout << "円周率の値はいくつですか？" << endl;
	cin >> pi;
	cout << "円周率の値は" << pi << "です。" << endl;

	char initial;
	cout << "アルファベットの最初の文字は何ですか？" << endl;
	cin >> initial;
	cout << "アルファベットの最初の文字は" << initial << "です。" << endl;

	float height, weight;
	cout << "身長と体重を入力してください。" << endl;
	cin >> height;
	cin >> weight;
	cout << "身長は" << height << "センチです。" << endl;
	cout << "体重は" << weight << "キロです。" << endl;
}