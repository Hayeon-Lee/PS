#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const char *morse[26] = {
        ".-",    // a
        "-...",  // b
        "-.-.",  // c
        "-..",   // d
        ".",     // e
        "..-.",  // f
        "--.",   // g
        "....",  // h
        "..",    // i
        ".---",  // j
        "-.-",   // k
        ".-..",  // l
        "--",    // m
        "-.",    // n
        "---",   // o
        ".--.",  // p
        "--.-",  // q
        ".-.",   // r
        "...",   // s
        "-",     // t
        "..-",   // u
        "...-",  // v
        ".--",   // w
        "-..-",  // x
        "-.--",  // y
        "--.."   // z
    };

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* letter) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char)*1000);
    
    int index = 0;
    char *ptr = strtok(letter, " ");
    while (ptr != NULL) {
        for(int i=0; i<26; i++) {
            if (strcmp(morse[i], ptr)==0) {
                char now = 'a'+i;
                answer[index] = now;
                index += 1;
            }
        }
        ptr = strtok(NULL, " ");
    }
    
    answer[index] = '\0';
    
    return answer;
}