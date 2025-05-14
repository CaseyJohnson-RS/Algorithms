C = float(input())

e, r = 0, 10**5

while r - e > 10**(-6):
    x = (e + r) / 2
    if x**2 + x**0.5 < C:
        e = x
    else:
        r = x

print(f"{((r + e) / 2):.6f}")