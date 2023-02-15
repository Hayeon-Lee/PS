#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;
int* student;

void input() {
	scanf("%d %d", &N, &M);
	student = new int[N+1];

	for (int i = 0; i <= N; i++) student[i] = i; //서로의 부모는 자기 자신 
}

int find_parent(int x) {
	if (student[x] != x) { //자신이 자신의 부모가 아니라면
		student[x] = find_parent(student[x]); 
	}
	return student[x];
}

void unionS(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);

	if (a < b) student[b] = a;
	if (a > b) student[a] = b;
}

void findS(int a, int b) {
	if (find_parent(a) == find_parent(b)) printf("YES\n");
	else printf("NO\n");
}

void solution() {
	for (int i = 0; i < M; i++) {
		int order, a, b;
		scanf("%d %d %d", &order, &a, &b);

		if (order == 0) unionS(a, b);
		else findS(a, b);
	}
}

int main() {
	input();
	solution();
}
