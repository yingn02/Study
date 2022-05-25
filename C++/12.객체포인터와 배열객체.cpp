#include <iostream>
using namespace std;

#include "Circle.h"

int main() {
	Circle ahn; //Circle(); 생성자 호출
	Circle young(40); // Circle(int r); 생성자 호출
	Circle *hansung; //오브젝트의 주소를 가리킴

	hansung = &ahn; //ahn의 주소를 hansung이 가리키게한다
	cout << "ahn.getArea() = " << ahn.getArea() << endl; //Circle.cpp 에 의해 getArea는 10 입력
	cout << "hansung->getArea() = " << hansung->getArea() << endl;

	hansung = &young; //young의 주소를 hansung이 가리키게한다
	cout << "young.getArea() = " << young.getArea() << endl;
	cout << "hansung->getArea() = " << hansung->getArea() << endl;

	/////////////////////////////////////////////////////////////////////////////////

	// Cricle lim[3]; //오브젝트 3개 생성, 이건 입력없는 생성자만 가능함, 생성자함수 3번부름
	// Cricle *tae[3]; //생성이 아니라, 오브젝트 3개를 가리키는 주소, 생성자함수 0번 부름
	//이런식으로 씀
	//tae[0] = &lim[0];
	//tae[1] = &lim[1];
	//tae[2] = &lim[2];

	//cout << "lim[1].getArea() = " << lim[1].getArea() << endl;
	//cout << "tae[1]->getArea() = " << tae[1]->getArea() << endl;

	//만약 입력있는 생성자를 쓰고 싶다면
	//Circle kim[3] = {Circle(), Circle(), Circle()};
	//Circle kim[3] = {Circle(20), Circle(), Circle(40)};
	//Circle kim[3] = {Circle(20), Circle(30), Circle(40)};

	/////////////////////////////////////////////////////////////////////////////////
	
	//Circle *han, *sung;

	 //동적 메모리 할당, 주소를 가져오지 않고 메모리 할당
	//han = new Circle();
	//sung = new Circle(20);


	return 0;
}

