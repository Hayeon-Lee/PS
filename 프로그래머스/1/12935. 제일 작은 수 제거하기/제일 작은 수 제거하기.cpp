#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> temp_arr = arr;
    vector<int> answer;
    
    sort(temp_arr.rbegin(), temp_arr.rend());
    int small = temp_arr[temp_arr.size()-1];

    for(int i=0; i<arr.size(); i++) if (arr[i] != small) answer.push_back(arr[i]);
    if (answer.size() == 0) answer.push_back(-1);
    
    return answer;
}