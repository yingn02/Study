#include <iostream>
using namespace std;

class Circle { //클래스 선언부
public: //멤버에 대한 접근 지정자
	int radius;
	double getArea();
};

double Circle::getArea() { //클래스 구현부
	return 3.14 * radius * radius;
}

int main() {
	Circle donut; //구조체 변수 선언처럼, 객체 donut 생성
	donut.radius = 1; //구조체처럼 donut의 radious를 1로 설정
	double area = donut.getArea(); //area에 donut의 getArea함수가 리턴한 값을 돌려줌
	cout << "donut의 면적은 " << area << endl;

	Circle pizza;
	pizza.radius = 30;
	area = pizza.getArea();
	cout << "pizza의 면적은 " << area << endl;

}
