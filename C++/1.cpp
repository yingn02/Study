#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	//char name[10], dept[20];
	string name, dept;
	int sid;
	// Ű����κ��� �б�
	cout << "�̸�>>";
	cin >> name; // Ű���忡�� �̸� �Է� ����
	cout << "�й�>>";
	cin >> sid; // Ű���忡�� �й� �Է� ����
	cout << "�а�>>";
	cin >> dept; // Ű���忡�� �а� �Է� ����
	// ���� ����. student.txt ������ ����, ��� ��Ʈ�� ����
	ofstream fout("c:\\temp\\student.txt");
	if (!fout) { // ���� ���� �˻�
		cout << "c:\\temp\\student.txt ������ �� �� ����";
			return 0;
	}
	// ���� ����
	fout << name << endl; // name ����
	fout << sid << endl; // sid ����
	fout << dept << endl; // dept ����
	fout.close(); // ���� �ݱ�
}

