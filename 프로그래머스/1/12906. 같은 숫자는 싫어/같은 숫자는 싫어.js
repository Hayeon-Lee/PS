function solution(arr)
{
    var answer = [];

    let prior_value = -1;
    
    arr.map((item, index) => {
        if (prior_value == -1) {
            prior_value = item;
            answer.push(item);
        }
        else if (item != prior_value) {
            answer.push(item);
            prior_value = item;
        }
    })
    
    return answer;
}