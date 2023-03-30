#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		string input;
		stack<char> check;
		cin >> input;

		string result = "YES";

		for (int j = 0; j < input.size(); j++) {
			if (input[j] == '(') check.push(input[j]);
			else if (check.empty() == false && input[j] == ')') check.pop();
			else {
				result = "NO";
				break;
			}
		}

		if (check.empty() == false) result = "NO";
		cout << result << "\n";
	}
}