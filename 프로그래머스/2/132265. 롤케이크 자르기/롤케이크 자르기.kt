class Solution {
    fun solution(topping: IntArray): Int {
        
        var arr1 = IntArray(topping.size) {0}
        var arr2 = IntArray(topping.size) {0}
        var toppingType = mutableSetOf<Int>()
        
        var answer = 0
        
        for (i in 0 until topping.size) {
            toppingType.add(topping[i])
            arr1[i] = toppingType.size
        }
        
        toppingType.clear()
        
        for (i in topping.size-1 downTo 0) {
            toppingType.add(topping[i])
            arr2[i] = toppingType.size
        }
        
        for (i in 0 until topping.size-1) {
            if (arr1[i] == arr2[i+1]) answer += 1
        }
        
        return answer
    }
}