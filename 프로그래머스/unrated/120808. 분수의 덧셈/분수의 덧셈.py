import math

def solution(numer1, denom1, numer2, denom2):
    numer = 0
    denom = 0
    
    if denom1 == denom2:
        denom = denom1
        numer = (numer1 + numer2)
    
    else:
        denom = (denom1 * denom2)
        numer = (numer1 * denom2 + numer2 * denom1)
    
    divisor = math.gcd(numer, denom)
    return [numer/divisor, denom/divisor]
        