function solution(n) {
    
    if(n==1) {
        return '수';
    }
    if(n==2) {
        return '수박';
    }
    
    const repeat = parseInt(n/2);
    let answer = ''
    
    for (let i=0; i<repeat; i++) {
        answer += '수박';
    }
    
    if (n%2==0) return answer;
    else return answer+'수';
    
    
}