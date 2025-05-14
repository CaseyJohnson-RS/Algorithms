n, a, b, w, h = [int(i) for i in input().split()]


left, right = 0, 10**18

while right - left > 1:

        middle = (left + right) // 2

        # Начало проверки
        can_fit = False
        x, y = a + 2 * middle, b + 2 * middle
        an, bn = w // x, h // y
        if an * bn >= n:
            can_fit = True
        else:
            an, bn = h // x, w // y
            can_fit = an * bn >= n 
        # Конец проверки

        if can_fit:
            left = middle
        else:
            right = middle

# Начало проверки
can_fit = False
x, y = a + 2 * right, b + 2 * right
an, bn = w // x, h // y
if an * bn >= n:
    can_fit = True
else:
    an, bn = h // x, w // y
    can_fit = an * bn >= n 
# Конец проверки

print(right if can_fit else left)
