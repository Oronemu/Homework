n = int(input())

for i in range(1, 2 * n, 2):
    empty = " " * ((2 * n - 1 - i) // 2)
    print(empty + "*" * i + empty)