numbers = [int(i) for i in input().split()]
before = set()
for number in numbers:
    print(number, end=' ')
    if number in before:
        print('YES')
    else:
        print('NO')
        before.add(number)