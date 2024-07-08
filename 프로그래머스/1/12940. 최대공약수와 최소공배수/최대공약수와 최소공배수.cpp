#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int r = 0;
    int tmp_n = n;
    int tmp_m = m;
    
    while (tmp_m != 0){
        r = tmp_n % tmp_m;
        tmp_n = tmp_m;
        tmp_m = r;
    }
    
    answer.push_back(tmp_n);
    answer.push_back(n*m/tmp_n);
    
    return answer;
}