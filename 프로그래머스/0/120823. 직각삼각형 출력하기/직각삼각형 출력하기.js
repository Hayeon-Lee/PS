const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = line.split(' ');
}).on('close', function () {
    length = input[0];
    for(let i = 1; i<= length; i++) {
        let string = '*'.repeat(i);
        console.log(string);
    }
});