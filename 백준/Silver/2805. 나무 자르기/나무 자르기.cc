#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	unsigned long long int n, m;
	unsigned long long int s, l, mid;
	unsigned long long int total;

	scanf("%lld %lld", &n, &m);
	unsigned long long int* trees = new unsigned long long int[n];

	for (int i = 0; i < n; i++) scanf("%lld", &trees[i]);

	sort(trees, trees + n);
	s = 0;
	l = trees[n - 1];

	while (s <= l) {
		total = 0;
		mid = (s + l) / 2;
		for (int i = 0; i < n; i++) if (trees[i] > mid)  total += trees[i] - mid;

		if (total >= m) s = mid + 1;
		else if (total < m) l = mid - 1;
	}
	printf("%lld\n", l);
}