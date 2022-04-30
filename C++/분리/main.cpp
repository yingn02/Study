#include <iostream>
using namespace std;
#include "Ram.h" // "" 로 가져옴

int main() {
	Ram myRam; // myRam 이라는 오브젝트를 만들었다. 구조체 변수 선언하듯이 하자

	myRam.read(50);
	myRam.write(500, 'A'); //65
	myRam.read(500);
	myRam.write(300, 'B'); //66

	cout << myRam.read(300) + myRam.read(500) << endl;

	return 0;
}

//프로그램 작성