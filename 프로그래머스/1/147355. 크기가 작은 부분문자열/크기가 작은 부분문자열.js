function solution(t, p) {
    var answer = 0;
    
    let length = p.length;
    let parseArr = [];
    
    for (let i=0; i<=t.length-length; i++) {
        parseArr.push(t.substr(i, length));
    }
    
    parseArr.map((item, index) => {
        if (parseInt(item, 10) <= parseInt(p, 10)) {
            answer += 1;
        }
    })
    
    return answer;
}