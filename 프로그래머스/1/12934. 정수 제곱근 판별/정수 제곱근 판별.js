function solution(n) {
    
    let sqrt_n = Math.sqrt(n);
    
    if (Number.isInteger(sqrt_n) == true) {
        return ((sqrt_n+1)**2);
    }
    
    else return -1;
}