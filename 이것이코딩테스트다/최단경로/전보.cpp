#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, C;
int** city;
int* dist;
priority_queue<pair<int, int>> heapQ;

void input() {
	scanf("%d %d %d", &N, &M, &C);

	//간선 저장 배열 
	city = new int* [N+1];
	for (int i = 0; i < N + 1; i++) city[i] = new int[N + 1];

	dist = new int[N + 1]; //거리 저장 배열 
	for(int i=0; i<N+1; i++) dist[i] = 987654321;
	
	//무한으로 초기화
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N + 1; j++) city[i][j] = 987654321;
	}

	//경로 입력받기
	for (int i = 0; i < M; i++) {
		int X, Y, d;
		scanf("%d %d %d", &X, &Y, &d);

		city[X][Y] = d;
	}
}

void solution() {
	heapQ.push(make_pair(0, C)); //첫번째 시작점 힙에 넣기
	dist[C] = 0;

	while (!heapQ.empty()) {
		int cost = (-1) * heapQ.top().first; //가장 짧은 경로
		int cur = heapQ.top().second; //가장 짧은 경로를 가진 노드
		heapQ.pop();

		for (int i = 1; i <N+1; i++) {
			int nextCost = city[cur][i];

			if (dist[i] > cost + nextCost) {
				dist[i] = cost + nextCost;
				heapQ.push(make_pair(-1 * dist[i], i));
			}
		}
	}

	int total = 0, cnt = 0;
	for (int i = 1; i < N + 1; i++) if (dist[i] < 987654321) {
		total += dist[i];
		cnt++;
	}

	printf("%d %d", cnt, total);
}

int main() {
	input();
	solution();
}
