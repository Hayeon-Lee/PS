function solution(my_string, overwrite_string, s) {
    var answer = '';
    let string = my_string.split('');
    let ovstring = [...overwrite_string];
    
    let overwrite_length = ovstring.length;
    
    console.log(ovstring.length);
    for (let i = 0; i< overwrite_length; i++){
        string[s+i] = ovstring[i];
    }
    
    string.forEach(function(value) {
        answer += value;
    })
    
    return answer;
}