#include <iostream>
#include <vector>

int main(){
	//std::cout << "0 - 4 = " << 0 - 4 << std::endl;
	//std::cout << "3.14 * 2 = " << 3.14 * 2 << std::endl;
	//std::cout << "5 / 3 = " << 5.f / 3.f << std::endl;
	//std::cout << "30 % 7 = " << 30 % 7 << std::endl;
	//std::cout << "(7 + 32) / 5 = " << (7.f + 32.f) / 5.f << std::endl;


	// 三角形の面積を出力するコード
	double height, baseline, ans;
	std::cout << "三角形の高さを入力してください。" << std::endl;
	std::cin >> height;
	std::cout << "三角形の底辺を入力してください。" << std::endl;
	std::cin >> baseline;

	ans = (height * baseline) / 2;
	std::cout << "三角形の面積は" << ans << "です。" << std::endl;


	// 合計値と平均値の出力
	std::vector<double> sub;
	double total, avarage;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "科目" << i + 1 << "の点数を入力してください。" << std::endl;
		sub.push_back(i);	// とりあえず要素を追加(この時点では０～５が入っている)
		std::cin >> sub[i];	// cin を使って要素の中に値を代入させる。(スマートじゃない！)
	}
	total = sub[0] + sub[1] + sub[2] + sub[3] + sub[4];
	avarage = total / sub.size();
	std::cout << "５科目の合計点は" << total << "です。" << std::endl;
	std::cout << "５科目の平均点は" << avarage << "です。" << std::endl;
}