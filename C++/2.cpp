#include <iostream>
using namespace std;

class Ram {
//접근 지정자, 오브젝트가 접근, 퍼블릭이므로 모두가 접근 가능
//지정자 지정안하면 기본적으로 private
public:
	//1.멤버 변수
	char mem[100 * 1024]; //100K
	int size;
	//2.멤버 함수
	Ram(); //생성자 함수
	~Ram(); //소멸자 함수
	char read(int address);
	void write(int address, char value);
};

//클래스의 함수 바디 만들기
Ram::Ram() {
	cout << "Ram() 생성자 함수 호출" << endl;
}

Ram::~Ram() {

}

char Ram::read(int address) {
	return 0;
}

void Ram::write(int address, char value) {

}

//C++ 프로그램, 오브젝트 만들기
int main() {
	Ram myRam;

	myRam.write(100, 20);

	return 0;
}
