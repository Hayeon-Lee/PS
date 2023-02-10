#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int X;
int memoArr[30001] = { 0, };

void input() {
	scanf("%d", &X);
}

//1부터 역행

void solution() {
	for (int i = 2; i <= X; i++) {
		memoArr[i] = memoArr[i -1] + 1; //1을 빼는 연산

		if (i % 2 == 0) {
			if (memoArr[i] > memoArr[i / 2] + 1) memoArr[i] = memoArr[i / 2] + 1;
		}

		if (i % 3 == 0) {
			if (memoArr[i] > memoArr[i / 3] + 1) memoArr[i] = memoArr[i / 3] + 1;
		}

		if (i % 5 == 0) {
			if (memoArr[i] > memoArr[i / 5] + 1) memoArr[i] = memoArr[i / 5] + 1;
		}
	}
}

int main() {
	input();
	solution();
	printf("%d", memoArr[X]);
}
