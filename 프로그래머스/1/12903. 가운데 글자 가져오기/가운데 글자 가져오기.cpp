#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int length = s.length();
    string answer = "";
    
    if (length % 2 == 1) answer = s[length/2];
    else {
        answer += s[length/2-1];
        answer += s[length/2];
    }    
    return answer;
}