#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int N, K; //맵 크기, 바이러스 종류
int** virusMap; //전염될 맵
priority_queue<tuple<int, int, int>> vq;
priority_queue<tuple<int, int, int>> tmp_v;
int S, X, Y; //전염 시간, 위치 좌표

int dir[4][2] = {
    {1,0}, //상
    {0,1}, //우
    {-1, 0}, //하
    {0,-1} //좌
};

void input() {
    scanf("%d %d", &N, &K);
    
    //맵 메모리 할당
    virusMap = new int* [N + 1];
    for (int i = 0; i < N + 1; i++) virusMap[i] = new int[N + 1];

    //맵 정보 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int n = 0;
            scanf("%d", &n);
            virusMap[i][j] = n;
            if (n != 0) vq.push(make_tuple(n*-1, i, j)); //바이러스라면 큐에 삽입
        }
    }
    
    scanf("%d %d %d", &S, &X, &Y);
}

//전염시키기
void infect(int k, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
            if (virusMap[nx][ny] == 0) {
                virusMap[nx][ny] = k; //해당 위치에 바이러스가 없어야만 전염 됨
                tmp_v.push(make_tuple(k*-1, nx, ny)); //새로운 자리를 추가
            }
        }
    }
}

void solution() {
    //전파시간 동안 실행
    for (int i = 0; i < S; i++) {
        while (!vq.empty()) {
            int k = get<0>(vq.top());
            int x = get<1>(vq.top());
            int y = get<2>(vq.top());
            vq.pop(); //삭제
            infect(k*-1, x, y);
        }
        
        while (!tmp_v.empty()) {
            vq.push(tmp_v.top());
            tmp_v.pop();
        }
    }
}

int main() {
    input();
    solution();
    printf("%d", virusMap[X][Y]);
}
