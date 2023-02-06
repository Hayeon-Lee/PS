#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int* tteoks;

void input() {
	scanf("%d %d", &N, &M);
	tteoks = new int[N];

	for (int i = 0; i < N; i++) scanf("%d", &tteoks[i]);
	sort(tteoks, tteoks + N);
}

int binarySearch(int start, int end, int mid, int find, int r) {
	int afterCut = 0;
	for (int i = 0; i < N; i++) {
		int cut = tteoks[i] - mid;
		if (cut >= 0) afterCut += cut;
		else cut += 0;
	} //현 중간값으로 떡 잘라보기

	if (afterCut == find) return mid; //지금 중간값이랑 find가 동일하면 탐색 멈추기
	if (start >= end) return r; //시작값과 끝값이 같은 경우 가능하면서 가장 길었던 값을 반환하기

	if (afterCut < find) { //지금 중간값으로 떡을 자르고 더한 값이 find보다 작으면 떡을 더 짧게 잘라야 함
		end = mid-1;
		mid = (start + end) / 2;
		return binarySearch(start, end, mid, find, r);
	}

	if (afterCut > find) { //지금 중간값으로 떡을 자르고 더한 값이 find보다 크면 떡을 더 크게 잘라야 함
		r = mid; //최대한 길게 잘라야 하므로 지금 값을 저장해두고, 이후에 M만큼 못가져갈 경우 지금 이 r이 정답이 됨.
		start = mid+1;
		mid = (start + end) / 2;
		return binarySearch(start, end, mid, find, r);
	}
}

void solution() {
	int start = tteoks[0];
	int end = tteoks[N - 1];
	int mid = (start + end) / 2;

	int result = binarySearch(start, end, mid, M, mid);
	printf("%d", result);
}

int main() {
	input();
	solution();
}
