const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = line.split(' ');
}).on('close', function () {
    let answer = input[0] + ' + ' + input[1] + ' = ';
    answer += (Number(input[0]) + Number(input[1])).toString();
    console.log(answer);
});