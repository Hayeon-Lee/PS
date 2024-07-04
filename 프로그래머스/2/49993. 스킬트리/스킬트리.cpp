#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    map<char, int> skillmap;
    
    for (int i=0; i<skill.length(); i++){
        skillmap[skill[i]] = i;
    }
    
    for (int i=0; i<skill_trees.size(); i++){
        string now_tree = skill_trees[i];
        int step = 0;
        int flag = 0;
        
        for(int j=0; j<now_tree.length(); j++){
            map<char, int>::iterator iter;
            iter = skillmap.find(now_tree[j]);
            
            if(iter == skillmap.end()) continue; //연마 단계에 포함되어있지 않은 스킬이면 건너뛴다
            else {
                char skillname = iter->first;
                int skillstep = iter->second;
                
                if (skillstep == step) {
                    step += 1;
                    continue;
                }
                else {
                    flag = 1;
                    break;
                }
            }
        }
        
        if (flag == 0) {
            answer += 1;
        }
    }
    
    return answer;
}