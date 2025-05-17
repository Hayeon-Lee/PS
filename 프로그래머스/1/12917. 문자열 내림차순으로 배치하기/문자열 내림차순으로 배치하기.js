function solution(s) {
    var answer = '';
    
    let sorted_arr = s.split('').sort().reverse();
    sorted_arr.map((item, index) => {
        answer += item;
    })
    
    return answer;
}