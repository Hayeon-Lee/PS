#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    long n;
    vector<long> arr;
    long shirt, pen;

    cin >> n;

    for (int i = 0; i < 6; i++) {
        int input = 0;
        cin >> input;
        arr.push_back(input);
    }

    cin >> shirt >> pen;

    long shirt_total = 0;
    for (int i = 0; i < 6; i++) {
        if (arr[i] == 0) {
            continue;
        }
        else {
            if (arr[i] % shirt == 0)
                shirt_total += arr[i] / shirt;
            else {
                shirt_total += ((arr[i] / shirt) + 1);
            }
        }
    }

    printf("%ld\n", shirt_total);
    printf("%ld %ld", n / pen, n % pen);
}