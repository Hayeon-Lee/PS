#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, tmp; //숫자 카드의 개수, 구해야 하는 갯수
	map<int, int> numbers;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		
		//numbers에 tmp가 있으면 value를 하나 증가
		if (numbers.find(tmp) != numbers.end()) {
			numbers[tmp]++;
		}
		//numbers에 tmp가 없으면 insert, value는 1
		else {
			numbers.insert({ tmp, 1 });
		}
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &tmp);
		
		//있으면
		if (numbers.find(tmp) != numbers.end()) printf("%d ", numbers[tmp]);
		else printf("0 ");
	}
}