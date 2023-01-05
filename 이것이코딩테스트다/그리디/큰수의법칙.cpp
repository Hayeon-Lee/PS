#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int* arr;

void input();
bool compare(int i, int j);
void sortArr();
void answer();

int main() {
	scanf("%d %d %d", &N, &M, &K);

	input();
	sortArr();
	answer();

}

void input() {
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	return;
}

bool compare(int i, int j) {
	return i > j;
}

void sortArr() {
	sort(arr, arr+N, compare);
	return;
}

void answer() {
	int limit = 0, index = 0;
	int result = 0;

	while (limit < M) {
		for (int i = 0; i < K; i++) {
			result += arr[index];
			limit += 1;
			if (limit == M) break;
		}

		if (limit == M) break;
		else {
			result += arr[index + 1];
			limit += 1;
		}
	}
	printf("%d", result);
}
