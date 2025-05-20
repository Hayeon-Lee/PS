function solution(n, m) {
    var answer = [];
    
    let bigger = -1;
    let smaller = -1;
    
    if (n >= m) {
        bigger = n;
        smaller = m;
    }
    else {
        bigger = m;
        smaller = n;
    }
    
    for (let i=smaller; i>=1; i--) {
        if (bigger % i == 0 && smaller % i == 0) {
            answer.push(i);
            break;
        }
    }
    
    let pivot = bigger;
    while (true) {
        if (pivot % smaller == 0 && pivot % bigger == 0) {
            answer.push(pivot);
            break;
        }
        pivot ++;
    }
    
    return answer;
}