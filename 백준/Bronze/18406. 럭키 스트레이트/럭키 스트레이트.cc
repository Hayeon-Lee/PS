#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string userInput;
int inputsize = 0, mid = 0, inputLeft = 0, inputRight = 0;

void input() {
    cin >> userInput;
    mid = (userInput.size() / 2);
    inputsize = userInput.size();
}

void solution() {
    for (int i = 0; i < mid; i++) inputLeft += (userInput[i] - '0');
    for(int i=mid; i<inputsize; i++) inputRight+= (userInput[i] - '0');
    
    if (inputLeft == inputRight) printf("LUCKY");
    else printf("READY");
}

int main() {
    input();
    solution();
}
