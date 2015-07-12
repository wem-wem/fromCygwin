#include <iostream>

using namespace std;

int main(){
	// 偶数と奇数の判別、出力------------------------------
	int num;
	cout << "整数を入力してください。" << endl;
	cin >> num;

	// 偶数なら
	if (num % 2 == 0){
		cout << num << "は偶数です。" << endl;
	}
	// 奇数なら
	else{
		cout << num << "は奇数です。" << endl;
	}


	// 数値の比較、出力------------------------------
	int num1, num2;
	cout << "２つの整数を入力してください。" << endl;
	cin >> num1;
	cin >> num2;

	// 同じ数値が入力された場合
	if (num1 == num2){
		cout << "２つの数は同じ値です。" << endl;
	}

	// 別々の数値が入力された場合
	else{
		// num1 に小さい数字を入れたいので
		// num2 の方が大きかったら swap する。
		if (num1 > num2){
			swap(num1, num2);
		}
		cout << num1 << "より" << num2 << "の方が大きい値です。" << endl;
	}


	// 複数の条件分岐------------------------------
	int record;
	// 最初は必ず下記の文章を流すのでdo～while文を使用
	do{
		cout << "成績を１～５までの数字で格付けしてください。" << endl;
		cin >> record;
	}
	// １～５以外の数字を入力した場合、何度も繰り返す
	while (record < 0 || record > 5);
	{
		switch (record){
			case 1:
				cout << "成績は１です。もっとがんばりましょう。" << endl;
				break;

			case 2:
				cout << "成績は２です。もう少し頑張りましょう。" << endl;
				break;

			case 3:
				cout << "成績は３です。さらに上を目指しましょう。" << endl;
				break;

			case 4:
				cout << "成績は４です。たいへんよくできました。" << endl;
				break;

			case 5:
				cout << "成績は５です。たいへん優秀です。" << endl;
				break;

				// 範囲外の数字だった場合やり直し
			default:
				cout << "１～５までの数字を入力してください。" << endl;
				cin >> record;
				break;
		}
	}
	return 0;
}