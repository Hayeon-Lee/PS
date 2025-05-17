function solution(seoul) {
    var answer = '';
    let loaction = -1;
    
    seoul.map((item, index) => {
        if (item == "Kim") location = index;
    })
    
    answer = "김서방은 " + location.toString() + "에 있다";
    
    return answer;
}