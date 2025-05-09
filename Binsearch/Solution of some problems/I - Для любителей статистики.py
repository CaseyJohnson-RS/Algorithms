n = int(input())
N = list(map(int, input().split()))
q = int(input())
Q = [ [int(i) for i in input().split()] for _ in range(q) ]

M = sorted([ (N[i], i + 1) for i in range(n) ])
A = ''

for qi in range(q):

    l, r = 0, n - 1
    while r - l > 1:
        m = (l + r) // 2
        if M[m][0] < Q[qi][2]:
            l = m
        else:
            r = m
    L = l if M[l][0] == Q[qi][2] else r


    if M[L][0] != Q[qi][2]:
        A += '0'
        continue

    l, r = L, n - 1
    while r - l > 1:
        m = (l + r) // 2
        if M[m][0] <= Q[qi][1]:
            l = m
        else:
            r = m
    R = r if M[r][0] == Q[qi][2] else l

    while R - L > 1:
        m = (L + R) // 2
        if Q[qi][0] <= M[m][1] <= Q[qi][1]:
            break
        elif M[m][1] < Q[qi][0]:
            L = m
        else:
            R = m

    A += '1' if Q[qi][0] <= M[L][1] <= Q[qi][1] else '0'

print(A)