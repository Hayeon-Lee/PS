function solution(numbers) {
    var answer = 0;
    
    let arr = new Array(10).fill(false);
    
    numbers.map((item, index) => {
        arr[item] = true;
    })
 
    for (let i=0; i<arr.length; i++){
        if (arr[i] == false) answer += i;
    }
    
    return answer;
}