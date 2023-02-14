#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int V, E, X, K;
int** roadMap;

void input() {
	scanf("%d %d", &V, &E);
	roadMap = new int* [V+1];

	for (int i = 0; i < V+1; i++) { //메모리 할당
		roadMap[i] = new int[V + 1];
	}

	//간선 무한으로 초기화
	for (int i = 0; i < V + 1; i++) {
		for (int j = 0; j < V + 1; j++) {
			roadMap[i][j] = 987654321;
		}
	}

	for (int i = 0; i < E; i++) { //간선경로 입력
		int a, b;
		scanf("%d %d", &a, &b);
		roadMap[a][b] = 1;
		roadMap[b][a] = 1;
	}

	scanf("%d %d", &X, &K); //도착점과 경유지


	for (int i = 1; i <= V; i++) {
		roadMap[i][i] = 0; //자기자신으로 가는 비용은 0
	}
}

void solution() {
	for (int i = 1; i <= V; i++) { //중간 지점
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
					int direct = roadMap[j][k]; //j에서 k로 바로 직진
					int midP = roadMap[j][i] + roadMap[i][k]; //j->i->k
					roadMap[j][k] = min(direct, midP);//작은값으로 초기화
				
			}
		}
	}

	int answer = roadMap[1][K] + roadMap[K][X];
	if (answer >= 987654321) printf("-1");
	else printf("%d", answer);
}

int main() {
	input();
	solution();
}
