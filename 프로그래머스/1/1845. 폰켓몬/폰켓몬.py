def solution(nums):
    pocketmon_amount = (len(nums)//2)
    pocketmon_set = set()
    
    for n in nums:
        pocketmon_set.add(n)
    
    if len(pocketmon_set) >= pocketmon_amount:
        return pocketmon_amount
    
    else:
        return len(pocketmon_set)
    