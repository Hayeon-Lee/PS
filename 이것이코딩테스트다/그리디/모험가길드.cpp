#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int* X;

void input() {
    scanf("%d", &N);
    X = new int[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }
    sort(X, X + N);
}

void solution() {
    int i = 0; 
    int groupN = 0;
    int count = 0; // 지금 그룹에 속해있는 모험가의 수
    for (int i = 0; i < N; i++) {
        count++; //반복문이 지나갈 때마다 해당 위치의 사람을 그룹에 넣어준다.
        if (count >= X[i]) { //지금 그룹에 속한 사람이, 현 인덱스의 값보다 같아지는 시점이면 그 그룹은 정원이 다 찼으므로 그만 모집.
            groupN++;
            count = 0;
        }
    }
    printf("%d", groupN);
}

int main() {
    input();
    solution();
}
