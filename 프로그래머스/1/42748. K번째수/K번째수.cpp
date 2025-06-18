#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    vector<int> answer;
    
    for (auto c: commands) {
        int i = c[0];
        int j = c[1];
        int k = c[2];
        
        vector<int> sub(array.begin()+(i-1), array.begin()+j);
        sort(sub.begin(), sub.end());
        answer.push_back(sub[k-1]);
    }
    
    return answer;
}