import sys
input = sys.stdin.readline

n = int(input())

def check_prime(number):
    if number < 2:
        return False
    for i in range(2, int(number**0.5)+1):
        if number%i == 0:
            return False
    return True

def solution(number):
    if len((str(number))) == n:
        print(number)
    
    else:
        for i in range(10):
            tmp = number * 10 + i
            if check_prime(tmp):
                solution(tmp)

solution(2)
solution(3)
solution(5)
solution(7)