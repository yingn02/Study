#include <iostream>
#include "Circle.h"
#include "Line.h"
#include "Shape.h"
#include "Rect.h"
using namespace std;

//int main() {
//	Shape ahn;
//	Rect young;
//	Line ah;
//	Circle lim;
//
//	return 0;
//}

int main() {
	Shape *pStart = NULL;
	Shape *pLast;

	pStart = new Circle(); //처음에 원 도형을 생성한다
	pLast = pStart;

	pLast = pLast->add(new Rect()); // 사각형 객체 생성
	pLast = pLast->add(new Circle());  // 원 객체 생성
	pLast = pLast->add(new Line());  // 선 객체 생성
	pLast = pLast->add(new Rect());  // 사각형 객체 생성

	// 현재 연결된 모든 도형을 화면에 그린다.
	Shape *p = pStart;
	while (p != NULL) {
		p->paint();
		p = p->getNext();
	}

	// 현재 연결된 모든 도형을 삭제한다.
	p = pStart;
	while (p != NULL) {
		Shape *q = p->getNext(); // 다음 도형 주소 기억
		delete p; // 현재 도형 객체 소멸
		p = q; // 다음 도형의 주소를 p에 저장
	}
}
