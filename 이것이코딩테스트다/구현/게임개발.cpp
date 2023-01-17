#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int direction[4][2] = {
	{-1, 0}, //북쪽
	{0, 1}, //동쪽
	{1, 0}, //남쪽
	{0, -1} //서쪽
};

//왼쪽으로 돌기: 북 서 남 동

int N, M; //맵의 세로 크기, 가로 크기
int A, B, d; //입력받은 서있는 칸의 좌표 (A,B)와 방향 d
int na, nb;
int** gameMap;
bool** visit;

void input() {
	scanf("%d %d", &N, &M);
	gameMap = new int* [N];
	for (int i = 0; i < N; i++) gameMap[i] = new int[M];

	visit = new bool* [N];
	for (int i = 0; i < N; i++) visit[i] = new bool[M];

	scanf("%d %d %d", &A, &B, &d); //좌표와 방향
	visit[A][B] = true;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) scanf("%d", &gameMap[i][j]);
	}
}

int turn_left() {
	d -= 1; //왼쪽으로 돌기
	if (d == -1) d = 3; //서쪽일 때 예외처리

	int tmpX = (A + direction[d][0]);
	int tmpY = (B + direction[d][1]);

	if (tmpX >= 0 && tmpX < N && tmpY >= 0 && tmpY < M) { //범위 체크 
		if (visit[tmpX][tmpY] == true) return 1; //방문한 곳이면 회전만 하고 끝
		else {
			if (gameMap[tmpX][tmpY] == 1) return 2;//방문안했는데 바다임
			if (gameMap[tmpX][tmpY] == 0) { //방문하지 않았고, 육지일 때는 전진
				A = tmpX;
				B = tmpY;
				visit[A][B] = true;
				return 3;
			}
		}
	}
	else return 4;
}

void solution() {
	int cnt = 1;
	int turn_cnt = 0;

	while (true) {
		int result = turn_left();
		if (result == 1 || result == 2 || result == 4) { //방문한 곳이거나 바다거나 못가면
			turn_cnt++;
		}

		if (result == 3) { //육지고 방문X한 곳이라 잘 방문했다면
			cnt++;
			turn_cnt = 0;
		}

		if (turn_cnt == 4) { //어느곳으로도 갈 수 없다면
			d++; //돌린 방향 원상복귀
			if (d == 4) d = 0;

			int tmpX = 0, tmpY = 0;
			if (d == 0) {
				tmpX = A + 1;
				tmpY = B;
			}
			if (d == 1) {
				tmpX = A;
				tmpY = B - 1;
			}
			if (d == 2) {
				tmpX = A - 1;
				tmpY = B;
			}
			if (d == 3) {
				tmpX = A;
				tmpY = B + 1;
			}

			if (tmpX < 0 || tmpX >= N || tmpY < 0 || tmpY >= M) break;
			else if (gameMap[tmpX][tmpY] == 1) break;
			else {
				A = tmpX;
				B = tmpY;
			}
		}

	}

	printf("%d", cnt);
}

int main() {
	input();
	solution();
}
