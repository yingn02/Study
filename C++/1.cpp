#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	//const char* file = "c:\\windows\\system.ini";
	string file = "c:\\windows\\system.ini";

	ifstream fin(file);
	if (!fin) {
		cout << file << " ���� ����" << endl;
		return 0;
	}
	int count = 0;
	int c;
	while ((c = fin.get()) != EOF) { // EOF�� ���� ������ ���� �б�
		cout << (char)c;
		count++;
	}
	cout << "���� ����Ʈ ���� " << count << endl;
	fin.close(); // ���� �ݱ�
}