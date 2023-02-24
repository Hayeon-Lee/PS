#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int* home;

bool compare(pair<int, int>a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

void input() {
    scanf("%d", &N);
    home = new int[N];

    for (int i = 0; i < N; i++) {
        int n;
        scanf("%d", &n);
        home[i] = n;
    }
}

void solution() {
    sort(home, home + N); //집 정렬
    printf("%d", home[(N - 1) / 2]);
   }

int main() {
    input();
    solution();
}
