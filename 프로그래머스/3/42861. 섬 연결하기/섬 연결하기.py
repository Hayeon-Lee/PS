def getParent(parent, x):
    if parent[x] == x:
        return x
    return getParent(parent, parent[x])

def unionParent(parent, a, b):
    a = getParent(parent, a)
    b = getParent(parent, b)
    
    if a > b:
        parent[a] = b
    else:
        parent[b] = a

def sameParent(parent, a, b):
    a = getParent(parent, a)
    b = getParent(parent, b)
    
    if a == b:
        return True
    else:
        return False

def solution(n, costs):
    parent = [i for i in range(n)]
    answer = 0
    count = 0
    
    costs = sorted(costs, key=lambda x: x[2])
    length = len(costs)
    
    for cost in costs:
        s, e, c = cost
        
        if sameParent(parent, s, e) == False:
            unionParent(parent, s, e)
            answer += c
            
    return answer
