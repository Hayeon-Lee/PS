from collections import Counter

def solution(participant, completion):
    pCounter = Counter(participant)
    cCounter = Counter(completion)
    
    diff = pCounter-cCounter
    answer = list(diff.keys())[0]
    return answer