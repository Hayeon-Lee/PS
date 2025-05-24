function solution(food) {
    var answer = '';
    
    for (let i=1; i<food.length; i++) {
        let repeat = ~~(food[i]/2);
        
        for (let j=0; j<repeat; j++) {
            answer += i.toString();
        }
    }
    
    answer += '0';
    
    for (let i=food.length-1; i>=1; i--) {
        let repeat = ~~(food[i]/2);
        for (let j=0; j<repeat; j++) {
            answer += i.toString();
        }
    }
    
    return answer;
}