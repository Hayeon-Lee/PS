function solution(strlist) {
    var answer = [];
    
    strlist.forEach(function(value){
        answer.push(value.length);
    })
    
    return answer;
}