#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, r;
int index = 0;

bool compare(int i, int j);
void init(vector<int> graph[]);
void dfs(int start, vector<int>graph[], bool visited[], int saved[]);

int main() {
	scanf("%d %d %d", &n, &m, &r);

	vector<int>* graph = new vector<int>[n + 1];
	bool* visited = new bool[n+1];
	int* saved = new int[n+1];
	fill(visited, visited + n + 1, false);
	fill(saved, saved + n + 1, 0);

	init(graph);
	dfs(r, graph, visited, saved);
	for (int i = 1; i <= n; i++) printf("%d\n", saved[i]);
}

bool compare(int i, int j) {
	return i > j;
}

void init(vector<int> graph[]) {
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);

		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end(), compare);
	}
}

void dfs(int start, vector<int>graph[], bool visited[], int saved[]) {
	visited[start] = true;
	saved[start] = ++index;

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (visited[next] != true) dfs(next, graph, visited, saved);
	}
}