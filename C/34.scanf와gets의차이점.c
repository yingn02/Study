#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char str[100];
    int i;

    printf("���� ���ڰ� �ִ� ���ڿ��� �Է��Ͻÿ�: ");
    gets(str); //scanf ��� �� ���� �߻�

    for (i = 0; str[i] != NULL; i++) {
        if (str[i] != ' ')
            printf("%c", str[i]);
    }

    return 0;
}

//scanf�� ����, �� �ٲ� �Ǵ� EOF(���� ��)�� ������ �Է����޴� ���� �����ϴ� �ݸ� 
//gets�� ������ �Է� ���ڿ��� �Ϻη� �����ϰ� �� �ٲ� �Ǵ� EOF�� ������ �Է��� �����ϴ�.