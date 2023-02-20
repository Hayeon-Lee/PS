#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> *city;
bool* visited;
int N, M, K, X;
int* dist;

void input() {
    scanf("%d %d %d %d", &N, &M, &K, &X);

    visited = new bool[N + 1];
    dist = new int[N + 1];

    for (int i = 0; i < N + 1; i++) {
        visited[i] = false; //false로 초기화
        dist[i] = -1; //거리 -1로 초기화
    }

    city = new vector<int>[N + 1];

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        city[a].push_back(b);
    }

    for (int i = 1; i < N + 1; i++) {
        sort(city[i].begin(), city[i].end());
    }

    dist[X] = 0; //시작점==도착점은 0임
    for (int i = 0; i < city[X].size(); i++) dist[city[X][i]] = 1; //X와 연결된 지점은 모두 최단거리 1임.
}

void solution(int start) {
    int current = start;
    visited[current] = true;

    for(int i = 0; i < city[current].size(); i++) {
        int next = city[current][i];
        if (visited[next] == false) {
            if (dist[next] == -1) dist[next] = dist[current] + 1;
            solution(next);
        }
    }
}

int main() {
    input();
    solution(X);
    int tmp = 0;
    for (int i = 1; i < N + 1; i++) {
        if (dist[i] == K) {
            tmp = 1;
            printf("%d\n", i);
        }
    }

    if (tmp == 0) printf("-1");
}
