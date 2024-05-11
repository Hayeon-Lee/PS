#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int divide = 0;
    int tmp_x = x;
    
    bool answer = true;
    
    while(tmp_x > 0) {
        divide += tmp_x%10;
        tmp_x /= 10;
    }
    
    return x%divide == 0 ? true : false;
}