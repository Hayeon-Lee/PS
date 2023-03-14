#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int *tiles = new int[n+1];
	for (int i = 0; i <= n; i++) tiles[i] = 0;

	//n이 1일 때 방법 1개
	tiles[1] = 1;

	//n이 2일 때 방법 3개
	tiles[2] = 3;

	//옆에 1칸만 남은 경우 2*1
	// 옆에 2칸만 남은 경우 1*2 2개, 2*2 1개
	for (int i = 3; i <= n; i++) {
		tiles[i] = (tiles[i - 1] + (tiles[i - 2] * 2)) % 10007;
	}

	printf("%d", tiles[n]);
}