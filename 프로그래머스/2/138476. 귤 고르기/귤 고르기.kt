import java.util.*

class Solution {
    fun solution(k: Int, tangerine: IntArray): Int {
        var tangerineMap = hashMapOf<Int, Int>()
        
        tangerine.forEach { item ->
            tangerineMap[item] = (tangerineMap[item] ?: 0) + 1
        }
        
        var valueList = tangerineMap.values.sortedDescending()
        
        var answer: Int = 0
        var count: Int = 0
        for (index:Int in 0..valueList.size) {
            answer += 1
            count += valueList[index]
            
            if (count >= k) break
        }
        
        return answer
    }
}