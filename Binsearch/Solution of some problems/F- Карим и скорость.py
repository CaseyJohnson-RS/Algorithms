n = int(input())
l = [int(i) for i in input().split()]
x = [int(i) for i in input().split()]
t = int(input())


left, right = 0, sum(l) / t + 1


while right - left > 10**(-7):

    start_speed = (left + right) / 2

    speed = start_speed
    time = 0
    for i in range(n):
        time += l[i] / speed
        speed += x[i]
    f = t - time

    if f < 0:
        left = start_speed
    else:
        right = start_speed

print(round((right + left) / 2, 6))