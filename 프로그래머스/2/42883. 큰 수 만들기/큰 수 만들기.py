def solution(number, k):
    stack = []
    
    for n in number:
        if len(stack) == 0: 
            stack.append(n)
            continue
        
        if k > 0:
            while stack[-1] < n:
                stack.pop()
                k -= 1
                if len(stack) == 0 or k <= 0:
                    break
        stack.append(n)
    
    return ''.join(stack[:len(stack)-k])
    