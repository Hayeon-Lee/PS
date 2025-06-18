#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s(nums.begin(), nums.end());
    int max_take = nums.size() / 2;
    
    return min((int)s.size(), max_take);
}