#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> items;
    
    for(int i=0; i<s.length(); i++) {
        if (s[i] == '(') items.push(s[i]);
        if (s[i] == ')') {
            if (!items.empty()) {
                items.pop();
            }
            else {
                answer = false;
                break;
            }
        }
    }
    
    if (!items.empty()) answer = false; 
    
    return answer;
}