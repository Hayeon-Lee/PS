#include <string>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

int dx[4] = {1, -1, 0, 0}; //U, D, R, L
int dy[4] = {0, 0, 1, -1}; //U, D, R, L
map<char, int> direction = {
    {'U', 0},
    {'D', 1},
    {'R', 2},
    {'L', 3}
};

bool check(int x, int y){
    if (x < -5 || x > 5 || y < -5 || y > 5) return false;
    return true;
}

int solution(string dirs) {
    map<pair<int, int>, vector<pair<int, int>>> visited;
    int answer = 0;
    
    int x = 0;
    int y = 0;
    
    for (int i=0; i<dirs.length(); i++){
        char now = dirs[i];
        int nx = x + dx[direction[now]];
        int ny = y + dy[direction[now]];
        int flag = 0;
        
        if (!check(nx, ny)) continue; //범위를 벗어나면 넘어간다
        
        //역방향 검사
        map<pair<int, int>, vector<pair<int, int>>>::iterator iter;
        iter = visited.find(make_pair(nx, ny)); 
        
        if (iter != visited.end()) { // 타겟 위치가 시작점으로도 쓰였다면 지금 위치를 방문해봤는지 확인한다
            vector<pair<int, int>> reverse_v = iter -> second;
            for (int j=0; j<reverse_v.size(); j++) {
                if(reverse_v[j].first == x && reverse_v[j].second == y) {
                    flag = 1; //역방향이 존재한다
                    break;
                }
            }
        }
        
        //역방향이 없다면
        if (flag == 0) {
            //이 위치가 시작점으로도 존재하지 않는다면 추가한다.
            iter = visited.find(make_pair(x, y));
            if (iter == visited.end()) {
                visited[make_pair(x, y)] = vector<pair<int, int>> ();
                visited[make_pair(x, y)].push_back(make_pair(nx, ny));
                answer += 1;
                
            }
            //이 위치가 시작점으로 존재했다면 가본 곳인지 확인한다.
            else {
                vector<pair<int, int>> v = iter -> second;
                int flag2 = 0;
                for (int j=0; j<v.size(); j++) {
                    if (v[j].first == nx && v[j].second == ny) {
                        flag2 = 1; //처음 가본 곳이 아니다
                        break;
                    }
                }
                if (flag2 == 0) { //처음 가본 곳이다
                    visited[make_pair(x, y)].push_back(make_pair(nx, ny));
                    answer += 1;
                }
            }
        }
        
        x = nx;
        y = ny;
    }
    
    return answer;
}

/*
역방향을 먼저 검사
*/