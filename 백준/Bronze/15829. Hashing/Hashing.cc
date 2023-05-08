#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//-'a'+1

int r = 31;
int M = 1234567891;

int L = 0;
string input;

long long int total = 0;

int main() {
	scanf("%d", &L);
	cin >> input;

	for (int i = 0; i < L; i++) {
		int alpha = input[i] - 'a' + 1;
		long long int result = alpha * (int)pow(r, i);
		total += result;
	}

	printf("%lld", total);
}
