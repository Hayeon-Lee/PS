def solution(triangle):
    if len(triangle) == 1: return triangle[0][0]
    
    if len(triangle) == 2:
        return max(triangle[0][0]+triangle[1][0], triangle[0][0]+triangle[1][1])
    
    first = triangle[0][0]
    second = triangle[0][0]+triangle[1][0]
    third = triangle[0][0]+triangle[1][1]
    
    sum_triangle = [[first], [second, third]]
    
    for i in range(1, len(triangle)-1):
        next_line_arr = []
        
        left = 0
        right = 0
        
        for j in range(len(triangle[i])):
            left = max(left, sum_triangle[i][j] + triangle[i+1][j])
            right = sum_triangle[i][j] + triangle[i+1][j+1]
            next_line_arr.append(left)
            left = right
        next_line_arr.append(right)
        sum_triangle.append(next_line_arr)
    
    return max(sum_triangle[-1])
    

'''
자기 인덱스에서 +0, +1 한 요소를 더해줍니다.

'''