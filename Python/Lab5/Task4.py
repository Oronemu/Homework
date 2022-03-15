def power(a, n):
    res = 1
    for i in range(n):
        res *= a
    return res

print(power(3, 3))