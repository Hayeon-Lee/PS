class Solution {
    
    fun solution(n: Int): Long {
        var answerArr = LongArray(n+1)
        
        answerArr[0] = 1
        answerArr[1] = 1
        
        if (n<2) return answerArr[n]%123_456_7
        
        for (i: Int in 2..n) {
            answerArr[i] = (answerArr[i-1]+answerArr[i-2])%123_456_7
        }
        
        return answerArr[n]
    }
}