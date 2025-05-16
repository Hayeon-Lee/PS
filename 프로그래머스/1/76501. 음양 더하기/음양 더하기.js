function solution(absolutes, signs) {
    var answer = 0;
    
    for (let i=0; i<absolutes.length; i++) {
        let real_num = absolutes[i];
        if (signs[i] == true) answer += real_num;
        else answer += (real_num * -1);
    }
     
    return answer;
}