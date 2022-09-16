#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

int N;
int M;
int Count = 0;
stack <int> S;

void dfs(int** net, int V);

int main() {
	int V;
	scanf("%d %d", &N, &M);
	
	int** net = new int* [N];
	for (int i = 0; i < N; i++) net[i] = new int[N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) net[i][j] = 0;
	}

	int x1, x2;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x1, &x2);
		net[x1 - 1][x2 - 1] = 1;
		net[x2 - 1][x1 - 1] = 1;
	}

	S.push(1); //1번 컴퓨터 감염 시작
	for (int i = 0; i < N; i++) net[i][0] = 0; //1번 방문처리
	dfs(net, 1);
	printf("%d", Count);
}

void dfs(int** net, int V)
{
	for (int i = 0; i < N; i++) {
		if (net[V - 1][i] == 1) {
			S.push(i + 1); //감염컴퓨터 push
			Count++;
			for (int j = 0; j < N; j++) net[j][i] = 0; //방문처리
			break;
		}
		if (i == N - 1) //감염컴퓨터가 없음
		{
			if (S.empty() == false) S.pop();
			if (S.empty() == false) dfs(net, S.top());
			else return;
		}
	}

	if(S.empty() == false) dfs(net, S.top());
}
