#include <iostream>
using namespace std;

#include "Circle.h"

int main() {
	Circle ahn; //Circle(); ������ ȣ��
	Circle young(40); // Circle(int r); ������ ȣ��
	Circle *hansung; //������Ʈ�� �ּҸ� ����Ŵ

	hansung = &ahn; //ahn�� �ּҸ� hansung�� ����Ű���Ѵ�
	cout << "ahn.getArea() = " << ahn.getArea() << endl; //Circle.cpp �� ���� getArea�� 10 �Է�
	cout << "hansung->getArea() = " << hansung->getArea() << endl;

	hansung = &young; //young�� �ּҸ� hansung�� ����Ű���Ѵ�
	cout << "young.getArea() = " << young.getArea() << endl;
	cout << "hansung->getArea() = " << hansung->getArea() << endl;

	/////////////////////////////////////////////////////////////////////////////////

	// Cricle lim[3]; //������Ʈ 3�� ����, �̰� �Է¾��� �����ڸ� ������, �������Լ� 3���θ�
	// Cricle *tae[3]; //������ �ƴ϶�, ������Ʈ 3���� ����Ű�� �ּ�, �������Լ� 0�� �θ�
	//�̷������� ��
	//tae[0] = &lim[0];
	//tae[1] = &lim[1];
	//tae[2] = &lim[2];

	//cout << "lim[1].getArea() = " << lim[1].getArea() << endl;
	//cout << "tae[1]->getArea() = " << tae[1]->getArea() << endl;

	//���� �Է��ִ� �����ڸ� ���� �ʹٸ�
	//Circle kim[3] = {Circle(), Circle(), Circle()};
	//Circle kim[3] = {Circle(20), Circle(), Circle(40)};
	//Circle kim[3] = {Circle(20), Circle(30), Circle(40)};

	/////////////////////////////////////////////////////////////////////////////////
	
	//Circle *han, *sung;

	 //���� �޸� �Ҵ�, �ּҸ� �������� �ʰ� �޸� �Ҵ�
	//han = new Circle();
	//sung = new Circle(20);


	return 0;
}

