#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int count = 1;
	int star = 0;
	int space = 1;

	for (count = 1; count <= 7; count++) {
		for (space = 1; space < 7 - star; space++) //°ø¹é
			printf(" ");
		for (star = 0; star < count; star++) //º°
			printf("*");
		printf("\n");
	}

	return 0;
}