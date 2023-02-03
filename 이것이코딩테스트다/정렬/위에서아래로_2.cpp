#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int* arr;

bool compare(int i, int j) {
	return i > j;
}

void input() {
	scanf("%d", &N);

	arr = new int[N];
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
}

void solution() {
	sort(arr, arr + N, compare);
	for (int i = 0; i < N;  i++) {
		printf("%d ", arr[i]);
	}
}

int main(void) {
	input();
	solution();
}
