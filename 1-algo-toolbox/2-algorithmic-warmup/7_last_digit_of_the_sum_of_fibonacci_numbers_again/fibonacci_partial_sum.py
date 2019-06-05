# Uses python3
import sys

def fibonacci_partial_Sum(from_, to):
    period = -1
    fibListMod = [0, 1]

    if from_ < 2 and to >= 1 :
        Sum = 1
    else: 
        Sum = 0

    for i in range(2, to+1):

        fibListMod.append((fibListMod[i-1] + fibListMod[i-2]) % 10)
        
        if fibListMod[i] == 1 and fibListMod[i-1] == 0:
            period = i-1
            break
        
        if i >= from_:
            Sum = (Sum + fibListMod[i]) % 10

    if period == -1:
        return Sum

    Sum_all = sum(fibListMod) - 1

    quotient1 = from_ // period
    remainder1 = from_ % period

    quotient2 = to // period
    remainder2 = to % period

    if quotient1 == quotient2:
        for i in range(remainder1, remainder2+1):
            Sum = (Sum + fibListMod[i]) % 10
    else:
        for i in range(remainder1, period +1):
            Sum = (Sum + fibListMod[i]) % 10

        if quotient2 != quotient1 + 1:
            Sum = (Sum + (Sum_all * (quotient2 - quotient1 - 1))) % 10

        for i in range(1, remainder2+1):
            Sum = (Sum + fibListMod[i]) % 10

    return Sum

def fibonacci_partial_Sum_naive(from_, to):
    Sum = 0

    current = 0
    next  = 1


    for i in range(to + 1):
        if i >= from_:
            Sum = (Sum + (current % 10)) % 10

        current, next = next, current + next

    return Sum % 10


if __name__ == '__main__':
    from_, to = map(int, input().split())
    print(fibonacci_partial_Sum(from_, to))