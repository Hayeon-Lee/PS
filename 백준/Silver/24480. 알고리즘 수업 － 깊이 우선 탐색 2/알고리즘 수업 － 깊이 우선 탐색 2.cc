#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool>visited;
vector<int> point;

int N, M;
int index = 0;

void init();
void dfs(int R);

int main() {
	int R;
	scanf("%d %d %d", &N, &M, &R);

	init();
	dfs(R);

	for (int i = 1; i <= N; i++) printf("%d\n", point[i]);
}

bool compare(int graph1,int graph2) {
	return graph1 > graph2;
}

void init() {
	graph.resize(N+1);//1차원크기 N+1로 확대
	visited.resize(N + 1);
	point.resize(N + 1);

	int tmp1, tmp2;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &tmp1, &tmp2);

		graph[tmp1].push_back(tmp2); 
		graph[tmp2].push_back(tmp1);
	}

	for (int i = 0; i <= N; i++) sort(graph[i].begin(), graph[i].end(), compare); //오름차순 정렬 시작정점으로부터.
}

void dfs(int R) {
	point[R] = ++index;
	visited[R] = true;

	for (int i = 0; i<graph[R].size(); i++) {
		int tmp = graph[R][i];
		if (visited[tmp] == false) dfs(tmp);
	}
}