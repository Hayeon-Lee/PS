#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int N, M;
map<string, string> m;

void solution() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		string site;
		string pw;
		cin >> site;
		cin >> pw;
		m[site] = pw;
	}

	for (int i = 0; i < M; i++) {
		string f;
		cin >> f;
		cout << m[f] << "\n";
	}
}

int main() {
	solution();
}