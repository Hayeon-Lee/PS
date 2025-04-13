#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i=1; i<=n; i++){
        int number = i;
        int sum = 0;
        
        while (sum <= n) {            
            sum += number;
            number += 1;
            
            if (sum == n) {
                answer += 1;
                break;
            }
        }
    }
    
    return answer;
}