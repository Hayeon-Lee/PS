#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

#define HEAD 0
#define NUMBER 1
#define TAIL 2

#define INTEGER 1
#define ALPHABET 2

int check(char c){
    if (c <= '9' && c >= '0') return INTEGER;
    else return ALPHABET;
}

typedef struct info {
    string head;
    int number;
    int index;
} Info;

bool compare (Info &a, Info &b){
    if (a.head == b.head) {
        if (a.number == b.number) return a.index < b.index;
        return a.number < b.number;
    }
    return a.head < b.head;
}


vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<Info> strip_infos;
    vector<vector<string>> strip_strings;
    
    for (int i=0; i<files.size(); i++){
        Info st;
        string now = files[i];
        
        int start_idx = 0;
        int end_idx = 0;
        int type = 0;
        int idx = 0;
        int number_cnt = 0;
        
        while(idx < now.length()){
            if (type == HEAD && check(now[idx]) == INTEGER) {
                end_idx = (idx - 1);
                string head = now.substr(start_idx, (end_idx - start_idx + 1));
                transform(head.begin(), head.end(), head.begin(), [](unsigned char c){return tolower(c);});
                st.head = head;
                
                start_idx = idx; //NUMBER 로 전환
                type = NUMBER;
                number_cnt ++;
                idx ++;
                
                if (idx == now.length()) { //숫자가 한글자밖에 없을 때
                    st.number = stoi(now.substr(start_idx, 1));
                    break;
                }
                continue;
            }
            
            if (type == NUMBER && check(now[idx]) == INTEGER) number_cnt++; 
            
            if (type == NUMBER && number_cnt == 5){ //숫자 입력받는 중인데 개수가 5개 
                string number = now.substr(start_idx, number_cnt);
                st.number = stoi(number);
                type = TAIL;
                number_cnt = 0;
                start_idx = idx + 1;
                idx++;
                continue;
            }
            
            if (type == NUMBER && (idx + 1) == now.length() && check(now[idx]) == INTEGER){ //숫자 입력받는 중인데 이미 문자열 끝 (tail이 없다)
                string number = now.substr(start_idx, number_cnt);
                st.number = stoi(number);
                type = TAIL;
                number_cnt = 0;
                break;
            }
            
            if (type == NUMBER && check(now[idx]) == ALPHABET) { //숫자 입력받는 중인데 더 이상 숫자가 아님
                string number = now.substr(start_idx, number_cnt);
                st.number = stoi(number);
                type = TAIL;
                number_cnt = 0;
                start_idx = idx;
                
                if (idx == now.length()-1) {
                    st.number = stoi(now.substr(idx));
                    break;
                }
            }
            
            if (type == TAIL) {
                string tail = now.substr(start_idx);
                break;
            }
            
            idx ++;
        }
        st.index = i;
        strip_infos.push_back(st);
    }

    sort(strip_infos.begin(), strip_infos.end(), compare);
    
    for (int i=0; i<strip_infos.size(); i++){
        cout << strip_infos[i].head << " " << strip_infos[i].number << " " << strip_infos[i].index << endl;
    }
    
    for (int i=0; i<strip_infos.size(); i++){
        answer.push_back(files[strip_infos[i].index]);
    }
    
    return answer;
}