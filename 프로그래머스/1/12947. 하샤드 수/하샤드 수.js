function solution(x) {
    let sum = 0;
    let tmp_x = x;
    
    while (x > 0) {
        sum += x%10;
        x /= 10;
        x = ~~x;
    }
 
    if (tmp_x % sum == 0) return true;
    else return false;
    
}