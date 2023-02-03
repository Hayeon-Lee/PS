#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N;
vector <pair<string, int>> students;

bool compare(pair<string, int>i, pair<string, int>j) {
	return i.second < j.second;
}

void input() {
	scanf("%d", &N);

	string name;
	int score;

	for (int i = 0; i < N; i++) {
		cin >> name;
		scanf("%d", &score);

		students.push_back(make_pair(name, score));
	}
}

void solution() {
	sort(students.begin(), students.end(), compare);

	vector<pair<string, int>>::iterator it;

	for (it = students.begin(); it != students.end(); it++) cout << (*it).first << ' ';
}

int main(void) {
	input();
	solution();
}
