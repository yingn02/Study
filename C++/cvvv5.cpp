#include <iostream>
#include <cstring> //strcmp �Լ��� �������� ��� ����
using namespace std;

int main() {
	char password[11];

	cout << "���α׷��� �����Ϸ��� ��ȣ�� �Է��ϼ���: " << endl;

	while (true) {
		cout << "��ȣ>>";
		cin >> password;

		if (strcmp(password, "C++") == 0) { //strcmp�� �� ���ڿ��� ���� �� 0 ��ȯ
			cout << "���α׷��� ���� �����մϴ�." << endl;
			break;
		}
		else
			cout << "��ȣ�� Ʋ���ϴ�." << endl;
	
	
	}

}