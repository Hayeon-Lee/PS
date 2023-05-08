#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	while (1) {
		stack<char> s;
		string input;
		getline(cin, input);

		int flag = 0;

		if (input[0] == '.' && input.length() == 1) {
			break;
		}

		else {
			for (int i = 0; i < input.length(); i++) {
				if (input[i] == '(') s.push(input[i]);
				if (input[i] == '[') s.push(input[i]);
				if (input[i] == ')') {
					if (s.empty()!=true && s.top() == '(') s.pop();
					else {
						flag = 1;
						printf("no\n");
						break;
					}
				}
				if (input[i] == ']') {
					if (s.empty() != true && s.top() == '[') s.pop();
					else {
						flag = 1;
						printf("no\n");
						break;
					}
				}
			}

			if (flag == 0) {
				if (s.empty() == false) printf("no\n");
				if (s.empty() == true) printf("yes\n");
			}
		}
	}
}
