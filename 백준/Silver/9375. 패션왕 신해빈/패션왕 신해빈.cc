#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void solution(map<string, int> wears);

int testN;

void input() {
	scanf("%d", &testN);

	string name;
	string wearType;

	for (int i = 0; i < testN; i++) {
		int cnt = 0;
		scanf("%d", &cnt);
		map<string, int> wears;
		for (int j = 0; j < cnt; j++) {
			cin >> name;
			cin >> wearType;
			if (wears.count(wearType) == 0) wears.insert({ wearType, 1 });
			else wears[wearType]++;
		}
		solution(wears);
	}
}

void solution(map<string, int>wears) {
	int answer = 1;
	for (auto iter = wears.begin(); iter != wears.end(); iter++) {
		answer *= ((iter->second) + 1);
	}
	answer -= 1;
	printf("%d\n", answer);
}

int main() {
	input();
}