#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//-'a'+1

int r = 31;
unsigned long long int M = 1234567891;

int L = 0;
string input;

unsigned long long int total = 0;

int main() {
	scanf("%d", &L);
	cin >> input;

	for (int i = 0; i < L; i++) {
		unsigned long long int alpha = input[i] - 'a' + 1;
		unsigned long long int tmp_r = 1;
		for (int j = 0; j < i; j++) {
			tmp_r *= r;
			tmp_r %= M;
		}
		total += (alpha * tmp_r);
	}

	printf("%lld", total%M);
}
