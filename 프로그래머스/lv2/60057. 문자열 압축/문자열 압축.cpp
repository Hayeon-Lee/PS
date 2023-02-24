#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string s) {
    int mid = s.size()/2;
    int smallSize = s.size();
    
    for(int i=1; i<=mid; i++){ //자르는 문자열 개수 1개부터 N/2개까지
        string cutstr = "";
        int strCount = 1;
        string compareStr = s.substr(0,i);
        for(int j=i; j<s.size(); j+=i){//i만큼 잘라서 기준값 생성
            //기준으로 설정한 값과 지금 값이 같은지 확인
            if(compareStr==s.substr(j, i)) {
                //같은 문자열이면 갯수 세기
                strCount ++;
            }
            else{ 
                //다른 문자열이면 갯수+문자열로 바꾸고, 자를 위치 바꾸기
                if(strCount>1)cutstr+=to_string(strCount);
                strCount=1;
                cutstr += compareStr;
                compareStr=s.substr(j,i);
            }
        }
        if(strCount>1) cutstr+=to_string(strCount);
        cutstr+=compareStr;
        if(cutstr.size()<smallSize) smallSize = cutstr.size(); //작을 경우 바꾸기
    }
    
    return smallSize;
}