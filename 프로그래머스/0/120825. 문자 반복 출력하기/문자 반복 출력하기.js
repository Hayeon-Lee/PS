function solution(my_string, n) {
    var answer = '';
    
    my_string.split("").forEach(function(value) {
        let tmp = value.repeat(n);
        answer += tmp;
    })
    
    return answer;
}