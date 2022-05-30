#include <iostream>
using namespace std;
#include "Point.h"
#include "ColorPoint.h"

int main() {
	Point p; //기본 클래스의 객체 생성
	p.set(2, 3);
	//접근지정자 오류 protected, protected는 상속받은 클래스만 사용 가능
	p.x = 5; //오류 확인
	p.y = 5; //오류 확인
	p.showPoint();

	ColorPoint cp; // 파생 클래스의 객체 생성
	cp.x = 10; //오류 확인
	cp.y = 10; //오류 확인
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("Red");
	cout << ((cp.equals(cp2)) ?  "true" : "false");

	return 0;
}
