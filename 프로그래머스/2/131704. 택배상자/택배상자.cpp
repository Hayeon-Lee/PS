#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int n = order.size();
    
    stack<int> s;
    int index = 0;
    for (int i=1; i<=n; i++){
        if (i<order[index]) s.push(i);
        else if (i==order[index]) index++;
        else if (!s.empty() && s.top() == i) {
            index += 1;
            s.pop();
        }
        else break;
        
        while (!s.empty() && s.top() == order[index]){
            index += 1;
            s.pop();
        }
    }
    
    return index;  
}