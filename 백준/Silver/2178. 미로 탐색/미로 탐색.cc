#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dir[4][2] = {
	{-1,0}, //상
	{0,1}, //우
	{1,0}, //하
	{0,-1} //좌
}; 

int N, M;
queue<pair<int, int>> q;
int maze[101][101] = { 0, };
int dist[101][101] = { 0, };
bool visited[101][101] = { false, };

void fillVar();
void bfs();

int main() {
	fillVar();

	q.push(make_pair(1, 1));
	visited[1][1] = true;
	dist[1][1] = 1;

	bfs();
	printf("%d", dist[N][M]);
}

void fillVar() {
	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) scanf("%1d", &maze[i][j]);
	}
}

void bfs() {

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (maze[nx][ny] == 1 && visited[nx][ny] == false
				&& nx >= 1 && ny >= 1 && nx <= N && ny <= M) {
				q.push(make_pair(nx, ny)); //4방향 중 갈 수 있는 곳으로
				visited[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}