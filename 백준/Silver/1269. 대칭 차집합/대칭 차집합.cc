#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int nA, nB, tmp, count = 0;
	scanf("%d %d", &nA, &nB);

	set<int>A, B, DU;

	for (int i = 0; i < nA; i++) {
		scanf("%d", &tmp);
		A.insert(tmp);
	}

	for (int i = 0; i < nB; i++) {
		scanf("%d", &tmp);
		B.insert(tmp);
	}

	set<int>::iterator it;
	set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(DU, DU.begin()));
	set_difference(B.begin(), B.end(), A.begin(), A.end(), inserter(DU, DU.end()));

	for (it = DU.begin(); it != DU.end(); it++) count++;
	printf("%d", count);
}