class Solution {
    fun isPrime (number: Long): Boolean {
        if (number <= 1) return false
        
        var sqrt = Math.sqrt(number.toDouble()).toLong()
        for (i in 2..sqrt) {
            if (number % i == 0L) return false
        }
        
        return true
    }
    
    fun solution(n: Int, k: Int): Int {
        
        var kString = n.toString(k)
        
        var numberArr = kString.split("0")
        var sindex = 0
        
        var answer: Int = 0

        for (i:Int in 0 until numberArr.size) {
            if (numberArr[i].length != 0) {
                if(isPrime(numberArr[i].toLong())) {
                    var location = kString.indexOf(numberArr[i], startIndex = sindex)
                    
                    //시작점일 경우
                    if (location == 0) {
                        // 이 숫자가 마지막인지 확인한다 [P]
                        if (numberArr[i].length == kString.length) return 1
                        // 마지막이 아니라면 뒤에 0이 있는지 확인한다 [P0]
                        else {
                            if(kString[numberArr[i].length] == '0') answer += 1
                        }
                    } 
                    //중간 위치일 경우
                    else {
                        if (kString[location-1] == '0') {
                            //끝인지 확인한다 [0P]
                            if ((location + numberArr[i].length) == kString.length) answer += 1
                            //중간에 껴있는지 확인한다 [0P0]
                            else {
                                if (kString[location + numberArr[i].length] == '0') answer += 1
                            }
                        }
                    }                  
                    sindex += numberArr[i].length
                }
            }
        }
        
        return answer
    }
}