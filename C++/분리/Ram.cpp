#include <iostream>
using namespace std;
#include "Ram.h" // "" 로 가져옴

Ram::Ram() { //생성자 함수, 멤버 변수를 초기화 하는 역할
	cout << "Ram() 생성자 함수 호출" << endl;
	size = 100 * 1024; //102400

	for (int i = 0; i < size; i++)
		mem[i] = 0;
}

Ram::~Ram() { //소멸자 함수
	cout << "~Ram() 소멸자 함수 호출" << endl;
	cout << "메모리 제거됨" << endl;
}

//클래스의 함수의 바디