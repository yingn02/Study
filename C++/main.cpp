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

	pStart = new Circle(); //ó���� �� ������ �����Ѵ�
	pLast = pStart;

	pLast = pLast->add(new Rect()); // �簢�� ��ü ����
	pLast = pLast->add(new Circle());  // �� ��ü ����
	pLast = pLast->add(new Line());  // �� ��ü ����
	pLast = pLast->add(new Rect());  // �簢�� ��ü ����

	// ���� ����� ��� ������ ȭ�鿡 �׸���.
	Shape *p = pStart;
	while (p != NULL) {
		p->paint();
		p = p->getNext();
	}

	// ���� ����� ��� ������ �����Ѵ�.
	p = pStart;
	while (p != NULL) {
		Shape *q = p->getNext(); // ���� ���� �ּ� ���
		delete p; // ���� ���� ��ü �Ҹ�
		p = q; // ���� ������ �ּҸ� p�� ����
	}
}
