import java.util.*

class Solution {
    fun solution(want: Array<String>, number: IntArray, discount: Array<String>): Int {
        
        var copyDiscount = discount.toMutableList()
        var answer: Int = 0
        var hashMap = HashMap<String, Int>()
        
        for (i:Int in 0..want.size-1) {
            hashMap[want[i]] = number[i]
        }
        
        for (i:Int in 0..copyDiscount.size-1) {
            var cmpHashMap = HashMap<String, Int>()
            
            if ((i+10) <= copyDiscount.size) {
                var subList = copyDiscount.subList(i, i+10)
                for (j:Int in 0..subList.size-1) {
                    cmpHashMap[subList[j]] = (cmpHashMap[subList[j]] ?: 0) + 1
                }
            }
            
            var flag = 0
            hashMap.forEach {(key, value) ->
                if(cmpHashMap.containsKey(key)) {
                    if(cmpHashMap[key] != hashMap[key]) flag = 1
                }
                else flag = 1
            }
            
            if (flag == 0) answer += 1
        }
        
        return answer
    }
}