# Uses python3
import sys

def fibonacci_huge(n, m):
    fibListMod = []

    fibListMod.append(0)
    fibListMod.append(1)
    fibListMod.append(1)

    for i in range(3, n):
        fibListMod.append((fibListMod[i-1] + fibListMod[i-2]) % m)

        if fibListMod[i] == 1 and fibListMod[i-1] == 0:
            p = i-1
            break

    mod = n % p

    return fibListMod[mod]

if __name__ == '__main__':
    n, m = map(int, input().split())
    print(fibonacci_huge(n, m))
