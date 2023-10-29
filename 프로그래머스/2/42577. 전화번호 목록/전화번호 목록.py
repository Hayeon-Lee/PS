def solution(phone_book):
    phone_book.sort()
    
    for i in range(len(phone_book)-1):
        first_num = phone_book[i]
        second_num = phone_book[i+1]
        
        if first_num in second_num and second_num.index(first_num) == 0:
            return False
    
    return True