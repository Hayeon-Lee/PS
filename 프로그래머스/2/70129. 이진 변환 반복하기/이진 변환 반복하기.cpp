#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int repeat_cnt=0;
    int zero_cnt = 0;
    
    while (true) {
        if (s.length() == 1) {
            answer.push_back(repeat_cnt);
            answer.push_back(zero_cnt);
            break;
        }
        
        vector<char> str;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '0') zero_cnt += 1;
            else str.push_back(s[i]);
        }
        
        int new_str_len = str.size();
        string tmp_str = "";
        while (new_str_len > 0) {
            tmp_str = to_string(new_str_len & 1) + tmp_str;
            new_str_len >>= 1;
        }
        
        s = tmp_str;
        repeat_cnt += 1;
    }
    
    return answer;
}

/*
문자열 벡터에 0을 제거한 1로 만들어진 숫자를 넣음
벡터의 길이를 이진수로 변환함
*/