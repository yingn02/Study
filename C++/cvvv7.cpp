#include <iostream>
#include <string> //string Ŭ������ ����ϱ� ���� ��� ����
using namespace std;

int main() {
	string song("�ֱ���"); //���ڿ� song, �� �̻� char song[]��� �Ƚᵵ ��
	string me("2171003"); //���ڿ� me
	string singer; //���ڿ� singer

	cout << song + "�� �θ� �����"; //���̽�ó�� + �� ���ڿ� ����
	cout << "��Ʈ: ù����>> " << me[0] << ")?\n";

	getline(cin, singer); //singer�� ������ ���ڿ��� �Է¹���

	if (singer == me) //���ڿ� ��, c��� ó�� �ϳ��� ���� �ʾƵ� ��
		cout << "����\n";
	else
		cout << "����, ������ " + me << " �Դϴ�.\n" << endl;

}