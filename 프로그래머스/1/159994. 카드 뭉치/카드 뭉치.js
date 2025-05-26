function solution(cards1, cards2, goal) {
    var answer = '';
    
    let length1 = cards1.length;
    let length2 = cards2.length;
    
    let index1 = 0;
    let index2 = 0;
    let targetIndex = 0;
    
    let flag = 0;
    
    while (targetIndex < goal.length) {
        let target = goal[targetIndex];
            
        if (index1 < length1 && cards1[index1] == target) {
            index1++;
            flag++;
        }
        else if (index2 < length2 && cards2[index2] == target) {
            index2++;
            flag++;
        }
        targetIndex++;
    }
    
    if (flag == goal.length) answer="Yes";
    else answer="No";
    
    return answer;
}