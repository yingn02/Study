#include <iostream>
#include <string> //string 클래스를 사용하기 위한 헤더 파일
using namespace std;

int main() {
	string song("애국가"); //문자열 song, 더 이상 char song[]라고 안써도 됨
	string me("2171003"); //문자열 me
	string singer; //문자열 singer

	cout << song + "를 부른 사람은"; //파이썬처럼 + 로 문자열 연결
	cout << "힌트: 첫글자>> " << me[0] << ")?\n";

	getline(cin, singer); //singer에 대입할 문자열을 입력받음

	if (singer == me) //문자열 비교, c언어 처럼 하나씩 하지 않아도 됨
		cout << "정답\n";
	else
		cout << "오답, 정답은 " + me << " 입니다.\n" << endl;

}
