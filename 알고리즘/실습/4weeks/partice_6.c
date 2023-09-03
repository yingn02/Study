#include <stdio.h>
#include <string.h>

void main() {
	char str[] = "This study is toward interactive dynamic mapping on web based on open source.\
 Among available interactive mapping of open source libraries, D3.js was chosen.\
 It is a JavaScript library with capability to bind arbitrary data and provides \
 open source mapping framework. Analysis of geo-statistical data is designed using R,\
 a package and programming language for statistical data analysis. \
 This work implemented an integrated user interface with these separate frameworks, \
 and provides a mobile web app application for client sides.";
	puts(str);
	int len = sizeof(str) / sizeof(str[0]);
	printf("str 문자열의 길이는 : %d \n", strlen(str));
	printf("str 문자열의 , 띄어쓰기 갯수는 : %d \n", charCount(str, len));

}

int charCount(char str[], int len) {
	int result=0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') result++;
	}
	return result;
}