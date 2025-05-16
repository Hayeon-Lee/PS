function solution(n) {
    var answer = 0;
    
    let number = n-1;
    
    for (let i=2; i<=number; i++){
        if (number%i==0) {
            answer = i;
            break;
        }
    }
    
    return answer;
}