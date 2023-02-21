#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int wall_count = 0;
int safetyZone = 0;
int ori_map[9][9] = { 0, };
int wall_map[9][9] = { 0, };

int dir[4][2] = {
	{-1,0}, //상
	{0,1}, //우
	{1, 0}, //하
	{0,-1}, //좌
};

void input() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf("%d", &ori_map[i][j]);
			wall_map[i][j] = ori_map[i][j];
		}
	}
}

//바이러스 퍼뜨리기
void virus(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
			if (wall_map[nx][ny] == 0) {
				wall_map[nx][ny] = 2;
				virus(nx, ny);
			}
		}
	}
}

//안전영역 계산하기
int get_safetyZone() {
	int s = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (wall_map[i][j] == 0) s++;
		}
	}
	return s;
}

//전체 수행하기
void solution() {
	//벽 개수가 3개면
	if (wall_count == 3) {
		//벽 설치 상태를 저장하기
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				wall_map[i][j] = ori_map[i][j];
			}
		}
		//바이러스를 전파시키기
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (wall_map[i][j] == 2) virus(i, j);
			}
		}

		//전파시킨 다음 최댓값 구하기
		safetyZone = max(get_safetyZone(), safetyZone);
		return;
	}

	//울타리 설치하기(벽 개수가 3개 아닐 때)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (ori_map[i][j] == 0) {
				ori_map[i][j] = 1;
				wall_count++;
				solution();
				ori_map[i][j] = 0;
				wall_count--;
			}
		}
	}
}

int main() {
	input();
	solution();
	printf("%d", safetyZone);
}
