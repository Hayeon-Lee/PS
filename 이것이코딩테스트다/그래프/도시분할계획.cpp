#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int N, M;
int* parent;
int last = 0;
int result = 0;
vector<tuple<int, int, int>> edges;

bool compareTuple(tuple<int, int, int>a, tuple<int, int, int>b) {
	return get<0>(a) < get<0>(b);
}

void input() {
	scanf("%d %d", &N, &M);
	parent = new int[N+1];

	for (int i = 0; i <= N; i++) parent[i] = i;

	for (int i = 0; i < M; i++) {
		int cost, a, b;
		scanf("%d %d %d", &a, &b, &cost);
		edges.push_back(make_tuple(cost, a, b));
	}

	sort(edges.begin(), edges.end(), compareTuple); //정렬
}

int find_parent(int x) {
	if (parent[x] != x) {
		parent[x] = find_parent(parent[x]);
	}
	return parent[x];
}

void unionP(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

void solution() {
	for (int i = 0; i < M; i++) {
		int cost = get<0>(edges[i]);
		int a = get<1>(edges[i]);
		int b = get<2>(edges[i]);

		if (find_parent(a) != find_parent(b)) {
			unionP(a, b);
			result += cost;
			last = cost;
		}
	}
	printf("%d", result - last);
}

int main() {
	input();
	solution();
}
