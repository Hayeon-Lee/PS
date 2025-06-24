#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    string input;
    cin >> input;

    int total = 0;
    int index = 0;

    for (int i = 0; i<input.length(); i++) {
        if (input[i] != '*') {
            if (i%2 == 0)
                total += input[i] - '0';
            if (i%2 == 1)
                total += 3 * (input[i] - '0');
        }
        else {
            index = i;
        }
    }

    int m = 0;
    for (int c = 0; c <= 9; c++) {
        int temp = total;

        if (index % 2 == 0) {
            temp += c;
        }
        else {
            temp += 3 * c;
        }

        if (temp % 10 == 0) {
            m = c;
            break;
        }
    }

    cout << m;
}