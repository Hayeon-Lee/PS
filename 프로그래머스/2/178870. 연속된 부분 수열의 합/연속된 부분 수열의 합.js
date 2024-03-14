function solution(sequence, k) {
    var answer = [];
    
    let answer_start = 0;
    let answer_end = sequence.length;
    let tmp_sum = 0;
    
    let tmp_start = 0;
    let tmp_end = 0;
    
    for (let i=0; i<sequence.length; i++) {
        tmp_start = i;
        
        while (tmp_sum < k && tmp_end < sequence.length){
            tmp_sum += sequence[tmp_end];
            tmp_end += 1;
        }
        if (tmp_sum == k) {
            if (Math.abs(answer_start-answer_end) > Math.abs(tmp_start-(tmp_end-1))) {
                answer_start = tmp_start;
                answer_end = tmp_end-1;
            }
        }
        tmp_sum -= sequence[tmp_start]
    }
    
    answer.push(answer_start, answer_end);
    return answer;
}
