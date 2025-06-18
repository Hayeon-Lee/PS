#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[8] = {false,};
int maxCount = 0;

void dfs(int k, vector<vector<int>> dungeons, int count) {
    maxCount = max(maxCount, count);
    
    for (int i=0; i<dungeons.size(); i++) {
        if (!visited[i] && k >= dungeons[i][0]){
            visited[i] = true;
            dfs(k-dungeons[i][1], dungeons, count + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k, dungeons, 0);
    return maxCount;
}