n, k = [int(i) for i in input().split()]
N = [int(i) for i in input().split()]


left, right = 0, 10**9

while right - left > 1:

    min_distance = (left + right) / 2

    ni = 0
    can_fit = True
    for ki in range(1, k):
        
        new_ni = ni
        while new_ni < n and N[new_ni] - N[ni] < min_distance:
            new_ni += 1
        if new_ni == n:
            can_fit = False
            break
        else:
            ni = new_ni

    if can_fit:
        left = min_distance
    else:
        right = min_distance

right = int(right)
left = int(left)

ni = 0
can_fit = True
for ki in range(1, k):
    
    new_ni = ni
    while new_ni < n and N[new_ni] - N[ni] < right:
        new_ni += 1
    if new_ni == n:
        can_fit = False
        break
    else:
        ni = new_ni

print(right if can_fit else left)
