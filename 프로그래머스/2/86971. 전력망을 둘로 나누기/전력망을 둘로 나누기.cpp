#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> graph[101];

int bfs(int start, int n){
    bool visited[101] = {false, };
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 1;
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        for(int next: graph[now]){
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    for (int i=0; i<wires.size(); i++) {
        for (int j=1; j<=n; j++) {
            graph[j].clear();
        }
        
        for (int j=0; j< wires.size(); j++) {
            if (i==j) continue;
            
            int v1 = wires[j][0];
            int v2 = wires[j][1];
            
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        
        int count = bfs(1, n);
        int diff = abs((n-count)-count);
        answer = min(answer, diff);
    }
    
    return answer;
}