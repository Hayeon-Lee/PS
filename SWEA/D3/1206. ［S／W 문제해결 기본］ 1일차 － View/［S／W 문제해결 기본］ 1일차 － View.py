def solution():
    for i in range(10):
        length = int(input())
        heights = list(map(int, input().split()))
        answer = 0

        #앞의 두개, 뒤의 두개를 제외
        for index in range(2, length-2, 1):

            #양쪽으로 +- 1개 확인하기
            left1 = heights[index]-heights[index-1]
            right1= heights[index]-heights[index+1]
            #나보다 양쪽으로 한칸의 건물 두 개가 키가 작으면 된다

            if left1 > 0 and right1 > 0:
                #양쪽으로 +- 2개 확인하기 
                left2 = heights[index]-heights[index-2]
                right2 = heights[index]-heights[index+2]
                if left2 > 0 and right2 > 0:
                    total_left = min(left1, left2)
                    total_right = min(right1, right2)
                    answer += min(total_left, total_right)
        
        print("#%d %d" %(i+1, answer))


solution()