function solution(n) {
    var answer = 0;
    
    let str_3 = n.toString(3);
    str_3 = str_3.split('').reverse().join('');
    answer = parseInt(str_3, 3);
    
    return answer;
}