#include <iostream>
using namespace std;

//클래스
class PrivateAccessError {
public: //접근지정자, 오브젝트가 접근

	//변수
	int a;
	//함수 헤더
	PrivateAccessError();
	PrivateAccessError(int a);
	~PrivateAccessError();

	int sum(int a, int b);

};

//클래스가 너무 커지지 않도록 바디는 뺀다
int PrivateAccessError::sum(int a, int b) {
	return a + b;
}

PrivateAccessError::PrivateAccessError() {
	cout << "PrivateAccessError() 생성자 함수 호출" << endl;
}

PrivateAccessError::PrivateAccessError(int a) {
	cout << "PrivateAccessError(int a) 생성자 함수 호출" << a << endl;
}

PrivateAccessError::~PrivateAccessError() {
	cout << "~PrivateAccessError() 소멸자 함수 호출" << endl;
}

//C++
int main() {
	//ahn 오브젝트 만든다 (메모리 할당 한다)
	PrivateAccessError ahn; //입력없는 생성자 함수 call
	PrivateAccessError yon(10); //입력있는 생성자 함수 call
	

	return 0;
}

//생성자함수: 클래스를 가지고 오브젝트를 생성할 때 호풀하는 함수
//생성자 함수는 함수이름이 클래스이름과 같다. 여러개 만들 수 있다. 1번만호출. 출력이 없다

//소멸자 함수는 1개만 만들 수 있다. 틸드~, 입력없음
