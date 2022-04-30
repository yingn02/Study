#pragma once
//#ifndef RAM_H
//#define RAM_H


class Ram {
//private: //변수
	char mem[100 * 1024]; // 100K = 102400
	int size;

public: //함수
	Ram(); //생성자 함수
	~Ram(); //소멸자 함수
	char read(int address);
	void write(int address, char value);

};

//#endif

//클래스를 헤더파일로 분리했다