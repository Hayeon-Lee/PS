#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, v;

//bool compare(vector <int>& v1, vector<int>& v2);
void init(vector<int>* graph);
void dfs(vector<int>* graph, bool *visited, int now);
void bfs(vector <int>* graph, bool *visited, int now);

int main(void) {
	scanf("%d %d %d", &n, &m, &v);

	vector<int>* graph = new vector<int>[n + 1];
	bool* visited = new bool[n + 1];

	init(graph);

	fill(visited, visited + n + 1, false);
	dfs(graph, visited, v);

	printf("\n");

	fill(visited, visited + n + 1, false);
	bfs(graph, visited, v);
}

/*bool compare(vector <int>& v1, vector<int>& v2) {
	if (v1[0] == v2[0]) return v1[1] < v2[1];
	else return v1[0] < v2[0];
}*/

void init(vector<int>* graph) {
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);

		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
}

void dfs(vector<int>* graph, bool* visited, int now) {
	visited[now] = true;
	printf("%d ", now); //처음 시작지점 출력

	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (visited[next] != true) dfs(graph, visited, next);
	}
}

void bfs(vector <int>* graph, bool* visited, int now) {
	queue<int> q;
	visited[now] = true;
	q.push(now);
	printf("%d ", now);

	while (q.empty() != true) {
		int point = q.front();
		q.pop();
		for (int i = 0; i < graph[point].size(); i++) {
			int next = graph[point][i];
			if (visited[next] != true) {
				q.push(next);
				visited[next] = true;
				printf("%d ", next);
			}
		}
	}
}