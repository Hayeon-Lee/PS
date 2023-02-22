#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int** city;

void input() {
    scanf("%d %d", &n, &m);

    //도시 메모리 할당
    city = new int* [n+1];
    for (int i = 0; i < n + 1; i++) city[i] = new int[n + 1];

    //도시 모든 칸을 무한으로 할당
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            city[i][j] = 987654321;
        }
    }

    //자기 자신에게 가는 비용은 0
    for (int i = 0; i < n + 1; i++) city[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, cost;
        scanf("%d %d %d", &a, &b, &cost);
        city[a][b] = min(cost, city[a][b]);//더 작은 값으로 저장
    }
}

void solution() {
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            for (int k = 1; k < n + 1; k++) {
                if(j!=k) city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
            }
        }
    }
}

int main() {
    input();
    solution();
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (city[i][j] == 987654321) printf("0 ");
            else printf("%d ", city[i][j]);
        }
        printf("\n");
    }
}
