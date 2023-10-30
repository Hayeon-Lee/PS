def solution(s):
    stack = list()

    for bracket in s:
        if bracket == '(':
            stack.append(bracket)
        else:
            if not len(stack):
                return False
            else:
                stack.pop()

    if not len(stack):
        return True
    else:
        return False