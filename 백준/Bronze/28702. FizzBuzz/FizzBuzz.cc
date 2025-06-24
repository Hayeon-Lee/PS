#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string input;
    vector<string> arr;

    for (int i = 0; i < 3; i++) {
        cin >> input;
        arr.push_back(input);
    }

    int index = 0;
    int number = 0;

    for (int i = 0; i < 3; i++) {
        if (arr[i].compare("Fizz")!=0 && arr[i].compare("Buzz")!=0 && arr[i].compare("FizzBuzz")!=0) {
            number = stoi(arr[i]);
            index = i;
            break;
        }
    }

    int last_number = (number + (3 - index));
    if (last_number % 3 == 0 && last_number % 5 == 0) {
        printf("FizzBuzz\n");
        return 0;
    }
    if (last_number % 3 == 0) {
        printf("Fizz");
        return 0;
    }
    if (last_number % 5 == 0) {
        printf("Buzz");
        return 0;
    }
    printf("%d", last_number);
}