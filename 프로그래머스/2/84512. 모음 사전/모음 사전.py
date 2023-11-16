from itertools import product

def solution(word):
    alphabets = ['A','E','I','O', 'U']
    
    dictionary = []
    
    for i in range(1,6):
        #같은 알파벳 반복해서 넣기, 1일 땐 순열로 만듦
        #if i != 1:
        #    for a in alphabets:
        #        dictionary.append(a*i)
            
        #순열 만들기
        for p in product(alphabets, repeat = i):
            w = ''.join(p).strip()
            dictionary.append(w)
    
    dictionary.sort()
    #print(dictionary)
    answer = dictionary.index(word)+1
    
    return answer