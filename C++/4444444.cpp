#include <iostream>
using namespace std;

//Ŭ����
class PrivateAccessError {
public: //����������, ������Ʈ�� ����

	//����
	int a;
	//�Լ� ���
	PrivateAccessError();
	PrivateAccessError(int a);
	~PrivateAccessError();

	int sum(int a, int b);

};

//Ŭ������ �ʹ� Ŀ���� �ʵ��� �ٵ�� ����
int PrivateAccessError::sum(int a, int b) {
	return a + b;
}

PrivateAccessError::PrivateAccessError() {
	cout << "PrivateAccessError() ������ �Լ� ȣ��" << endl;
}

PrivateAccessError::PrivateAccessError(int a) {
	cout << "PrivateAccessError(int a) ������ �Լ� ȣ��" << a << endl;
}

PrivateAccessError::~PrivateAccessError() {
	cout << "~PrivateAccessError() �Ҹ��� �Լ� ȣ��" << endl;
}

//C++
int main() {
	//ahn ������Ʈ ����� (�޸� �Ҵ� �Ѵ�)
	PrivateAccessError ahn; //�Է¾��� ������ �Լ� call
	PrivateAccessError yon(10); //�Է��ִ� ������ �Լ� call
	

	return 0;
}

//�������Լ�: Ŭ������ ������ ������Ʈ�� ������ �� ȣǮ�ϴ� �Լ�
//������ �Լ��� �Լ��̸��� Ŭ�����̸��� ����. ������ ���� �� �ִ�. 1����ȣ��. ����� ����

//�Ҹ��� �Լ��� 1���� ���� �� �ִ�. ƿ��~, �Է¾���
