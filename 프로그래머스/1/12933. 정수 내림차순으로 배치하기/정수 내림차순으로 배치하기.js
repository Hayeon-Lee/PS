function solution(n) {
    var answer = 0;
    let number_arr = [];
 
    while (n > 0) {
        number_arr.push(n%10);
        n/=10;
        n=~~n;
    }
  
    number_arr = number_arr.sort((a,b)=>b-a);
    
    for (let i=0; i<number_arr.length; i++){
        answer += number_arr[i];
        if (i!=number_arr.length-1) answer *= 10;
    }
    
    return answer;
}