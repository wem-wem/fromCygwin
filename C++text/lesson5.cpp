#include <iostream>

using namespace std;

int main(){
	// �����Ɗ�̔��ʁA�o��------------------------------
	int num;
	cout << "��������͂��Ă��������B" << endl;
	cin >> num;

	// �����Ȃ�
	if (num % 2 == 0){
		cout << num << "�͋����ł��B" << endl;
	}
	// ��Ȃ�
	else{
		cout << num << "�͊�ł��B" << endl;
	}


	// ���l�̔�r�A�o��------------------------------
	int num1, num2;
	cout << "�Q�̐�������͂��Ă��������B" << endl;
	cin >> num1;
	cin >> num2;

	// �������l�����͂��ꂽ�ꍇ
	if (num1 == num2){
		cout << "�Q�̐��͓����l�ł��B" << endl;
	}

	// �ʁX�̐��l�����͂��ꂽ�ꍇ
	else{
		// num1 �ɏ�������������ꂽ���̂�
		// num2 �̕����傫�������� swap ����B
		if (num1 > num2){
			swap(num1, num2);
		}
		cout << num1 << "���" << num2 << "�̕����傫���l�ł��B" << endl;
	}


	// �����̏�������------------------------------
	int record;
	// �ŏ��͕K�����L�̕��͂𗬂��̂�do�`while�����g�p
	do{
		cout << "���т��P�`�T�܂ł̐����Ŋi�t�����Ă��������B" << endl;
		cin >> record;
	}
	// �P�`�T�ȊO�̐�������͂����ꍇ�A���x���J��Ԃ�
	while (record < 0 || record > 5);
	{
		switch (record){
			case 1:
				cout << "���т͂P�ł��B�����Ƃ���΂�܂��傤�B" << endl;
				break;

			case 2:
				cout << "���т͂Q�ł��B���������撣��܂��傤�B" << endl;
				break;

			case 3:
				cout << "���т͂R�ł��B����ɏ��ڎw���܂��傤�B" << endl;
				break;

			case 4:
				cout << "���т͂S�ł��B�����ւ�悭�ł��܂����B" << endl;
				break;

			case 5:
				cout << "���т͂T�ł��B�����ւ�D�G�ł��B" << endl;
				break;

				// �͈͊O�̐����������ꍇ��蒼��
			default:
				cout << "�P�`�T�܂ł̐�������͂��Ă��������B" << endl;
				cin >> record;
				break;
		}
	}
	return 0;
}