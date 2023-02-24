#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string userInput;
string character;
int number = 0;

void input() {
    cin >> userInput;
}

void solution() {
    sort(userInput.begin(), userInput.end());
    for (int i = 0; i < userInput.size(); i++) {
        if (userInput[i] >= 'A' && userInput[i] <= 'Z') character.push_back(userInput[i]);
        else number += (userInput[i] - '0');
    }
    cout << character << number;
}

int main() {
    input();
    solution();
}
