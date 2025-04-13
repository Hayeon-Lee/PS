#include <string>
#include <vector>
#include <iostream>

using namespace std;

int get_one_cnt (int arg) {
    int n_zero = 0;
    string binary_str = "";
    
    while (arg > 0) {
        binary_str = to_string(arg & 1) + binary_str;
        arg >>= 1;
    }
    
    for (int i=0; i<binary_str.length(); i++) {
        if (binary_str[i] == '1') n_zero += 1;
    }
    
    return n_zero;
}

int solution(int n) {
    int answer = 0;
    
    int n_zero = get_one_cnt(n);
    
    while (true) {
        n += 1;
        int bigger_n = get_one_cnt(n);
        if (n_zero == bigger_n) break;
    }
    
    answer = n;
    return answer;
}