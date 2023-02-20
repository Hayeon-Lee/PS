#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

vector<int> graph[9];
bool visited[9] = { false, };
stack<int> stacks;

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

void dfs_stack(int start) {
    int current = start;
    stacks.push(current);
    visited[current] = true;
    printf("%d ", current);

    for (int i = 0; i < graph[current].size(); i++) {
        int next = graph[current][i];
        if (visited[next] == false) {
            stacks.push(next);
            visited[next] = true;
            dfs_stack(next);
        }
    }
    stacks.pop();
}

void dfs_recursive(int start) {
    int current = start;
    visited[current] = true; 
    printf("%d ", current);

    for (int i = 0; i < graph[current].size(); i++) {
        int next = graph[current][i];
        if (visited[next] == false) dfs_recursive(next);
    }
}

int main() {
    input();

    printf("스택 이용:");
    dfs_stack(1);

    printf("\n재귀함수 이용:");
    memset(visited, 0, sizeof(visited));
    dfs_recursive(1);
}
