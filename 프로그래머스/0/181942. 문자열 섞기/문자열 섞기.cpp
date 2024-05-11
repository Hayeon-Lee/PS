#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    int flag = 1;
    int index = 0;
    
    while (index < str1.length()) {
        if (flag == 1) answer += str1[index];
        else answer += str2[index];
        
        flag *= -1;
        if (flag == 1) index += 1;
    }
    
    return answer;
}