function solution(num_list) {
    var answer = [];
    
    let even = 0;
    let odd = 0;
    
    num_list.forEach(function(value){
        if (value % 2 == 0) {
            even += 1;
        }
        else {
            odd += 1;
        }
    })
    
    answer.push(even, odd);
    return answer;
}