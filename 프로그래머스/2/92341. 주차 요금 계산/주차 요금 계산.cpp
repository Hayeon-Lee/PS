#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    int original_time = fees[0];
    int original_fee = fees[1];
    int unit_time = fees[2];
    int unit_fee = fees[3];
    
    map<string, vector<string>> in_car_times;
    map<string, vector<string>> out_car_times;
    
    //문자열 처리
    for (int i=0; i<records.size(); i++){
        string now = records[i];
        
        istringstream str(now);
        vector<string> tokens;
        string token;
        
        while(getline(str, token, ' ')) tokens.push_back(token);
        
        if(tokens[2] == "IN") {
            map<string, vector<string>>::iterator iter;
            iter = in_car_times.find(tokens[1]);
            
            if (iter == in_car_times.end()) {
                in_car_times[tokens[1]] = vector<string>();
                in_car_times[tokens[1]].push_back(tokens[0]);
            }
            else in_car_times[tokens[1]].push_back(tokens[0]);
        }
        
        else {
            map<string, vector<string>>::iterator iter;
            iter = out_car_times.find(tokens[1]);
            
            if (iter == out_car_times.end()) {
                out_car_times[tokens[1]] = vector<string>();
                out_car_times[tokens[1]].push_back(tokens[0]);
            }
            else out_car_times[tokens[1]].push_back(tokens[0]);
        }
    }
    
    //출차 시간 없는 애들 추가해주기
    for (const auto &pair: in_car_times){
        map<string, vector<string>>::iterator iter;
        iter = out_car_times.find(pair.first);
        
        if (iter == out_car_times.end()) {
            out_car_times[pair.first] = vector<string>();
            out_car_times[pair.first].push_back("23:59");
            continue;
        }
        
        if (out_car_times[pair.first].size() != pair.second.size()) out_car_times[pair.first].push_back("23:59");
    }
    
    //시간 계산하기
    for (const auto &pair: in_car_times){ //차 번호 별로
        int cost = 0;
        int acc_time = 0;
        
        for(int i=0; i<in_car_times[pair.first].size(); i++){ //입출차 세트별로
            int in_minute = 0;
            int out_minute = 0;
            
            string intime_str = in_car_times[pair.first][i];
            vector<int> intime_v;
            string outtime_str = out_car_times[pair.first][i];
            vector<int> outtime_v;
            
            istringstream is(intime_str);
            istringstream os(outtime_str);
            string t;
            while(getline(is, t, ':')) intime_v.push_back(stoi(t));
            while(getline(os, t, ':')) outtime_v.push_back(stoi(t));
            
            in_minute = (intime_v[0]*60) + intime_v[1];
            out_minute = (outtime_v[0]*60) + outtime_v[1];
            
            int sub = out_minute - in_minute;
            acc_time += sub;
        }
        
        if (acc_time <= original_time) cost += original_fee;
        else {
            cost += original_fee;
            
            int rest = (acc_time - original_time);
            if (rest % unit_time == 0) {
                cost += ((rest / unit_time) * unit_fee);
            }
            else {
                cost += (((rest / unit_time) + 1) * unit_fee);
            }
        }
        
        answer.push_back(cost);
    }
    return answer;
}