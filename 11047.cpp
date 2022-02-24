#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int N, K, count = 0;
	scanf("%d %d", &N, &K);

	int* coin = new int[N];
	for (int i = 0; i < N; i++) scanf("%d", &coin[i]);

	while (K >= coin[N-1]) {
		K -= coin[N - 1];
		count += 1;
	}

	while (K != 0) {
		for (int i = 0; i < N; i++) {
			if (coin[i] == K) {
				K -= coin[i];
				count += 1;
				break;
			}
			else if (coin[i] > K) {
				K -= coin[i - 1];
				count += 1;
				break;
			}
		}
	}

	printf("%d", count);
}
