#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    
    long long int size = 0;
    long long int save_n = n;
    
    while (save_n > 0) {
        size += 1;
        save_n /= 10;
    }
    
    int* answer = (int *)malloc(size * sizeof(int));
    
    long long int index = 0;
    save_n = n;
    while (save_n > 0) {
        answer[index] = save_n % 10;
        save_n /= 10;
        index += 1;
    }
    
    return answer;
}