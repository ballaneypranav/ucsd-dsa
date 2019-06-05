# Uses python3

def countSplitInv(X, Y):
	i = 0
	j = 0
	k = 0
	p = len(X)
	q = len(Y)
	Z = []
	count = 0

	while (i < p and j < q):
		if Y[j] < X[i]:
			Z.append(Y[j])
			j = j + 1
			count = count + p - i
		else:
			Z.append(X[i])
			i = i + 1

	while i != p:
		Z.append(X[i])
		i = i + 1

	while j != q:
		Z.append(Y[j])
		j = j + 1

	return (Z, count)

def sortAndCountInv(numbers):
	n = len(numbers)

	if n < 2:
		return (numbers, 0)

	(X, b) = sortAndCountInv(numbers[: n//2])
	(Y, c) = sortAndCountInv(numbers[n//2 :])
	(Z, d) = countSplitInv(X, Y)

	return (Z, b + c + d)

n = int(input())
numbers = list(map(int, input().split()))

_, inversions = sortAndCountInv(numbers)

print(inversions)