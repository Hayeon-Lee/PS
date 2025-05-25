function solution(k, score) {
    var answer = [];
    
    for (let i=0; i<score.length; i++) {
        let subarr = score.slice(0, i+1);
        subarr.sort((a,b)=>b-a);
        if (subarr.length < k) {
            answer.push(subarr[subarr.length-1]);
        }
        else {
            answer.push(subarr[k-1]);
        }
    }
    
    
    return answer;
}