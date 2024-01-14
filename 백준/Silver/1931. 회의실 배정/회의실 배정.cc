#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int,int>v1, pair<int,int>v2) {
	if (v1.second == v2.second) return v1.first < v2.first;
	else return v1.second < v2.second;
}

int main() {
	int N;
	scanf("%d", &N);

	vector<pair<int, int>>v;

	for (int i = 0; i < N; i++) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		v.push_back(pair<int, int>(n1, n2));
	}
	sort(v.begin(), v.end(), cmp);

	int small = v[0].second;
	int count = 1;

	for (int i = 1; i < N; i++) {
		if (v[i].first >= small) {
			small = v[i].second;
			count++;
		}
	}

	printf("%d", count);
}