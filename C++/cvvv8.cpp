#include <iostream>
using namespace std;

class Circle { //Ŭ���� �����
public: //����� ���� ���� ������
	int radius;
	double getArea();
};

double Circle::getArea() { //Ŭ���� ������
	return 3.14 * radius * radius;
}

int main() {
	Circle donut; //����ü ���� ����ó��, ��ü donut ����
	donut.radius = 1; //����üó�� donut�� radious�� 1�� ����
	double area = donut.getArea(); //area�� donut�� getArea�Լ��� ������ ���� ������
	cout << "donut�� ������ " << area << endl;

	Circle pizza;
	pizza.radius = 30;
	area = pizza.getArea();
	cout << "pizza�� ������ " << area << endl;

}