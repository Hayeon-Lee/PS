def solution(T):

    for i in range(T):
        length = int(input())
        arr = list(map(int, input().split()))

        answer = 0 #최종 금액
        price = 0 #내가 소비한 가격
        count = 0 #내가 산 개수
        
        biggest_price = arr[length-1]

        for index in range(length-2, -1, -1):
            if arr[index] < biggest_price:
                count += 1 #구매 개수
                price -= arr[index] #소비 금액
            
            else:
                earn = biggest_price * count
                earn += price
                answer += earn
                biggest_price = arr[index]
                count = 0
                price = 0
        
        if count:
            answer += ((biggest_price*count)+price)

        print("#%d %d" %(i+1, answer))

T= int(input())
solution(T)
