#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int> d;
int n;

void solution() {
	scanf("%d", &n);
	string order;
	int x = 0;
	for (int i = 0; i < n; i++) {
		cin >> order;
		if (order == "push_front") {
			scanf("%d", &x);
			d.push_front(x);
		}
		if (order == "push_back") {
			scanf("%d", &x);
			d.push_back(x);
		}
		if (order == "pop_front" || order == "front") {
			if (d.empty() != true) {
				printf("%d\n", d.front());
				if(order == "pop_front") d.pop_front();
			}
			else printf("-1\n");
		}
		if (order == "pop_back" || order == "back") {
			if (d.empty() != true) {
				printf("%d\n", d.back());
				if(order == "pop_back") d.pop_back();
			}
			else printf("-1\n");
		}
		if (order == "size") printf("%d\n", d.size());
		if (order == "empty") printf("%d\n", d.empty());

	}
}

int main() {
	solution();
}