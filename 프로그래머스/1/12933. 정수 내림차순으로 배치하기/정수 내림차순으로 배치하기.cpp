#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    vector<int> n_arr;
    long long answer = 0;
    
    while (n > 0) {
        n_arr.push_back(n%10);
        n/=10;
    }
    sort(n_arr.rbegin(), n_arr.rend());
    
    string new_number = "";
    vector<int>::iterator ptr;
    for(ptr = n_arr.begin(); ptr != n_arr.end(); ptr ++) {
        new_number += to_string(*ptr);
    }
    
    return stoll(new_number);
}