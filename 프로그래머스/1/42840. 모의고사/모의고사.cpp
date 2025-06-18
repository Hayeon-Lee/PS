#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    vector<int> supoja1 = {1, 2, 3, 4, 5};
    vector<int> supoja2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> supoja3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int supo1_ans = 0;
    int supo2_ans = 0;
    int supo3_ans = 0;
    
    for (int i=0; i<answers.size(); i++) {
        if (answers[i] == supoja1[i % supoja1.size()]) supo1_ans++;
        if (answers[i] == supoja2[i % supoja2.size()]) supo2_ans++;
        if (answers[i] == supoja3[i % supoja3.size()]) supo3_ans++;
    }
    
    int max = (supo1_ans > supo2_ans) ? ((supo1_ans > supo3_ans) ? supo1_ans : supo3_ans) : ((supo2_ans > supo3_ans) ? supo2_ans:supo3_ans);
    
    vector<int> answer;
        
    if (supo1_ans == max) answer.push_back(1);
    if (supo2_ans == max) answer.push_back(2);
    if (supo3_ans == max) answer.push_back(3);
        
    return answer;
}