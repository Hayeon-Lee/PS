#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    
    string answer = "";
    int index = 0;
    int space_flag = 1;
    
    for(int i=0; i<s.length(); i++) {        
        if (s[i] == ' ') {
            space_flag = 1;
            index = 0;
            answer += ' ';
            continue;
        }
        
        if (space_flag == 1 && s[i] != ' ') {
            space_flag = 0;
            
            if (index == 0) {
                if (s[i] >= '0' && s[i] <= '9') answer += s[i];
                else if (s[i] >= 'a' && s[i] <= 'z') answer += ('A' + s[i] - 'a');
                else answer += s[i];
                
                index ++;
            }
            continue;
        }
        
        if (index > 0) {
            if (s[i] >= 'A' && s[i] <= 'Z') answer += ('a' + s[i] - 'A');
            else answer += s[i];
            index ++;
            continue;
        }
    }
    
    return answer;
}