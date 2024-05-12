#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    
    string kim = "Kim";
    
    int index = 0;
    vector<string>::iterator ptr;
    for(ptr=seoul.begin(); ptr != seoul.end(); ptr++){
        if ((*ptr).compare(kim) == 0) break;
        index += 1;
    }
    
    string answer = "김서방은 " + to_string(index) + "에 있다";
    return answer;
}