#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

set<int> s;
vector<bool> visited;

bool is_prime(int n){
    if (n <= 1) return false;
    for (int i=2; i<=sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}

void dfs(string numbers, string current) {
    if (!current.empty()){
        s.insert(stoi(current));
    }
    
    for (int i=0; i<numbers.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(numbers, current+numbers[i]);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    visited = vector<bool>(numbers.size(), false);
    
    dfs(numbers, "");
    
    int answer = 0;
    for (auto num: s) {
        if (is_prime(num)) answer++;
    }
    
    return answer;
}