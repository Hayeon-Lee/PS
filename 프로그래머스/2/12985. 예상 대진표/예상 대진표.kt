class Solution {
    fun evenOrOdd(arg:Int):Int {
        if (arg % 2 == 0) {return (arg/2)}
        else {(return (arg/2)+(arg%2))}
    }
    
    fun solution(n: Int, a: Int, b: Int): Int {
        var first = 0
        var second = 0
        
        if (a <= b) {
            first = a
            second = b
        }
        else {
            first = b
            second = a
        }
        
        var answer = 0
        
        while (true) {
            if (first == second) { return answer }
            
            first = evenOrOdd(first)
            second = evenOrOdd(second)
            
            answer += 1
        }
        
    }
}