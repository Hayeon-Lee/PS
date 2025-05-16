function solution(x, n) {
    var answer = [];
    let number = x;
    
    for (let i=0; i<n; i++){
        answer.push(number);
        number += x;
    }
    
    return answer;
}