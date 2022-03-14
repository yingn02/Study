#include <iostream>
using namespace std; //나는 std:: 만 사용할테니 std:: 를 생략하게 해줘라

int main() {
	cout << "너비를 입력하세요>> ";

	int width;
	cin >> width; //scanf와 같은 기능

	cout << "높이를 입력하세요>> ";

	int height;
	cin >> height;

	int area = width * height;
	
	cout << "면적은 " << area << " 입니다." << "\n";

}