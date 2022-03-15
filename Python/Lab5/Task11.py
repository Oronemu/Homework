def matrix(*args):
    if len(args) == 0:
        return list('0')
    elif len(args) == 1:
        return [[0] * args[0] for i in range(args[0])]
    elif len(args) == 2:
        return [[0] * args[1] for i in range(args[0])]
    elif len(args) == 3:
        return [[args[2]] * args[1] for i in range(args[0])]

rows = matrix(2)
for row in rows:
    print(*row)