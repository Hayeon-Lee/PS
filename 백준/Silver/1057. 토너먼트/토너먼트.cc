#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int A = 0, B = 0;
int tmp_A, tmp_B;
int N = 0;

void setNextRound() {
	//A
	if (tmp_A % 2 == 0) tmp_A /= 2;
	else tmp_A = ((tmp_A + 1) / 2);

	//B
	if (tmp_B % 2 == 0) tmp_B /= 2;
	else tmp_B = ((tmp_B + 1) / 2);
}

int main()
{
	scanf("%d %d %d", &N, &A, &B);

	tmp_A = A;
	tmp_B = B;
	
	int count = 1;

	while (1) {
		setNextRound();
		if (tmp_A == tmp_B) {
			printf("%d\n", count);
			return 0;
		}
		else {
			count++;
		}

		if (tmp_A == 0 || tmp_B == 0) {
			printf("-1\n");
			return 0;
		}
	}
}