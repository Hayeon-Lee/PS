#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int stock[101];
int saved[101] = { 0 ,};

void input() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &stock[i]);
	}
}

void solution() {
	stock[2] = (stock[1] > stock[2] ? stock[1] : stock[2]);

	for (int i = 3; i <= N; i++ ) {
		int case1 = stock[i - 1]; //현재 식량창고 털 수 없음
		int case2 = stock[i - 2] + stock[i]; //현재 식량창고 털 수 있음

		if (case1 > case2) stock[i] = case1;
		if (case2 > case1) stock[i] = case2;
	}

	printf("%d", stock[N]);
}

int main() {
	input();
	solution();
}
