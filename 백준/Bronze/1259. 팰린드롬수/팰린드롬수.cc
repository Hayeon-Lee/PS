#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	string r, original;
	cin >> r;
	original = r;

	while (r != "0") {
		reverse(r.begin(), r.end());

		if (r == original) printf("yes\n");
		else printf("no\n");

		cin >> r;
		original = r;
	}
}
