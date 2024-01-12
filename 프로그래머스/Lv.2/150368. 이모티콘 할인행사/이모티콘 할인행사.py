from itertools import product

def solution(users, emoticons):
    
    plus_user = 0 #플러스 구독자
    plus_benefit = 0 #플러스 이득
    
    discounts = [10, 20, 30, 40] 
    for discount in product(discounts, repeat=len(emoticons)): #중복순열
    
        tmp_user = 0 #해당 할인율일 때, 플러스 구독자
        tmp_benefit = 0 #해당 할인율일 때, 플러스 이득
        
        for user in users:
            sale, max_cash = user
            price = 0 #사용자가 해당 할인율일 때 지불한 금액
            
            for i in range(len(emoticons)):
                #할인율이 기준보다 높다(=산다)
                if discount[i] >= sale:
                    price += emoticons[i] * (100-discount[i]) / 100
                    
            if price >= max_cash: #허용선보다 넘으면 플러스 구독
                tmp_user += 1
            else: #허용선보다 안넘으면 플러스 구독 안 함
                tmp_benefit += price
        
        if tmp_user > plus_user:
            plus_user = tmp_user
            plus_benefit = tmp_benefit
        
        elif tmp_user == plus_user:
            plus_benefit = max(tmp_benefit, plus_benefit)
            
        else:
            continue
            
    return [plus_user, plus_benefit]
    
'''
user 최대 100명, 이모티콘 최대 7개, 7*4 = 28가지 경우의 수
유저명수 100명 * 28 = 2800 -> 브루트포스 가능

1) 이모티콘 별로 10%~40% 할인율 전부 뽑아서
2) 사용자가 할인된 임티 샀을 때 보유 돈 보다 많은지 적은지 확인
3) 할인율마다 최댓값으로 갱신
'''