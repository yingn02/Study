#include <iostream>
using namespace std;
#include "Ram.h" // "" �� ������

int main() {
	Ram myRam; // myRam �̶�� ������Ʈ�� �������. ����ü ���� �����ϵ��� ����

	myRam.read(50);
	myRam.write(500, 'A'); //65
	myRam.read(500);
	myRam.write(300, 'B'); //66

	cout << myRam.read(300) + myRam.read(500) << endl;

	return 0;
}

//���α׷� �ۼ�