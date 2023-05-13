#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long int A;
long long int B;

int main() {
	scanf("%lld %lld", &A, &B);
	printf("%lld", ((A + B) * (A - B)));
}
