#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int hp) {
    int answer = 0;
    
    int tmp = hp;
    answer += (tmp/5);
    tmp %= 5;
    
    answer += (tmp / 3);
    tmp %= 3;
    
    answer += tmp;
    
    
    return answer;
}