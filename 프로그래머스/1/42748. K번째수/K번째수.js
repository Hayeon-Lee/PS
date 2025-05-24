function solution(array, commands) {
    var answer = [];
    
    commands.map((item, index) => {
        let start = item[0];
        let last = item[1];
        let target = item[2];
        
        let subArr = array.slice(start-1, last);
        subArr.sort((a,b)=>a-b);
        answer.push(subArr[target-1]);
    })
    
    return answer;
}