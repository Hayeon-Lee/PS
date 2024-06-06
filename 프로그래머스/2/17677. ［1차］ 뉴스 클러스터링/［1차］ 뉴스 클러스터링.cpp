#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

vector<string> strip_str(string str) {
    vector<string> str_v;
    
    for (int i=0; i<str.length()-1; i++) {
        string tmp = str.substr(i, 2);
        
        int flag = 0;
        for (int j=0; j<tmp.length(); j++) {
            if (!isalpha(tmp[j])) {
                flag = 1;
                break;
            } 
            else tmp[j] = tolower(tmp[j]);
        }
        if (flag == 0) str_v.push_back(tmp);
    }
    
    return str_v;
}


int solution(string str1, string str2) {
    vector<string> str1_v = strip_str(str1);
    vector<string> str2_v = strip_str(str2);
    
    if (str1_v.empty() && str2_v.empty()) return 65536;
    
    int max = str1_v.size() + str2_v.size();
    int min = 0;
    
    if (str1_v.size() > str2_v.size()) {
        for (int i=0; i<str2_v.size(); i++) {
            auto itr = find(str1_v.begin(), str1_v.end(), str2_v[i]);
            if (itr != str1_v.end()) {
                min ++;
                str1_v.erase(itr);
            }
        }
    }
    
    else {
        for (int i=0; i<str1_v.size(); i++) {
            auto itr = find(str2_v.begin(), str2_v.end(), str1_v[i]);
            if (itr != str2_v.end()) {
                min ++;
                str2_v.erase(itr);
            }
        }
    }

    max -= min;
    if (max == 0) return 65536;
    double answer = (double)min / (double)max;
    
    cout  << max << " " << min <<  " " <<endl;
    
    return answer*65536;
}