def solution(n, words):
    response_dict = {words[0]:1}
    answer = []

    who = 0
    when = 0
    
    for i in range(1, len(words)):
        if words[i-1][-1] == words[i][0] and words[i] not in response_dict:
            response_dict[words[i]] = 1
        else:
            who = (i+1)%n
            if who == 0: who = n
            
            when = (i+1)//n 
            if (i+1)%n != 0: when += 1
            
            break

    if not who and not when: return [0,0]
    return [who, when]