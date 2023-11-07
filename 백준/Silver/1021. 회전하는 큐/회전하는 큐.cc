#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N = 0, M = 0;
    scanf("%d %d", &N, &M);

    deque<int> numbers;
    for (int i = 1; i <= N; i++) numbers.push_back(i);

    deque<int> target_queue;
    for (int i = 0; i < M; i++) {
        int tmp;
        scanf("%d", &tmp);
        target_queue.push_back(tmp);
    }

    deque<int>::iterator iter;
    int head = 0, tail = numbers.size()-1, target_index = -1, answer = 0;

    while (target_queue.size() != 0) {
        int target = target_queue.front();
        target_queue.pop_front();

        if (target == numbers.front()) {
            numbers.pop_front();
            tail = numbers.size() - 1;
            continue;
        }

        for (iter = numbers.begin(); iter != numbers.end(); iter++) {
            target_index += 1;
            if (*iter == target) break;
        }

        int left = target_index - head;
        int right = tail - target_index;

        if (left <= right) {
            while (numbers.front() != target) {
                int tmp = numbers.front();
                numbers.pop_front();
                numbers.push_back(tmp);
                answer += 1;
            }
        }

        else {
            while (numbers.front() != target) {
                int tmp = numbers.back();
                numbers.pop_back();
                numbers.push_front(tmp);
                answer += 1;
            }
        }

        numbers.pop_front();
        tail = numbers.size() - 1;
        target_index = -1;
    }

    printf("%d", answer);
}