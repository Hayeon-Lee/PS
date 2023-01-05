#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<char, int>alphabet;
string input;

int fixN = 8; //한 선택지에서 갈 수 있는 모든 루트는 총 8개
int w, h;

void initialize() {
	alphabet.insert(make_pair('a', 1));
	alphabet.insert(make_pair('b', 2));
	alphabet.insert(make_pair('c', 3));
	alphabet.insert(make_pair('d', 4));
	alphabet.insert(make_pair('e', 5));
	alphabet.insert(make_pair('f', 6));
	alphabet.insert(make_pair('g', 7));
	alphabet.insert(make_pair('h', 8));

	cin >> input;
	w = alphabet[input[0]];
	h = input[1] - '0';
}

void solution() {
	int answer = fixN;

	//왼쪽으로 2칸이 확보가 안되면 경우의 수 두 개 삭제
	if (w - 2 < 1) answer -= 2;
	else { //확보되었지만 1칸 이동 불가능할 때 경우의 수 삭제
		if (h - 1 < 1) answer -= 1; //위로
		if (h + 1 > 8) answer -= 1; //아래로
	}
	
	//오른쪽으로 2칸이 확보가 안되면 경우의 수 두 개 삭제
	if (w + 2 > 8) answer -= 2;
	else { //위와 동일 
		if (h - 1 < 1) answer -= 1;
		if (h + 1 > 8) answer -= 1;
	}
	
	//위로 2칸이 확보가 안되면 경우의 수 두 개 삭제
	if (h - 2 < 1) answer -= 2;
	else { //위와동일
		if (h - 1 < 1) answer -= 1;
		if (h + 1 > 8) answer -= 1;
	}

	//아래로 2칸이 확보가 안되면 경우의 수 두 개 삭제
	if (h + 2 > 8) answer -= 2;
	else { //위와 동일
		if (h - 1 < 1) answer -= 1;
		if (h + 1 > 8) answer -= 1;
	}

	printf("%d", answer);
	
}

int main() {
	initialize();
	solution();
}
