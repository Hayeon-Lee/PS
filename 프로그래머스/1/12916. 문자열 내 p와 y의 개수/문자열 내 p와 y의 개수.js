function solution(s){
    var answer = true;

    let p_n = 0;
    let y_n = 0;
    
    for (let i=0; i<s.length; i++) {
        if (s[i] == 'p' || s[i] == 'P') p_n+=1;
        if (s[i] == 'y' || s[i] =='Y') y_n+=1;
    }
    
    if (p_n == y_n) return true;
    else return false;
}