#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int cnt = 0;

void input() {
	scanf("%d", &N);
}

void solution() {
	for (int i = 1; i <= N; i++) {
		if (i % 5 == 0) cnt++;
		if (i % 25 == 0) cnt++;
		if (i % 125 == 0) cnt++;
	}
}

int main() {
	input();
	solution();
	printf("%d", cnt);
}