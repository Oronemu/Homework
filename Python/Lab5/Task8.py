arr = [1, 2]
arr2 = [1]


def mirror(arr):
    mirrored_part = reversed(arr)
    arr += list(mirrored_part)

mirror(arr)
mirror(arr2)

print(*arr)
print(*arr2)

