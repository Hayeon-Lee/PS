#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int map[26][26];
bool check[26][26];
vector<int> V;

int n;
int cnt = 0;
int dir[4][2] = { {-1,0}, {0,1},{1,0},{0,-1} };
void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (nx >= 0 && ny >= 0 && nx <= n && ny <= n) {
			if (check[nx][ny] == false && map[nx][ny] == 1) {
				check[nx][ny] = true;
				cnt++;
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == false && map[i][j] == 1) {
				check[i][j] = true;
				cnt++;
				dfs(i, j);
				V.push_back(cnt);
				cnt = 0;
			}
		}
	}

	printf("%d\n", V.size());
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++) printf("%d\n", V[i]);
}