#include <iostream>
using namespace std;

int main() {
	cout << "이름을 입력하세요>> ";

	char name[11]; //한글은 5 영어는 10까지
	cin >> name; //문자열 입력

	cout << "이름은 " << name << " 입니다\n"; //출력

}

//참고로 cin 만으로는 scanf처럼 띄어쓰기가 있을 시 잘린다.
