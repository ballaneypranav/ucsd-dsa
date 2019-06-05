# Uses python3
import sys

def fast_count_segments(starts, ends, points):
    n = len(points)
    counts = [0] * n
    segments = dict(zip(starts, ends))
    starts.sort()

    for i in range(n):
        for start in starts:
            if start <= points[i]:
                if segments[start] >= points[i]:
                    counts[i] += 1
            else:
                break

    return counts

def naive_count_segments(starts, ends, points):
    counts = [0] * len(points)
    for i in range(len(points)):
        for j in range(len(starts)):
            if starts[j] <= points[i] <= ends[j]:
                counts[i] += 1
    return counts

if __name__ == '__main__':

    s, p = map(int, input().split())

    starts = []
    ends = []
    for i in range(s):
        start, end = map(int, input().split())
        starts.append(start)
        ends.append(end)

    points = list(map(int, input().split()))

    counts = fast_count_segments(starts, ends, points)
    for count in counts:
        print(count, end=" ")
    print()