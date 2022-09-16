#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int hour, min;
	scanf("%d %d", &hour, &min);

	int time;
	scanf("%d", &time);

	int t1 = time / 60;
	int t2 = time % 60;

	hour += t1;
	min += t2;

	if (min >= 60) {
		min -= 60;
		hour += 1;
	}

	if (hour >= 24) {
		hour -= 24;
	}

	printf("%d %d", hour, min);
}
