#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> q;
int n;

void solution() {
	scanf("%d", &n);
	string order;
	
	for (int i = 0; i < n; i++) {
		cin >> order;
		int x = 0;
		if (order == "push") {
			scanf("%d", &x);
			q.push(x);
		}
		if (order == "pop" || order == "front") {
			if (q.empty() == false) {
				printf("%d\n", q.front());
				if(order == "pop") q.pop();
			}
			else printf("-1\n");
		}
		if (order == "size") printf("%d\n", q.size());
		if (order == "empty") printf("%d\n", q.empty());
		if (order == "back") {
			if (q.empty() == false) printf("%d\n", q.back());
			else printf("-1\n");
		}
	}
}

int main() {
	solution();
}