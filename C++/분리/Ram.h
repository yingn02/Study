#pragma once
//#ifndef RAM_H
//#define RAM_H


class Ram {
//private: //����
	char mem[100 * 1024]; // 100K = 102400
	int size;

public: //�Լ�
	Ram(); //������ �Լ�
	~Ram(); //�Ҹ��� �Լ�
	char read(int address);
	void write(int address, char value);

};

//#endif

//Ŭ������ ������Ϸ� �и��ߴ�