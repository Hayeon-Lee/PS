import java.util.*

class Solution {
    
    fun solution(s: String): Int {
        var copys = s.toMutableList()
        var answer:Int = 0
        
        for (i:Int in 1..copys.size) {
            if (i != 1) {
                var tmp = copys[0]
                copys.removeAt(0)
                copys.add(tmp)
            }
            
            var dq = ArrayDeque<Char>()
            
            for (i:Int in 0..copys.size-1) dq.add(copys[i])
                
            var stack = Stack<Char>()
            var flag = 0
            while(!dq.isEmpty()) {
                var item = dq.peek()
                dq.remove()

                if ((item == '(') or (item == '{') or (item == '[' )){
                    stack.push(item)
                } 
                else {
                    if (stack.isEmpty()) {
                        flag = 1
                        break
                    }

                    else if (item == ')') {
                        var top = stack.pop()
                        if (top != '(') {
                            flag = 1
                            break
                        }
                    }

                    else if (item == '}') {
                        var top = stack.pop()
                        if (top != '{') {
                            flag = 1
                            break
                        }
                    }

                    else {
                        var top = stack.pop()
                        if (top != '[') {
                            flag = 1
                            break
                        }
                    }
                }
            }
            if ((flag == 0) and (stack.isEmpty())) answer += 1
            
        }
        return answer
    }
}