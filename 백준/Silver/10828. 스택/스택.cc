#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int>s;
int n;

void solution() {
	scanf("%d", &n);
	string order;
	for (int i = 0; i < n; i++) {
		cin >> order;
		int x = 0;
		if (order == "push") {
			scanf("%d", &x);
			s.push(x);
		}
		if (order == "pop" || order == "top") {
			if (s.empty() == false) {
				printf("%d\n", s.top());
				if(order == "pop") s.pop();
			}
			else printf("-1\n");
		}
		if (order == "size") printf("%d\n", s.size());
		if (order == "empty") printf("%d\n", s.empty());
	}
}

int main() {
	solution();
}