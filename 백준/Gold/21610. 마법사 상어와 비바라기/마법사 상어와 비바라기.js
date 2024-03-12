const fs = require('fs')

let input = fs.readFileSync('dev/stdin').toString().trim().split('\n');

const nm_array= input[0].trim().split(' ');
const n = Number(nm_array[0]);
const m = Number(nm_array[1]);

let board = Array();
for (let i=1; i<=n; i++) {
    let tmp_array = input[i].trim().split(' ');
    for (let j=0; j<n; j++){
        tmp_array[j] = Number(tmp_array[j]);
    }
    board.push(tmp_array);
}

const moving = Array();
for (let i=(1+n); i<(1+n+m); i++) {
    let tmp_array = input[i].trim().split(' ');
    for (let j=0; j<2; j++){
        tmp_array[j] = Number(tmp_array[j]);
    }
    moving.push(tmp_array);
}

// 문제에 필요한 전역 변수
const direction_x = [0, -1, -1, -1, 0, 1, 1, 1]
const direction_y = [-1, -1, 0, 1, 1, 1, 0, -1]

let cloud = [[n-1, 0], [n-1, 1], [n-2, 0], [n-2, 1]]
let cant_cloud = []

function cloud_moving(d, s) {
    const dx = direction_x[d-1];
    const dy = direction_y[d-1];
    let bug_cloud = Array();

    for (let j = 0; j<cloud.length; j++){
        let nx = cloud[j][0];
        let ny = cloud[j][1];

        // 구름 이동
        nx = (nx + (dx*s)) % n;
        ny = (ny + (dy*s)) % n;

        nx = nx < 0 ? nx + n : nx;
        ny = ny < 0 ? ny + n : ny;

        // 버그가 발생하는 구름 생성
        bug_cloud.push([nx, ny]);
    }

    return bug_cloud;
}

function raining(bug_cloud) {
    // 구름을 만들 수 없는 배열 초기화
    cant_cloud = [];

    for(let j = 0; j<n; j++){
        let tmp_array = Array();
        for(let k = 0; k<n; k++) {
            tmp_array.push(false);
        }
        cant_cloud.push(tmp_array);
    }

    for(let j=0; j<bug_cloud.length; j++){
        const x = bug_cloud[j][0];
        const y = bug_cloud[j][1];

        board[x][y]+=1; //비가 내린다
        cant_cloud[x][y] = true; //구름이 사라진 칸은 구름이 생길 수 없다
    }
}

function copy_bug(bug_cloud) {
    const bug_direction_x = [-1, -1, 1, 1]
    const bug_direction_y = [-1, 1, 1, -1]

    for (let j=0; j<bug_cloud.length; j++) {
        const x = bug_cloud[j][0];
        const y = bug_cloud[j][1];
        let cnt = 0;

        //대각선 방향으로 거리가 1인 바구니에 물이 있는지 확인한다
        for(let k=0; k<4; k++) {
            let nx = x + bug_direction_x[k];
            let ny = y + bug_direction_y[k];
            
            if (0<=nx && nx<n && 0<=ny && ny<n) {
                if (board[nx][ny]>0) {
                    cnt += 1;
                }
            }
        }
        board[x][y] += cnt;
    }
}

function make_new_cloud() {
    cloud = [];

    for(let j=0; j<n; j++) {
        for(let k=0; k<n; k++) {
            if(board[j][k] >= 2 && cant_cloud[j][k]==false) {
                cloud.push([j,k]);
                board[j][k] -= 2;
            }
        }
    }
}

for (let i=0; i<m; i++) {
    let d = moving[i][0];
    let s = moving[i][1];

    let bug_cloud = cloud_moving(d,s);
    raining(bug_cloud);
    copy_bug(bug_cloud);
    make_new_cloud();
}

let answer = 0;
for (let i=0; i<n; i++) {
    for (let j=0; j<n; j++) {
        answer += board[i][j];
    }
}

console.log(answer);