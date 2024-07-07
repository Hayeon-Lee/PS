#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> infos;
    
    for (int i=0; i<record.size(); i++){
        
        //현재 사람의 아이디 구하기
        stringstream now(record[i]);
        string token;
        vector<string> strip_now;
        
        while(getline(now, token, ' ')) strip_now.push_back(token);
        
        if (strip_now[0] != "Leave") {
            infos[strip_now[1]] = strip_now[2];
            continue;
        }
    }
    
    for (int i=0; i<record.size(); i++){
        stringstream now(record[i]);
        string token;
        vector<string> strip_now;
        
        while(getline(now, token, ' ')) strip_now.push_back(token);
        
        string message;
        string name = infos[strip_now[1]];
        
        if (strip_now[0] == "Enter"){    
            message = (name + "님이 들어왔습니다.");
            answer.push_back(message);
            continue;
        }
        
        if (strip_now[0] == "Leave"){
            message = (name + "님이 나갔습니다.");
            answer.push_back(message);
            continue;
        }
    }
    
    return answer;
}