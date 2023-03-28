#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int x1=1, x2=1, x3=1;
	for (int i = n; i >= 1; i--) {
		x1 *= i;
	}

	for (int i = k; i >= 1; i--) {
		x2 *= i;
	}

	for (int i = (n - k); i >= 1; i--) {
		x3 *= i;
	}

	int answer = x1 / (x2 * x3);
	printf("%d", answer);
}