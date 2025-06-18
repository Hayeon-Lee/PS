#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int max_width = 0;
    int max_height = 0;
    
    for (auto s: sizes) {
        int width = max(s[0], s[1]);
        int height = min(s[0], s[1]);
        
        if (max_width < width) max_width = width;
        if (max_height < height) max_height = height;
    }
    
    answer = max_width * max_height;
    
    return answer;
}