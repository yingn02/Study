#include <iostream>
using namespace std;
#include "Ram.h" // "" �� ������

Ram::Ram() { //������ �Լ�, ��� ������ �ʱ�ȭ �ϴ� ����
	cout << "Ram() ������ �Լ� ȣ��" << endl;
	size = 100 * 1024; //102400

	for (int i = 0; i < size; i++)
		mem[i] = 0;
}

Ram::~Ram() { //�Ҹ��� �Լ�
	cout << "~Ram() �Ҹ��� �Լ� ȣ��" << endl;
	cout << "�޸� ���ŵ�" << endl;
}

//Ŭ������ �Լ��� �ٵ�