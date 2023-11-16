from itertools import product

def solution(word):
    alphabets = ['A','E','I','O', 'U']
    
    dictionary = []
    
    for i in range(1,6):
        for p in product(alphabets, repeat = i):
            w = ''.join(p).strip()
            dictionary.append(w)
    
    dictionary.sort()
    answer = dictionary.index(word)+1
    
    return answer