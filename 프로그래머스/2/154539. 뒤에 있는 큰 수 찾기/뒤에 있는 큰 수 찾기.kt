import java.util.ArrayDeque

class Solution {
    fun solution(numbers: IntArray): IntArray {
        var answer = IntArray(numbers.size) {-1}
        var stack = ArrayDeque<Int>()
        
        for (i in numbers.indices.reversed()) {
            if (stack.isEmpty()) answer[i] = -1
            else {
                while(!stack.isEmpty()){
                    var cmp = stack.peekLast()
                    if (cmp > numbers[i]) {
                        answer[i] = cmp
                        break
                    }
                    else stack.removeLast()
                }
            }
            stack.addLast(numbers[i])
        }
        
        return answer
    }
}