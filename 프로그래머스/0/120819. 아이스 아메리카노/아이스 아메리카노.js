function solution(money) {
    var answer = [];
    
    let canbuy = parseInt(money/5500);
    let change = money - (canbuy * 5500);
    
    answer.push(canbuy, change);
    
    return answer;
}