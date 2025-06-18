#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int h=3; h<=yellow+2; h++) {
        if (yellow % (h-2) == 0) {
            int w = yellow / (h-2) + 2;
            if (brown == (w*h - yellow)) return {w, h};
        }
    }
       
    return {};
}