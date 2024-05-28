class Solution {
    fun solution(s: String): IntArray {
        var newString = s.substring(2 until s.length)
        var splitArr = newString.split("}")
        
        var arr = ArrayList<MutableList<Int>>()

        splitArr.forEach{ it -> 
            var removeStr = it.replace(",{", "")
            var removeStrArr = removeStr.split(",")
            
            var tmpList = mutableListOf<Int>()
            removeStrArr.forEach {it -> 
                if (it != ""){ 
                    var tmpInt = it.toString().toInt()
                    tmpList.add(tmpInt)
                }
            }
            if (tmpList.size != 0) arr.add(tmpList)
        }
        
        arr.sortBy {it.size}
        var answerMap = mutableMapOf<Int, Int>()
        
        for (i:Int in 0 until arr.size) {
            for (j: Int in 0 until arr[i].size) {
                if (!answerMap.containsKey(arr[i][j])) answerMap[arr[i][j]] = 1
            }
        }
        
        var answer = arrayListOf<Int>()
        
        for ((key, value) in answerMap) answer.add(key)
        
        return answer.toIntArray()
    }
}

/*
}를 기준으로 분리한다.
분리된 각 요소에서 괄호와 반점이 아니면 숫자로 변경한 뒤 임시 배열에 저장한다.
문자열 끝까지 이를 수행한 후 배열에 추가한다.

배열내부 원소(배열)의 크기 순으로 정렬한다.
먼저 나온 숫자부터 정답배열에 추가한다.
*/