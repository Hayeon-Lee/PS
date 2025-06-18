#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> m;
    
    for (auto cv: clothes) {
        m[cv[1]]++;
    }
    
    int answer = 1;
    for (auto it: m) {
        answer *= (it.second + 1);
    }
    
    return answer - 1;
}