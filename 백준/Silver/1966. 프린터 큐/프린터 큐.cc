#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int test_n;
	scanf("%d", &test_n);

	for (int i = 0; i < test_n; i++) {
		int counts = 0;
		int to_find = 0;
		scanf("%d %d", &counts, &to_find);

		priority_queue<int> pq;
		queue<pair<int, int>> q;

		for (int j = 0; j < counts; j++) {
			int input = 0;
			scanf("%d", &input);

			pq.push(input);
			q.push({ j, input });
		}
		
		int l = 0, v = 0, order = 0;

		while (!q.empty()) {
			l = q.front().first;
			v = q.front().second;
			q.pop();
			
			if (pq.top() == v) {
				pq.pop();
				order++;
				if (l == to_find)
				{
					printf("%d\n", order);
					break;
				}
			}
			else q.push({ l, v });
		}
	}
}