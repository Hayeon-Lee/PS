#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int* arr;

void input() {
	scanf("%d", &N);

	arr = new int[N];
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
}

void solution() {
	sort(arr, arr + N);
	for (int i = N-1; i >=0; i--) {
		printf("%d ", arr[i]);
	}
}

int main(void) {
	input();
	solution();
}
