#include <string>
#include <vector>
#include <algorithm>
#include <cstring> 

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    
    vector<pair<int, string>> cache(cacheSize);
    
    int answer = 0;
    int time = 0;
    int cacheFullCnt = 0;
    
    if (cacheSize == 0) return (5*cities.size());
    
    vector<string>::iterator ptr;
    for (ptr = cities.begin(); ptr != cities.end(); ptr ++) {
        time ++;
        int flag = 0;
        for (int i=0; i<cacheFullCnt; i++) {
            //cache hit (1)
            if(strcasecmp((*ptr).c_str(), cache[i].second.c_str()) == 0) {
                answer += 1;
                cache[i].first = time;
                flag = 1;
            }
        }
        //cache miss (5)
        if (flag == 0) {
            answer += 5;
            //캐시가 다 차지 않았을 경우 -> 캐시에 페이지를 추가한다
            if (cacheFullCnt < cacheSize) {
                cache[cacheFullCnt] = make_pair(time, *ptr);
                cacheFullCnt += 1;    
            }
            //캐시가 다 찼을 경우 -> 가장 오랫동안 안 쓴 페이지를 지운다
            else {
                auto minElement = min_element (
                    cache.begin(), cache.end(), 
                    [](pair<int, string> &a, pair<int, string>&b) { return a.first < b.first; });
                auto position = distance(cache.begin(), minElement);
                
                minElement->first = time;
                minElement->second = *ptr;
            }
        }
    }
    
    return answer;
}
                                 