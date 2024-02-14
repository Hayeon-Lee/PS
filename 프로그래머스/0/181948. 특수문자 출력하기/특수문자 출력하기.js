const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('close', function () {
    let answer = '!@#$%^&*(\\\'\"<>?:;';
    console.log(answer);
});