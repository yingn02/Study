#include <iostream>
#include "Point.h"
#include "ColorPoint.h"
using namespace std;

int main() {
	//Point Pixel; //오브젝트 생성
	//Point *temp; 
	//temp = new Point(); //오브젝트 생성

	ColorPoint cPixel; //상속으로 인해 Reuse 되었으므로 생성자 함수 2개 호출
	ColorPoint kPixel; //생성자 함수 2개 더 호출

	return 0;
}