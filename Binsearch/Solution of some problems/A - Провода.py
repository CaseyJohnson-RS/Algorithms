N, K = [int(i) for i in input().split()]
L = [int(input()) for _ in range(N)]

L.sort()

def lbs(N, target):

    l, r = 0, len(N) - 1
    while r - l > 1:
        m = (l + r) // 2
        if N[m] < target:
            l = m
        else:
            r = m
    L = l if N[l] == target else r
    L = 0 if N[0] > target else L
    return L


def segment_count(segment_len):
    count = 0
    for segments in range(1, L[-1] // segment_len + 1):
        index = lbs(L, segments * segment_len)
        count += N - index
    return count


left = 0
right = L[-1]

while right - left > 1:
    middle = (left + right) // 2
    count = segment_count(middle)
    if count < K:
        right = middle
    else:
        left = middle

if segment_count(right) == K:
    print(right)
elif segment_count(left) == K:
    print(left)
else:
    print(0)