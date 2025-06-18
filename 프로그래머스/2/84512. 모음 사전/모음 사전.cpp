#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    int weight[5] = {0,};
    
    int w = 1;
    weight[4] = 1;
    
    for (int i=3; i>=0; i--) {
        w = w * 5;
        weight[i] = w + weight[i+1];
    }
    
    string alpha = "AEIOU";
    
    for (int i=0; i<word.size(); i++) {
        int index = alpha.find(word[i]);
        answer += index * weight[i] + 1;
    }
    
    return answer;
}