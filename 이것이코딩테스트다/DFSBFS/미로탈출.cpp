#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int** map;
queue<pair<int, int>> q;

int direction[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

void input() {
	scanf("%d %d", &N, &M);
	map = new int* [N];
	for (int i = 0; i < N; i++) map[i] = new int[M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) scanf("%d", &map[i][j]);
	}
}

void solution() {
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + direction[i][0];
			int dy = y + direction[i][1];

			if (dx < 0 || dx >= N || dy < 0 || dy >= M) continue;
			if (map[dx][dy] == 0) continue;
			if (map[dx][dy] == 1) {
				map[dx][dy] = map[x][y] + 1;
				q.push(make_pair(dx, dy));
			}
		}
	}

	printf("%d", map[N - 1][M - 1]);
}

int main(void) {
	input();
	solution();
}
