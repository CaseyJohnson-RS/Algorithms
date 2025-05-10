
def left_binsearch(N, target):

    """
    Левосторонний бинарный поиск в массиве

    Args:
        N: массив
        target: целевое значение

    Returns:
        Индекс первого i, при котором N[i] >= target
    
    ## Warning
        Если target больше max(N), то будет возвращено len(N) - 1
    """

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


def right_binsearch(N, target):
    """
    Правосторонний бинарный поиск в массиве

    Args:
        N: массив
        target: целевое значение

    Returns:
        Индекс последнего i, при котором N[i] <= target
    
    ## Warning
        Если target больше min(N), то будет возвращено 0
    """

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


### Троичный поиск минимума функции ### 
# 
# Возвращает X, при котором функция минимальна
def ternary_search(f, left, right):

    while right - left > 10**(-10):

        delta = (right - left) / 3

        if f(left + delta) < f(right - delta):
            right -= delta
        else:
            left += delta
    
    return (right + left) / 2



def binary_search_by_function(f, left, right, mode='r', delta = 10**(-7)): 
    """
    Бинарный поиск нуля монотонной функции

    Args:
        f: монотонная функция
        left: левая граница поиска
        right: правая граница поиска
        mode: способ поиска ['i', 'r'] - integer, real
        delta: точность (используется только при mode='r')

    Returns:
        Точка, в которой f равняется 0
    """

    if f(left) * f(right) > 0:  raise ValueError(f"The function is not monotone or has no solutions on the interval [{left}; {right}]")
    if mode not in ['i', 'r']:  raise ValueError(f"Mode must be one of the {['i', 'r']}")

    inc = 1 if f(left) <= 0 else -1
    delta = delta if mode == 'r' else 1

    while right - left > delta:

        middle = (left + right) / 2 if mode == 'r' else (left + right) // 2

        if inc * f(middle) < 0:
            left = middle
        else:
            right = middle
    
    return left if abs(f(left)) < abs(f(right)) else right