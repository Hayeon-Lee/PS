function solution(a, b, n) {
    var answer = 0;
    
    while (n >= a) {
        let exchange = (~~(n/a)) * b;
        answer += exchange;
        n = (n % a) + exchange;
    }
    
    return answer;
}