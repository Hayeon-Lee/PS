const fs = require('fs')

let input = fs.readFileSync('dev/stdin').toString().split('\n')
const S = input[0].trim();
const T = input[1].trim();
var answer = 0

make_str(S, T);
console.log(answer);

function make_str(input_str, target_str) {
    while (target_str.length > 0) {
        if (target_str[(target_str.length)-1] == 'A') {
            target_str = target_str.slice(0, -1);
        }

        else if (target_str[(target_str.length)-1] == 'B') {
            target_str = target_str.slice(0,-1);
            target_str = target_str.split("").reverse().join("");
        }

        if (target_str == input_str) {
            answer = 1
            break
        }
    }
}