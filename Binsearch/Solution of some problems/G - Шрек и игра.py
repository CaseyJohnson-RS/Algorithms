import sys

N = int(input())

print(1, 1)
s = input()
sys.stdout.flush()

e = 0
r = N + 1

while r - e > 1:
    m = (e + r) // 2

    print(1, m)
    res = input()
    sys.stdout.flush()

    if res == s:
        e = m
    else:
        r = m

if s == '1':
    print(2, e)
else:
    print(2, N - e)