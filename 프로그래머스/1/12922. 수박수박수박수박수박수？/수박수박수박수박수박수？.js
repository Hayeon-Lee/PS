function solution(n) {
    
    var answer = '';
    
    if (n%2 == 0) {
        for (let i=0; i<n/2; i++) answer += "수박";
    }
    else {
        for (let i=0; i<~~(n/2); i++) answer += "수박";
        answer += "수";
    }
    
    return answer;
}