#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int n1, n2, n3;
	int prize = 0;
	scanf("%d %d %d", &n1, &n2, &n3);
	
	if (n1 == n2 && n2 == n3) {
		prize += 10000;
		prize += n1 * 1000;
		
		printf("%d", prize);
	}
	
	else if (n1 == n2 || n1 == n3) {
		prize += 1000;
		prize += 100 * n1;
		printf("%d", prize);
	}

	else if (n2 == n3) {
		prize += 1000;
		prize += 100 * n2;
		printf("%d", prize);
	}

	else {
		int big = 0;
		n1 > n2 ? (n1 > n3 ? big = n1 : big = n3) : (n2 > n3 ? big = n2 : big = n3);
		prize = big * 100;
		printf("%d", prize);
	}
	
}
