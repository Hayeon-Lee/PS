#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    vector<int>::iterator ptr;
    for (ptr = array.begin(); ptr != array.end(); ptr++) {
        if (*ptr == n) answer += 1;
    }
    return answer;
}