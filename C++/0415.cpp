#include <iostream>
#include <string>
using namespace std;

class Integer {
	int n;

public:
	inline Integer(int num);
	inline Integer(string mmm);
	inline int get();
	inline void set(int s);
	inline int isEven();

};

Integer::Integer(int num) {
	n = num;
}

Integer::Integer(string mmm) {
	n = stoi(mmm);
}

int Integer::get() {
	return n;
}

void Integer::set(int s) {
	n = s;
}

int Integer::isEven() {
	if (n % 2 == 0)
		return 1;
	else
		return 0;
}

int main() {
	Integer n(30);
	cout << n.get() << ' '; // 30출력
	n.set(50);
	cout << n.get() << ' '; // 50출력

	Integer m("300");
	cout << m.get() << ' '; // 300출력
	cout << m.isEven(); // True(정수로 1) 출력
}