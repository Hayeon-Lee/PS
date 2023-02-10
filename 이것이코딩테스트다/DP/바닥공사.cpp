#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int floorTile[1001];

void input() {
	scanf("%d", &N);
}

void solution() {
	floorTile[1] = 1;
	floorTile[2] = 3;
	for (int i = 3; i <= N; i++) {
		floorTile[i] = (floorTile[i - 1] + (floorTile[i - 2] * 2))%796796;
	}

	printf("%d", floorTile[N]);
}

int main() {
	input();
	solution();
}
