#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M;
int** ice;

void input() {
	scanf("%d %d", &N, &M); //세로 길이 N, 가로 길이 M

	ice = new int* [N];

	for (int i = 0; i < N; i++) ice[i] = new int[M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &ice[i][j]);
		}
	}
}

bool solution(int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= M) {
		return false; //범위가 벗어났을 때
	}

	if (ice[i][j] == 0) { //내 위치에서 상하좌우 다 확인
		ice[i][j] = 1;
		solution(i - 1, j);
		solution(i + 1, j);
		solution(i, j - 1);
		solution(i, j + 1);
		return true;
	}
	return false;
}

int main(void) {
	input();
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (solution(i, j) == true) {
				result += 1;
			}
		}
	}

	printf("%d", result);
}
