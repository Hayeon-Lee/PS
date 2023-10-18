function solution(s) {
    let arr = s.split(" ");
    let i = 0;
    for (i=0; i<arr.length; i++){
       arr[i] = Number(arr[i]); 
    }
    
    let answer = "";
    answer += Math.min(...arr).toString()
    answer += " "
    answer += Math.max(...arr).toString()
    
    return answer
}