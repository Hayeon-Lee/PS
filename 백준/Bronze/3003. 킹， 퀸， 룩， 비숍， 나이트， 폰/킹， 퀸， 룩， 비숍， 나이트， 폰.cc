#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
int main() {
	int arr[6];
	int answer[6] = { 1, 1, 2, 2, 2, 8 };

	for(int i = 0; i < 6; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 6; i++) printf("%d ", answer[i] - arr[i]);
}