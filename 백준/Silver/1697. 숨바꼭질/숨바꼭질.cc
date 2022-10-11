#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

bool visited[100001] = { false, };
int N, K;

int bfs(int point, int d);
int main()
{
	scanf("%d %d", &N, &K);
	visited[N] = true;
	printf("%d", bfs(N, 0));
}

int bfs(int point, int d) {
	queue<pair<int, int>> q;
	q.push({ point, d });

	while (!q.empty()) {
		int next = q.front().first;
		int dist = q.front().second;

		if (next == K) {
			return dist;
		}
		q.pop();

		if (next + 1 <= 100000 && visited[next + 1] != true) {
			q.push({ next + 1, dist + 1 });
			visited[next + 1] = true;
		}
		if (next - 1 >= 0 && visited[next - 1] != true) {
			q.push({ next - 1, dist + 1 });
			visited[next - 1] = true;
		}
		if (next * 2 <= 100000 && visited[next * 2] != true) {
			q.push({ next * 2, dist + 1 });
			visited[next * 2] = true;
		}
	}
}