function solution(s, n) {
    let result = '';
    
    for (let i=0; i<s.length; i++) {
        let char = s[i];
        
        if (char === ' ') {
            result += ' ';
        }
        else if (char >= 'A' && char <= 'Z') {
            let code = (char.charCodeAt(0) - 'A'.charCodeAt(0) + n) % 26 + 'A'.charCodeAt(0);
            result += String.fromCharCode(code);
        }
        else if (char >= 'a' && char <= 'z') {
            let code = (char.charCodeAt(0) - 'a'.charCodeAt(0) + n) % 26 + 'a'.charCodeAt(0);
            result += String.fromCharCode(code);
        }
    }
    
    return result;
}