#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	getchar();
	
	char * tracks = (char*)malloc(n * sizeof(char));
	for(int i=0; i<n; i++) {
		char input;
		scanf("%c", &input);
		tracks[i] = input;
		getchar();
	}
	
	char hellobit;
	scanf("%c", &hellobit);
	
	int answer = 0;
	
	for (int i=0; i<n; i++) {
		if (tracks[i] == hellobit) {
			answer += 1;
		}
	}
	
	printf("%d", answer); 
	
	return 0;
}
