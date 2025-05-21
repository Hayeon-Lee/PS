function solution(s) {
    var answer = '';
    
    let arr = s.split(' ');

    arr.map((item, index) => {
        let sub_arr = item;
        
        for (let i=0; i<item.length; i++) {
            if (i%2==0) answer += sub_arr[i].toUpperCase();
            else answer += sub_arr[i].toLowerCase();
        }
        if (index != arr.length -1) answer += ' ';
    });
    
    return answer;
}