#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    if (n == 2) return 1;
    if (n == 3) return 2;
    
    int num1 = 1;
    int num2 = 2;
    int current_n = 3;
    
    for (int i=4; i<=n; i++){
        current_n = (num1 + num2) % 1234567;
        num1 = num2;
        num2 = current_n;
    }
    
    int answer = current_n % 1234567;
    return answer;
}