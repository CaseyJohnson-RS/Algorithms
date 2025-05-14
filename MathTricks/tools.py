def catalan_formula_efficient(n):
    """
    Вычисляет n-е число Каталана с использованием формулы и оптимизированным вычислением.

    Args:
        n: Индекс числа Каталана (начиная с 0).

    Returns:
        n-е число Каталана.
    """
    if n < 0:
        return 0
    c = 1
    for i in range(n):
        c = c * (2 * (2 * i + 1)) // (i + 2)
    return c


# Пример использования:
n = 2000
print(f"Число Каталана для n = {n}: {len(str(catalan_formula_efficient(n)))}")

