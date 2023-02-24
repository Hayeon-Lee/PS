#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<double, int>a, pair<double,int>b){
    if (a.first==b.first) return a.second < b.second;
    else return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    int *persons = new int[N+1]; //스테이지에 있는 사람의 수
    for(int i=0; i<=N; i++) persons[i] =0;
    vector<pair<double,int>> failure; //실패율, 스테이지
    
    for(int i=0; i<stages.size(); i++){
        persons[stages[i]]++; //해당 스테이지의 사람 구하기 
    }
    
    int totalP = stages.size();
    for(int i=1; i<=N; i++){
        if(persons[i]==0) failure.push_back(make_pair(0,i));
        else{
            int notPass = persons[i]; //통과못한 사람의 수
            failure.push_back(make_pair(((double)notPass/(double)totalP), i));
        }
        totalP -= persons[i]; //이미 게산한 사람은 제외한다.
    }
    
    sort(failure.begin(), failure.end(), compare);
    for(int i=0;i<failure.size(); i++){
        answer.push_back(failure[i].second);
    }
    
    return answer;
}
