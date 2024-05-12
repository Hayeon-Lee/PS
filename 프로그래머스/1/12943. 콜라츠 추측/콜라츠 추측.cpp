#include <string>
#include <vector>

using namespace std;

int recurse(long long number, int cnt) {
    if (number == 1) return cnt;
    if (cnt >= 500) return -1;
    
    if (number % 2 == 0) return recurse(number/2, cnt+1);
    else return recurse(number*3+1, cnt+1);
}

int solution(int num) {
    int answer = recurse(num, 0);
    return answer;
}