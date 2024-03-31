#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {

	int option[4] = { 0, };

	for (int i = 0; i < 5; i++) {
		int tmp = 0;
		scanf("%d", &tmp);
		option[tmp] += 1;
	}

	int flag = 0;

	for (int i = 1; i < 4; i++) {
		if (option[i] == 5) {
			printf("%d", 0);
			flag = 1;
			break;
		}
		if (option[i] == 0) {
			if (i == 1) //가위가 없음 
			{
				printf("%d", option[3]);
				flag = 1;
				break;
			}
			if (i == 2) {
				printf("%d", option[1]);
				flag = 1;
				break;
			}
			if (i == 3) {
				printf("%d", option[2]);
				flag = 1;
				break;
			}
		}
	}

	if (flag == 0) {
		printf("%d", 0);
	}

	return 0;

}
