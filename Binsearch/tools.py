
def left_binsearch(N, target):

    """
    Левосторонний бинарный поиск в массиве. Если target больше max(N), то будет возвращено -1.

    Args:
        N: массив
        target: целевое значение

    Returns:
        Индекс первого i, при котором N[i] >= target
        
    """

    l, r = 0, len(N) - 1
    while r - l > 1:
        m = (l + r) // 2
        if N[m] < target:
            l = m
        else:
            r = m
    L = l if N[l] >= target else r
    L = -1 if target > N[-1] else L
    return L


def right_binsearch(N, target):
    """
    Правосторонний бинарный поиск в массиве. Если target меньше min(N), то будет возвращено -1.

    Args:
        N: массив
        target: целевое значение

    Returns:
        Индекс последнего i, при котором N[i] <= target
    """

    l, r = 0, len(N) - 1
    while r - l > 1:
        m = (l + r) // 2
        if N[m] <= target:
            l = m
        else:
            r = m
    R = r if N[r] <= target else l
    R = -1 if target < N[0] else R
    return R


def ternary_search(f, left, right, delta=10**(-7)):
    """
    Тернарный поиск минимума функции, которая сначала строго убывает, а затем строго возрастает на отрезке [left; right].

    Args:
        f: массив
        left: левая граница поиска
        right: правая граница поиска
        delta: точность

    Returns:
        Значение аргумента функции f, при котором функция минимальная на отрезке [left; right]
    """
    fl, fr, fm = f(left), f(right), f( (left + right) / 2 )
    if  fl < fm and fr < fm:
        raise ValueError("The function does not satisfy the condition: first it strictly decreases, and then it strictly increases.")

    while right - left > delta:

        delta_x = (right - left) / 3

        if f(left + delta_x) < f(right - delta_x):
            right -= delta_x
        else:
            left += delta_x
    
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