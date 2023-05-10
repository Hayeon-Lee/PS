#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

int K;
stack <int> numbers;

int main() {
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int input;
		scanf("%d", &input);

		if (input == 0) numbers.pop();
		else numbers.push(input);
	}
	
	int total = 0;
	while (numbers.empty() == false) {
		total += numbers.top();
		numbers.pop();
	}
	printf("%d", total);
}