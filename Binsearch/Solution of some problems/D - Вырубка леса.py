a, k, b, m, x = map(int, input().split())

l = 0
r = x
while l < r - 1:
    mid = (l + r) // 2

    Dmitry_days = mid - mid // k
    Fedya_days = mid - mid // m
    can_cut = Dmitry_days * a + Fedya_days * b >= x

    if can_cut:
        r = mid
    else:
        l = mid

Dmitry_days = l - l // k
Fedya_days = l - l // m
can_cut = Dmitry_days * a + Fedya_days * b >= x

if can_cut:
    print(l)
else:
    print(r)
