from math import sqrt

v1, v2 = [int(i) for i in input().split()]
a = float(input())

left, right = 0, 1

while right - left > 10**(-10):

    lx = left + (right - left) / 3
    rx = right - (right - left) / 3
    
    value_r = sqrt( (1 - a)**2 + rx**2 ) / v1 + sqrt( a**2 + (1 - rx)**2 ) / v2
    value_l = sqrt( (1 - a)**2 + lx**2 ) / v1 + sqrt( a**2 + (1 - lx)**2 ) / v2

    if value_l < value_r:
        right = rx
    else:
        left = lx

print(round(lx,6))