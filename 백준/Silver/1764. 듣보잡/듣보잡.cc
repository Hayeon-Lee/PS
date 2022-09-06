#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	set<string>notHear;
	set<string>notSee;
	string name;

	for (int i = 0; i < N; i++) {
		cin >> name;
		notHear.insert(name);
	}

	for (int i = 0; i < M; i++) {
		cin >> name;
		notSee.insert(name);
	}

	set<string>notHearAndSee;

	set_intersection(notHear.begin(), notHear.end(), notSee.begin(), notSee.end(),
		inserter(notHearAndSee, notHearAndSee.begin()));

	printf("%d\n", notHearAndSee.size());

	set<string>::iterator it;

	for (it = notHearAndSee.begin(); it != notHearAndSee.end(); it++) {
		cout << *it << "\n";
	}
}