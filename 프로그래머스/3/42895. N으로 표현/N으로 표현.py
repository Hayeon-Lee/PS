def solution(N, number):
    if N == number:
        return 1
    
    dp = [{N}]
    for i in range(2,9):
        nums = set([int(str(N)*i)])
        for j in range(0, int(i/2)):
            for x in dp[j]:
                for y in dp[i-j-2]:
                    nums.add(x+y)
                    nums.add(x-y)
                    nums.add(y-x)
                    nums.add(x*y)
                    if y != 0:
                        nums.add(x//y)
                    if x != 0:
                        nums.add(y//x)
        if number in nums:
            return i
        dp.append(nums)
    return -1
    
    