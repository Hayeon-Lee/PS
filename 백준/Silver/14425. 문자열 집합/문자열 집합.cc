#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N, M, count = 0;
	scanf("%d %d", &N, &M);

	set<string> strings;
	string tmp;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		strings.insert(tmp);
	}

	set<string>::iterator it;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		//it = strings.find(tmp);

		if (strings.find(tmp) != strings.end()) count++;
	}

	printf("%d", count);
}