#include <iostream>
using namespace std;

int main() {
	cout << "주소를 입력하세요>>";

	char address[100];

	//이제는 띄어쓰기해도 전부 입력된다. 마치 gets
	cin.getline(address, 100, '\n'); //address에 100만큼 받고 엔터치를 치면 받으시오

	cout << "주소는 " << address << " 입니다\n";



}
