#include <iostream>
using namespace std;

class Ram {
//���� ������, ������Ʈ�� ����, �ۺ��̹Ƿ� ��ΰ� ���� ����
public:
	//1.��� ����
	char mem[100 * 1024]; //100K
	int size;
	//2.��� �Լ�
	Ram(); //������ �Լ�
	~Ram(); //�Ҹ��� �Լ�
	char read(int address);
	void write(int address, char value);
};

//Ŭ������ �Լ� �ٵ� �����
Ram::Ram() {
	cout << "Ram() ������ �Լ� ȣ��" << endl;
}

Ram::~Ram() {

}

char Ram::read(int address) {
	return 0;
}

void Ram::write(int address, char value) {

}

//C++ ���α׸�, ������Ʈ �����
int main() {
	Ram myRam;

	myRam.write(100, 20);

	return 0;
}