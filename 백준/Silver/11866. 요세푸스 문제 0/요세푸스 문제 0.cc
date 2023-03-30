#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n, k, f = 0;
	scanf("%d %d", &n, &k);

	queue<int> q;
	queue<int> answer;
	for (int i = 1; i <= n; i++) q.push(i);

	while (answer.size() != n) {
		for (int i = 0; i < k-1; i++) {
			f = q.front();
			q.pop();
			q.push(f);
		}
		f = q.front();
		q.pop();
		answer.push(f);
	}

	printf("<");
	while (answer.empty() != true) {
		if (answer.size() == 1) printf("%d", answer.front());
		else printf("%d, ", answer.front());
		answer.pop();
	}
	printf(">");
}