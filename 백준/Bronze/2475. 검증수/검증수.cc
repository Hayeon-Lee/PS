#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int numbers[5];
	int answer = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &numbers[i]);
		answer += (numbers[i] * numbers[i]);
	}

	answer %= 10;
	printf("%d", answer);
}
