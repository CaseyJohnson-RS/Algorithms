# Welcome to the repository with algorithms

This repository is created to store all sorts of algorithmic tools for future use. There is also a small set of tools for creating and testing problems.

## Structure

Let's look at the structure using the Binsearch topic as an example

The Binsearch folder contains the tools.py file. It contains functions that help in solving the problems of the current topic. For example, here is a left-hand binary search:

```python
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
```

And the Solution of some problems folder contains solutions to problems, but without the condition, unfortunately.


