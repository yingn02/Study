#include <iostream>
using namespace std;

//쿨래스 선언
class Circle {
	// 1. 멤버 변수
	// 2. 멤버 함수
public:
	int radius;			//생성자
						//1. 생성자는 함수
	Circle();			//2. 클래스와 이름 동일
	Circle(int r);		//3. 여러 개 만들 수 있다

	~Circle();			//소멸자
						//1. 얘도 함수
						//2. 클래스명 앞에 틸드 ~ , 입력없어야함
						//3. 1개만 만들 수 있다
	double get_Area();
	double get_Area(int r);
};

Circle::Circle() {
	radius = 10;
	cout << "Circle() 생성자 함수 입니다" << endl;
	cout << "반지름이 " << radius << " 로 생성됨" << endl << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "Circle(int r) 생성자 함수 입니다" << endl;
	cout << "반지름이 " << radius << " 로 생성됨" << endl << endl;
}

Circle::~Circle() {
	cout << "반지름이 " << radius << " 인 오브젝트를 종료" << endl;
	cout << "~Circle() 소멸자 함수 호출됨" << endl << endl;
}

double Circle::get_Area() {
	return radius * radius * 3.141592;
}

double Circle::get_Area(int r) {
	return r * r * 3.141592;
}

int main() {
	//클래스를 이용해서 오브젝트 생성
	Circle mirror; //이렇게만해도 결과를 보니 위에있던게 출력됨
	double area;
	area = mirror.get_Area();
	cout << "mirror의 반지름은 " << mirror.radius << " 넓이는 " << area << endl << endl;
	// 오브젝트를 만들 때 자동으로 생성자 함수를 호출 Circle()

	Circle orange(5); 
	area = mirror.get_Area();
	cout << "orange의 반지름은 " << orange.radius << " 넓이는 " << area << endl << endl;
	//생성자 함수 호출 Circle(int r)
	//생성자 함수 없이 쓰면 기본생성자가 자동 생성됨
}