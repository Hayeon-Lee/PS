function charToIndex(char) {
    return char.charCodeAt(0) - 'a'.charCodeAt(0);
}

function solution(s) {
    var answer = [];
    
    let englishArr = new Array(26).fill(-1);
    
    for (let i=0; i<s.length; i++) {
        let index = charToIndex(s[i])
        if (englishArr[index] == -1) {
            answer.push(-1);
            englishArr[index] = i;
        }
        else {
            answer.push(i-englishArr[index]);
            englishArr[index] = i;
        }
    }
    
    
    return answer;
}