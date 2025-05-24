function solution(s) {
    
    let dictionary = {
        'zero': 0,
        'one': 1,
        'two': 2,
        'three': 3,
        'four': 4,
        'five': 5,
        'six': 6,
        'seven': 7,
        'eight': 8,
        'nine': 9,
    }
    
    var answer = 0;
    
    let start = 0;
    let end = 0;
    
    for (let i=0; i<s.length; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            answer = answer * 10 + parseInt(s[i]);
            start = i + 1;
        }
        else {
            end = i + 1;
            let word = s.slice(start, end);
            if (word in dictionary) {
                answer = answer * 10 + dictionary[word];
                start = i + 1;
            }
        }
    }
    
    return answer;
}