# python3


def max_pairwise_product(numbers):
    n = len(numbers)
    max1 = -1
    max2 = -1
    for i in range(n):
        if max1 < numbers[i]:
            max1 = numbers[i]
            index = i

    for i in range(n):
        if max2 < numbers[i] and index != i:
            max2 = numbers[i]

    return max1 * max2


if __name__ == '__main__':
    input_n = int(input())
    input_numbers = [int(x) for x in input().split()]
    print(max_pairwise_product(input_numbers))
