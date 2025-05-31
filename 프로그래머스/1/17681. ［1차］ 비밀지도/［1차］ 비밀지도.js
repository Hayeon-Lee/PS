function solution(n, arr1, arr2) {
    var answer = [];
    
    for (let i=0; i<n; i++) {
        let arr1Str = arr1[i].toString(2);
        arr1Str = ("0".repeat(n-arr1Str.length)) + arr1Str;
        
        let arr2Str = arr2[i].toString(2);
        arr2Str = ("0".repeat(n-arr2Str.length)) + arr2Str;
        
        let answerStr = "";
        
        for (let j=0; j<n; j++) {
            if (arr1Str[j] == '0' && arr2Str[j] == '0') answerStr += " ";
            else answerStr += "#";
        }
        
        answer.push(answerStr);
    }
    
    return answer;
}