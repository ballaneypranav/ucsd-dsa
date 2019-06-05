# Uses python3

def fibonacci_sum_squares(n):

    if n <= 1:
        return n
    
    previous = 0
    current = 1

    for _ in range(n):
        previous, current = current, (previous + current) 
    
    return current*previous % 10

def fibonacci_sum_squares_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum      = 1

    for _ in range(n - 1):
        previous, current = current, previous + current
        sum += current * current

    return sum % 10


n = int(input())
print(fibonacci_sum_squares(n%30))

# for i in range(2000):
#     print(i)
#     if fibonacci_sum_squares(i%30) != fibonacci_sum_squares_naive(i):
#         break