#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[9];
bool visited[9] = { false, };
queue<int> q;

void input() {
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    graph[2].push_back(1);
    graph[2].push_back(7);

    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);

    graph[6].push_back(7);

    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);
}

void bfs(int start) {
    visited[start] = true;
    
    while (!q.empty()) {
        int front = q.front();
        printf("%d ", front);
        q.pop();

        for (int i = 0; i < graph[front].size(); i++) {
            int next = graph[front][i];
            if (visited[next] == false) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
    input();
    q.push(1);
    bfs(1);
}
