class Solution {
    fun solution(arr1: Array<IntArray>, arr2: Array<IntArray>): Array<IntArray> {
        var answer = Array(arr1.size) {IntArray(arr2[0].size)}
        
        for (i:Int in 0..arr1.size-1) {
            for (j:Int in 0..arr2[0].size-1) {
                for (k:Int in 0..arr1[0].size-1) {
                    answer[i][j] += arr1[i][k] * arr2[k][j]
                }
            }
        }
        
        return answer
    }
}