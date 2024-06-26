#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int allKind = 0;
    map<string, int> gKind;
    for(int i = 0; i < gems.size(); i++) {
        if(gKind.find(gems[i]) == gKind.end()) {
            gKind.insert(pair<string, int>(gems[i], allKind));
            allKind++;
        }
    }

    int cnt =0;
    int s = 0, e = 0, rs,  re, min = gems.size()+1, ce=0;
    map<string, int> exist;
    while(1) {
        if (gems.size() - s < allKind || e >= gems.size() || s > e) break;
        if(e != ce || e == 0) {
            if(exist.find(gems[e]) == exist.end()) { exist.insert(pair<string, int>(gems[e], 1)); }
            else { exist[gems[e]]++; }
        }
        ce = e;

        if(exist.size() == allKind){
            if(e-s < min) { rs=s;re=e;min=e-s; }
            if(exist[gems[s]] == 1) { exist.erase(gems[s]); }
            else { exist[gems[s]]--; }
            s++;
        }
        
        else { e++; } 
    }

    answer.push_back(rs+1);
    answer.push_back(re+1);
    return answer;
}