### Левосторонний бинпоиск ###
#
# Возвращает индекс первого элемента, 
# который >= target
# Исключение: 
#   Если target больше max(N),
#   то возвращается len(N) - 1
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


### Правосторонний бинпоиск ###
#
# Возвращает индекс последнего элемента, 
# который <= target
# Исключение: 
#   Если target больше min(N),
#   то возвращается 0
def rbs(N, target):

    l, r = 0, len(N) - 1
    while r - l > 1:
        m = (l + r) // 2
        if N[m] <= target:
            l = m
        else:
            r = m
    R = r if N[r] == target else l
    R = len(N) - 1 if N[-1] < target else R
    return R