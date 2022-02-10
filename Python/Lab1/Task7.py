tmp = 0
num = int(input())

a = num % 10
b = num // 10 % 10
c = num // 100 % 10
d = num // 1000

if a > b:
    tmp = a
    a = b
    b = tmp
if b > c:
    tmp = b
    b = c
    c = tmp
if c > d:
    tmp = c
    c = d
    d = tmp
if a > b:
    tmp = a
    a = b
    b = tmp
if b > c:
    tmp = b
    b = c
    c = tmp
if a > b:
    tmp = a
    a = b
    b = tmp
if a == 0 and b:
    tmp = a
    a = b
    b = tmp
if a == 0 and c:
    tmp = a
    a = c
    c = tmp
if a == 0 and d:
    tmp = a
    a = d
    d = tmp
print(d + 10 * (c + 10 * (b + 10 * a)))
