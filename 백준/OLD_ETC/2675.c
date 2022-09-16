#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void split(char* str, int repeat);

int main(void) {

	int T = 0, repeat = 0;
	char str[21];
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &repeat);
		scanf("%s", str);
		split(str, repeat);
		printf("\n");
	}
}

void split(char* str, int repeat) {

	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0; j < repeat; j++) {
			printf("%c", *(str + i));
		}
	}

	return;
}
