#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n;
queue<int> inputs;
stack<int> numbers;
queue<char> order;

int main() {
	scanf("%d", &n);

	//입력받기
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		scanf("%d", &tmp);
		inputs.push(tmp);
	}

	int index = 1;
	while (inputs.empty() != true) {
		if (numbers.empty() != true && numbers.top() == inputs.front()) {
			numbers.pop();
			inputs.pop();
			order.push('-');
		}
		else if (index <= inputs.front()) {
			while (index <= inputs.front()) {
				numbers.push(index++);
				order.push('+');
			}
		}
		else {
			printf("NO");
			return 0;
		}
	}

	while (order.empty() != true) {
		printf("%c\n", order.front());
		order.pop();
	}
}