#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;

int main() {
	scanf("%d %d", &N, &K);
	int answer = 0;
	int tmp = N;

	while (tmp != 1) {
		if (tmp % K == 0) tmp /= K;
		else tmp -= 1;

		answer += 1;
	}

	printf("%d", answer);
}
