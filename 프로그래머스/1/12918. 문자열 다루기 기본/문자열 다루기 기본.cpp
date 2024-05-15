#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int flag= 0;
    
    if (s.length() == 4 || s.length() == 6) {
        flag = 0;
        for(int i=0; i<s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z')  {
                flag = 1;
                break;
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                flag = 1;
                break;
            }
        }
    }
    else {
        answer = false;
        flag = 1;
    }
    
    if (flag == 1) answer = false;
    else answer = true;
    
    return answer;
}