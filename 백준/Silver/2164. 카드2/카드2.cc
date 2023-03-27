#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

deque<int> dq;
int N;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) dq.push_back(i);

	while (dq.size() != 1) {
		dq.pop_front();
		int f = dq.front();
		dq.pop_front();
		dq.push_back(f);
	}

	printf("%d", dq.front());
}