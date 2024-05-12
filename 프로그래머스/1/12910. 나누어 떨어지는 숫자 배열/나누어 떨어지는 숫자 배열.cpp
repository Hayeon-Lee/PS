#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    vector<int>::iterator ptr;
    for(ptr=arr.begin(); ptr!=arr.end(); ptr++) {
        if (*ptr % divisor == 0) answer.push_back(*ptr);
    }
    
    if (answer.size()==0) {
        answer.push_back(-1);
        return answer;
    }
    else {
        sort(answer.begin(), answer.end());
        return answer;
    }
}