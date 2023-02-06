#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int* stocks;
int* wish;

void input() {
	scanf("%d", &N);
	stocks = new int[N];
	for (int i = 0; i < N; i++) scanf("%d", &stocks[i]);
	sort(stocks, stocks + N);

	scanf("%d", &M);
	wish = new int[M];
	for (int i = 0; i < M; i++) scanf("%d", &wish[i]);
}

int binarySearch(int start, int end, int mid, int find) {
	if (start < 0 || start >= N || end < 0 || end >= N) return 0; //범위가 벗어난 경우
	if (end < start) return 0; //찾지 못한 경우

	if (stocks[mid] == find) return 1; //찾은 경우
	
	if (find < stocks[mid]) {
		end = mid-1;
		mid = (start + end) / 2;
		return binarySearch(start, end, mid, find);
	}

	if (find > stocks[mid]) {
		start = mid + 1;
		mid = (start + end) / 2;
		return binarySearch(start, end, mid, find);
	}
}

void solution() {
	for (int i = 0; i < M; i++) {
		int result =  binarySearch(0, N-1, (int)(N / 2), wish[i]);
		if (result == 0) printf("no ");
		else printf("yes ");
	}
}

int main() {
	input();
	solution();
}
