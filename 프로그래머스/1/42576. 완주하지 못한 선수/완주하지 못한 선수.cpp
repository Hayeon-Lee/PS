#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    
    for (auto p: participant) {
        m[p] ++;
    }
    
    for (auto c: completion) {
        m[c] --;
    }
    
    for (auto it: m) {
        if (it.second > 0) return it.first;
    }
    
    return "";
}