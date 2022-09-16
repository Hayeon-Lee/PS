#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int N, M;

stack <int> S;
queue <int> q;

void dfs(int** g, int V);
void bfs(int** g, int V);

int main() {
	int V;
	scanf("%d %d %d", &N, &M, &V);
	S.push(V);
	q.push(V);

	int** bfs_graph = new int* [N];
	int** dfs_graph = new int* [N];

	for (int i = 0; i < N; i++) bfs_graph[i] = new int[N];
	for (int i = 0; i < N; i++) dfs_graph[i] = new int[N];

	for (int i = 0; i < N; i++) { for (int j = 0; j < N; j++) bfs_graph[i][j] = 0; }

	int x1, x2;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x1, &x2);
		bfs_graph[x1 - 1][x2 - 1] = 1;
		bfs_graph[x2 - 1][x1 - 1] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) dfs_graph[i][j] = bfs_graph[i][j];
	}

	printf("%d ", S.top());
	for (int i = 0; i < N; i++) dfs_graph[i][S.top() - 1] = 0;
	dfs(dfs_graph, V);

	printf("\n%d ", q.front());
	for (int i = 0; i < N; i++) bfs_graph[i][q.front() - 1] = 0;
	bfs(bfs_graph, V);
}

void dfs(int** g, int V)
{
	for (int i = 0; i < N; i++) {
		if (g[V-1][i] == 1) {
			V = i + 1; //정점 바꾸기 
			for (int j = 0; j < N; j++) g[j][V - 1] = 0;
			S.push(V); //정점 스택에 추가
			printf("%d ", S.top());
			dfs(g, S.top());
		}

		if (i == N - 1) {
			if(S.empty() == false) S.pop();
			
			if (S.empty() == true) return;
			else dfs(g, S.top());
		}
	}
}

void bfs(int** g, int V) {
	for (int i = 0; i < N; i++) {
		if (g[q.front() - 1][i] == 1) {
			q.push(i + 1);
			for (int j = 0; j < N; j++) g[j][i] = 0; //방문처리
		}
	}

	q.pop();

	if (q.empty() == true) return;
	else {
		printf("%d ", q.front());
		bfs(g, q.front()-1);
	}
}
