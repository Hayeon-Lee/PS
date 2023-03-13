#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x;
	scanf("%d", &x);

	int* arr = new int[x + 1];
	for (int i = 0; i < x + 1; i++) arr[i] = 0;

	int cnt = 0;

	for (int i = 2; i <= x; i++) {
		arr[i] = arr[i - 1] + 1;

		if (i % 2 == 0) {
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}

		if (i % 3 == 0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}
	}
	printf("%d", arr[x]);
}