#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int n = 0;
	scanf("%d", &n);

	for (int i = n; i > 0; i--) {
		for (int k = i; k < n; k++) {
			printf(" ");
		}

		for (int j = 0; j < 2 * i - 1; j++) {
			printf("*");
		}

		printf("\n");
	} //위 삼각형

	for (int i = 1; i < n; i++) {
		for (int j = i; j < n - 1; j++) {
			printf(" ");
		}
		for (int k = 0; k < 2 * i + 1; k++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
