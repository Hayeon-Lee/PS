def solution(clothes):
    closet = {}
    result = 1
    
    for elements in clothes:
        key = elements[1]
        value = elements[0]
        if key in closet:
            closet[key].append(value)
        else:
            closet[key] = [value]
            
    for key in closet.keys():
        result = result * (len(closet[key])+1)
    
    return result - 1