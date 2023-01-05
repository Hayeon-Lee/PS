#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int** arr;
int N, M;
int* cmp;

void input() {
	scanf("%d %d", &N, &M);
	arr = new int *[N];
	for (int i = 0; i < N; i++) arr[i] = new int[M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	cmp = new int[N];
}

void sortArr() {
	for (int i = 0; i < N; i++) {
		int** p = &(arr[i]);
		sort(p, p+M);
	}

	for (int i = 0; i < N; i++) {
		cmp[i] = arr[i][0];
	}
	sort(cmp, cmp + N);
}

int main() {
	input();
	sortArr();
	printf("%d", cmp[0]);
}
