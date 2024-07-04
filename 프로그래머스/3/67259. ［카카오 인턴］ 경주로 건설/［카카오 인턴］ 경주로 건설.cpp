#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 999999
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int length = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1}; 

struct Pos {
    int x, y, cost, direction;
};

struct Compare {
    bool operator()(const Pos &a, const Pos &b) {
        return a.cost > b.cost;
    }
};

bool check(int nx, int ny, vector<vector<int>> board){
    if (nx < 0 || nx >= length || ny < 0 || ny >= length || board[nx][ny] == 1) return false;
    return true;
}

void initialize(int (&cost)[25][25][4]){
    for(int i=0; i<length; i++){
        for (int j=0; j<length; j++){
            for (int k=0; k<4; k++) {
                cost[i][j][k] = INF;
            }
        }
    }
    
    for (int i=0; i<4; i++) cost[0][0][i] = 0; //출발지의 방향을 초기화 
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    length = board.size();
    int cost[25][25][4];
    initialize(cost);
    
    priority_queue<Pos, vector<Pos>, Compare> pq;
    pq.push({0, 0, 0, -1}); //x, y, cost, direction
    
    while (!pq.empty()){
        Pos now = pq.top();
        pq.pop();
        
        for (int i=0; i<4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            int nd = i;
            int nc = now.cost;
            
            if (!check(nx, ny, board)) continue;
            
            nc += 100;
            if (now.direction == UP || now.direction == DOWN) {
                if (nd == LEFT || nd == RIGHT) nc += 500;
            }
            if (now.direction == LEFT || now.direction == RIGHT){
                if (nd == UP || nd == DOWN) nc += 500;
            }
            
            if (nc < cost[nx][ny][nd]) {
                cost[nx][ny][nd] = nc;
                pq.push({nx, ny, nc, nd});
            }
        }
    }
    
    answer = *min_element(cost[length-1][length-1], cost[length-1][length-1]+4);
    return answer;
}
