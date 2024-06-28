#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b){
    return a.second > b.second;
}

void find(int target, map<int, int> &myMap){
    for (int i=2; i<=target; i++){
        if(target%i==0) {
            if(myMap.find(i) == myMap.end()) myMap[i] = 1;
            else myMap[i] += 1;
        }
    }
    return;
}

int main(int argc, char** argv)
{
    int n;
    map<int, int> myMap;

    scanf("%d", &n);
    for (int i=0; i<n; i++){
        int tmp;
        scanf("%d", &tmp);
        find(tmp, myMap);
    }

    vector<pair<int, int>> vec(myMap.begin(), myMap.end());
    sort(vec.begin(), vec.end(), compare);

    printf("%d", vec[0].second);
    return 0;
}
