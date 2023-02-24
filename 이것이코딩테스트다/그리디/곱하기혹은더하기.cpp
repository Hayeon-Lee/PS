#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int inputLength;
string inputString;
int inputInt[21] = { 0, };

bool compare(int i, int j) {
    return i > j;
}

void input() {
    cin >> inputString;
    inputLength = inputString.size();

    for (int i = 0; i < inputLength; i++) {
        inputInt[i] = inputString[i] - '0'; //정수로 변환
    }
}

void solution() {
    int result = inputInt[0];
    for (int i = 1; i < inputLength; i++){
        if (result == 0) result += inputInt[i]; //현재 값이 0일 때만 덧셈처리
        else {
            int add = (result + inputInt[i]); //더한 값
            int multi = (result * inputInt[i]); //곱한 값
            result = max(add, multi); //둘 중 큰 것으로 저장
        }
    }
    printf("%d", result);
}

int main() {
    input();
    solution();
}
