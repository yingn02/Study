#include <iostream>
using namespace std; //���� std:: �� ������״� std:: �� �����ϰ� �����

int main() {
	cout << "�ʺ� �Է��ϼ���>> ";

	int width;
	cin >> width; //scanf�� ���� ���

	cout << "���̸� �Է��ϼ���>> ";

	int height;
	cin >> height;

	int area = width * height;
	
	cout << "������ " << area << " �Դϴ�." << "\n";

}