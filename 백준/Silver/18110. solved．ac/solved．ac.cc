#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    float except_f = floor((n * 0.15) + 0.5);
    int except_i = (int)except_f;

    vector<int> arr;

    for (int i = 0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    if (arr.size() == 0) {
        printf("0");
        return 0;
    }

    sort(arr.begin(), arr.end());

    int real_total = 0;
    int real_cnt = 0;
    for (int i = except_i; i < (n - except_i); i++) {
        real_cnt++;
        real_total += arr[i];
    }

    float total = real_total / (float)real_cnt;
    int answer = floor(total + 0.5);

    cout << answer;
}