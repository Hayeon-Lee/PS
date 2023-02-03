#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int* A, * B;

bool compare(int i, int j) {
	return i > j;
}

void input() {
	scanf("%d %d", &N, &K);
	A = new int[N];
	B = new int[N];

	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) scanf("%d", &B[i]);
}

void solution() {
	sort(A, A + N);
	sort(B, B + N, compare);

	for (int i = 0; i < K; i++) {
		if (A[i] > B[i])  break;
		//A는 오름차순, B는 내림차순 정렬 되어있으므로 B가 A보다 작은 지점부터는 더이상 확인할 이유가 없음 

		int tmp = A[i];
		A[i] = B[i];
		B[i] = tmp;
	}

	int result = 0;
	for (int i = 0; i < N; i++) result += A[i];
	printf("%d", result);
}

int main(void) {
	input();
	solution();
}
