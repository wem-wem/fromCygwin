#include <iostream>
#include <vector>

int main(){
	//std::cout << "0 - 4 = " << 0 - 4 << std::endl;
	//std::cout << "3.14 * 2 = " << 3.14 * 2 << std::endl;
	//std::cout << "5 / 3 = " << 5.f / 3.f << std::endl;
	//std::cout << "30 % 7 = " << 30 % 7 << std::endl;
	//std::cout << "(7 + 32) / 5 = " << (7.f + 32.f) / 5.f << std::endl;


	// �O�p�`�̖ʐς��o�͂���R�[�h
	double height, baseline, ans;
	std::cout << "�O�p�`�̍�������͂��Ă��������B" << std::endl;
	std::cin >> height;
	std::cout << "�O�p�`�̒�ӂ���͂��Ă��������B" << std::endl;
	std::cin >> baseline;

	ans = (height * baseline) / 2;
	std::cout << "�O�p�`�̖ʐς�" << ans << "�ł��B" << std::endl;


	// ���v�l�ƕ��ϒl�̏o��
	std::vector<double> sub;
	double total, avarage;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "�Ȗ�" << i + 1 << "�̓_������͂��Ă��������B" << std::endl;
		sub.push_back(i);	// �Ƃ肠�����v�f��ǉ�(���̎��_�ł͂O�`�T�������Ă���)
		std::cin >> sub[i];	// cin ���g���ėv�f�̒��ɒl����������B(�X�}�[�g����Ȃ��I)
	}
	total = sub[0] + sub[1] + sub[2] + sub[3] + sub[4];
	avarage = total / sub.size();
	std::cout << "�T�Ȗڂ̍��v�_��" << total << "�ł��B" << std::endl;
	std::cout << "�T�Ȗڂ̕��ϓ_��" << avarage << "�ł��B" << std::endl;
}