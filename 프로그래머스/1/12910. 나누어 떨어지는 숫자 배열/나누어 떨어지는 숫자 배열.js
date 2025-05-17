function solution(arr, divisor) {
    var answer = [];
    
    arr.map((item, index) => {
        if (item % divisor == 0) answer.push(item);
    })
    
    answer = answer.sort((a, b) => a-b);
    if (answer.length == 0) answer.push(-1);
    
    return answer;
}