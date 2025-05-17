function solution(phone_number) {
    var answer = '';
    let count = 0;
    
    for(let i=phone_number.length -1 ; i>=0; i--) {
        if (count >= 4) answer = '*' + answer;
        else answer = phone_number[i] + answer;
        count += 1;
    }
    
    return answer;
}