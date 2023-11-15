def solution(array):
    counts = {}
    
    for item in array:
        if item not in counts.keys(): counts[item] = 1
        else: counts[item] += 1
        
    counts = sorted( counts.items(), key = lambda x:x[1], reverse=True)
    
    if len(counts) == 1: return counts[0][0]    
    elif counts[0][1] == counts[1][1]: return -1
    else: return counts[0][0]