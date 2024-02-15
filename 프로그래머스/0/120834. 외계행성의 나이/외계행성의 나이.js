function solution(age) {
    let str = 'abcdefghij';
    let ageArr = age.toString().split('');
    
    var answer = '';
    
    ageArr.forEach((value) => {
        answer += str[+value];
    })
    return answer;
}