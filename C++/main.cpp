#include <iostream>
using namespace std;
#include "Point.h"
#include "ColorPoint.h"

int main() {
	Point p; //�⺻ Ŭ������ ��ü ����
	p.set(2, 3);
	//���������� ���� protected, protected�� ��ӹ��� Ŭ������ ��� ����
	p.x = 5; //���� Ȯ��
	p.y = 5; //���� Ȯ��
	p.showPoint();

	ColorPoint cp; // �Ļ� Ŭ������ ��ü ����
	cp.x = 10; //���� Ȯ��
	cp.y = 10; //���� Ȯ��
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("Red");
	cout << ((cp.equals(cp2)) ?  "true" : "false");

	return 0;
}