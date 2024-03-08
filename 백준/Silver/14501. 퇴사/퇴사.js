const fs = require('fs')

let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')
const n = parseInt(input[0].trim());
const counseling = [];

let i = 0;
let j = 0;

for (i=1; i<input.length; i++) {
    let tmp = input[i].split(' ');
    for (j=0; j<2; j++){
        tmp[j] = parseInt(tmp[j].trim());
    }
    counseling.push(tmp);
}

let dp = [];
for (i=0; i<n+1; i++){
    dp.push(0);
}

for (i=0; i<n; i++){
    for (j=i+counseling[i][0]; j<n+1; j++){
        if (dp[j] < dp[i] + counseling[i][1]){
            dp[j] = dp[i] + counseling[i][1]
        }
    }
}

console.log(dp[n]);