#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";

    int pn_length = phone_number.length();
    for(int i=0; i<pn_length-4; i++) answer += "*";
    for(int i=0; i<4; i++) answer += phone_number[pn_length-4+i];
    
    return answer;
}