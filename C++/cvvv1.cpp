#include <iostream>
using namespace std;

//�𷡽� ����
class Circle {
	// 1. ��� ����
	// 2. ��� �Լ�
public:
	int radius;			//������
						//1. �����ڴ� �Լ�
	Circle();			//2. Ŭ������ �̸� ����
	Circle(int r);		//3. ���� �� ���� �� �ִ�

	~Circle();			//�Ҹ���
						//1. �굵 �Լ�
						//2. Ŭ������ �տ� ƿ�� ~ , �Է¾������
						//3. 1���� ���� �� �ִ�
	double get_Area();
	double get_Area(int r);
};

Circle::Circle() {
	radius = 10;
	cout << "Circle() ������ �Լ� �Դϴ�" << endl;
	cout << "�������� " << radius << " �� ������" << endl << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "Circle(int r) ������ �Լ� �Դϴ�" << endl;
	cout << "�������� " << radius << " �� ������" << endl << endl;
}

Circle::~Circle() {
	cout << "�������� " << radius << " �� ������Ʈ�� ����" << endl;
	cout << "~Circle() �Ҹ��� �Լ� ȣ���" << endl << endl;
}

double Circle::get_Area() {
	return radius * radius * 3.141592;
}

double Circle::get_Area(int r) {
	return r * r * 3.141592;
}

int main() {
	//Ŭ������ �̿��ؼ� ������Ʈ ����
	Circle mirror; //�̷��Ը��ص� ����� ���� �����ִ��� ��µ�
	double area;
	area = mirror.get_Area();
	cout << "mirror�� �������� " << mirror.radius << " ���̴� " << area << endl << endl;
	// ������Ʈ�� ���� �� �ڵ����� ������ �Լ��� ȣ�� Circle()

	Circle orange(5); 
	area = mirror.get_Area();
	cout << "orange�� �������� " << orange.radius << " ���̴� " << area << endl << endl;
	//������ �Լ� ȣ�� Circle(int r)
	//������ �Լ� ���� ���� �⺻�����ڰ� �ڵ� ������
}