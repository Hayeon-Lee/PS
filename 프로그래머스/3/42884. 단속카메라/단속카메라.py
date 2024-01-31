def solution(routes):
    routes = sorted(routes, key=lambda x:x[1])
    
    start = routes[0][0]
    end = routes[0][1]
    answer = 1
    
    for route in routes[1:]:
        s, e = route
        
        if s <= end:
            start = s
        
        else :
            end = e
            answer += 1
        
    return answer