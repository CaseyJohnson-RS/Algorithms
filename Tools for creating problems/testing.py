def print_loader(percent, length = 50):
    cells = int(length * percent)
    print('\r', end='[')
    print('#' * cells, end='')
    print(' ' * (length - cells), end=']')
    print(f"  {(percent * 100) :.2f}%    ", end='')


from random import randrange, sample
def random_tests(rude_solve, smart_solve, data_generator, test_amount = 25):

    print("### Random tests ###")

    print_loader(0)

    print_rate = 2

    for _test in range(test_amount):

        data = data_generator()

        rude_solution = rude_solve(*data)
        smart_solution = smart_solve(*data)

        if rude_solution != smart_solution:
            print("\n\n FAIL \n")
            print("Rude answer:\n", rude_solution)
            print("Smart:\n", smart_solution)
            print("Data:")
            print(*data)
            return
        
        if ((_test + 1) % print_rate == 0):
            print_loader( (_test + 1) / test_amount )
            
    print_loader(1)
