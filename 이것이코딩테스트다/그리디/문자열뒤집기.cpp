#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string userInput;
int group1 = 0;
int group0 = 0;

void input() {
    cin >> userInput;
}

void solution() {
    //초기 상태 설정
   int  flag = userInput[0] - '0';
   if (flag == 0) group0++;
   else group1++;

    for (int i = 0; i < userInput.size(); i++) {
        int n = userInput[i] - '0';
        if (n == 0 && flag == 1) { //지금 숫자는 0인데, 플래그값이 1이면 이전 숫자까지 1이었고 지금 0이 됐으므로 그룹이 바뀜
            group0++;
            flag = 0;
        }
        if (n == 1 && flag == 0) { //0->1
            group1++;
            flag = 1;
        }
    }

    if (group1 == 0 || group0 == 0) printf("0");
    else printf("%d", min(group1, group0)); //그룹 수가 적은게 곧 뒤집는 횟수임
}

int main() {
    input();
    solution();
}
