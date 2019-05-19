# Uses python3
def calc_fib(n):
    fibList = []

    fibList.append(0);
    fibList.append(1);

    if (n < 2):
    	return fibList[n]

    for i in range(2, n+1):
      	fibList.append(fibList[i-1] + fibList[i-2]);
    
    return fibList[n]

n = int(input())
print(calc_fib(n))
