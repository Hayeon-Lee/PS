function solution(n, k) {
    var answer = 0;
    
    answer += 12000 * n;
    k -= parseInt(n/10);
    answer += 2000 * k;
    
    return answer;
}