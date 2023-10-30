def solution(arr):
    stack = list()

    for item in arr:
        if not len(stack):
            stack.append(item)
        else:
            top = stack[-1]
            if top != item:
                stack.append(item)
    
    return stack