#include <stdio.h>
#include <stdlib.h>

void main() {
	char* menu[4][2] = {
		{"�Ѽ����","1500��"},
		{"�Ѽ����","1500��"},
		{"������","3500��"},
		{"��ġ������","4000��"}
	};
	int input, order_num = 0;
	int orders[100] = { 0 }, totalPrice = 0;

	printf("-----------------�޴���-----------------\n");
	printf("0. �ֹ� ����\n");
	printf("1. %s   / %s \n", menu[0][0], menu[0][1]);
	printf("2. %s   / %s \n", menu[1][0], menu[1][1]);
	printf("3. %s     / %s \n", menu[2][0], menu[2][1]);
	printf("4. %s / %s \n", menu[3][0], menu[3][1]);
	printf("----------------------------------------\n");
	while (1) {
		printf("�ֹ� �� ����: ");
		scanf_s("%d", &input);
		if (input > 0 && input < 5) {
			orders[order_num] = input - 1;
			printf("�ֹ� �Ͻ� ���� : %s \n", menu[input - 1][0]);
			order_num++;
		}
		else if (input == 0) {
			break;
		}
		else {
			printf("�ش� ������ �����ϴ�. �ٽ� �������ּ���\n");
		}
	}

	FILE* fp = NULL;
	fopen_s(&fp, "receipt.txt", "wt");
	if (fp != NULL) {
		fprintf(fp, "\t****�İ� �н�****\n");
		fprintf(fp, "----------------------------------------\n");
		fprintf(fp, "��ȣ\tǰ��\t\t\t����\n");
		fprintf(fp, "----------------------------------------\n");

		for (int i = 0; i < order_num; i++) {
			fprintf(fp, "%d\t%s\t\t%s\n", i, menu[orders[i]][0], menu[orders[i]][1]);
			totalPrice += atoi(menu[orders[i]][1]);
		}
		fprintf(fp, "----------------------------------------\n");
		fprintf(fp, "�Ѿ�\t\t\t\t %d�� \n", totalPrice);
		fclose(fp);
		printf("\n\n�ֹ� ������ receipt.txt�� ��� �Ͽ����ϴ�\n");
		printf("\n�ֹ� ����\n");
	}

	fopen_s(&fp, "receipt.txt", "r");
	char readStr1[80], readStr2[80];
	if (fp != NULL) { 
		for (int i = 0; i < 4; i++) {
			fgets(readStr1, 80, fp);
			printf("%s", readStr1);
		}
		int num = 0; 
		for (int i = 0; i < order_num; i++) {
			fscanf_s(fp, "%d %s %s", &num, readStr1, 80, readStr2, 80);
			printf("%d\t%s\t\t%s\n", num, readStr1, readStr2);
		}

		for (int i = 0; i < 3 ; i++) {
			fgets(readStr1, 80, fp);
			printf("%s", readStr1);
		}

		fclose(fp);
	}

}
