#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n>s) {
        answer.push_back(-1);
        return answer;
    }
    else {
        int counts = s/n;
        int m = s%n;

        int numbers[n];
        for (int i=0; i<n; i++) numbers[i] = counts;
        for (int i=0; i<m; i++) numbers[i] += 1;
        for (int i=0; i<n; i++) answer.push_back(numbers[i]);
        sort(answer.begin(), answer.end());
    
        return answer;
    }
}