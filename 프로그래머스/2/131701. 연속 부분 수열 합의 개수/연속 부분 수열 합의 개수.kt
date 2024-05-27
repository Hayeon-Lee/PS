import java.util.*

class Solution {
    fun solution(elements: IntArray): Int {
        var answerSet = mutableSetOf<Int>()
        val length = elements.size
        
        for (pickCnt:Int in 0..(length-1)) {
            for (index:Int in 0..(length-1)) {
                var sum = 0
                for (repeat:Int in 0..pickCnt) {
                    sum+=(elements[(index+repeat)%length])
                }
                answerSet.add(sum)
            }
        }
        return answerSet.size
    }
}