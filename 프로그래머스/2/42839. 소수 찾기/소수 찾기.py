from itertools import permutations

def eratos(isPrime, integer):
    isPrime[0] = False
    isPrime[1] = False
    
    m = int(integer**0.5)

    for i in range(2, m + 1):
        if isPrime[i] == True:
            for j in range(i+i, integer+1, i):
                isPrime[j] = False

def solution(numbers):
    numbers = list(numbers) #문자열로 들어온 숫자를 리스트로 변환
    integers = []

    #길이만큼 순열로 뽑아야 하기 때문에 len(numbers)+1
    for i in range(1, len(numbers)+1):
        #조합으로 숫자 만들기
        c_list = list(permutations(numbers, i))
        for c in c_list:
            integers.append(int(''.join(list(c))))
    
    #중복 숫자 제거하기
    integers = sorted(list(set(integers)))
    maximum_number = integers[-1]

    #소수인지 아닌지 체크하는 배열
    isPrime = [True for _ in range(maximum_number+1)] 
    eratos(isPrime, maximum_number)

    answer = 0
    for integer in integers:
        if isPrime[integer] == True: answer+=1
    
    return answer
