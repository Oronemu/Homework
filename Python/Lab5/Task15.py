def linear(some_list):
    if some_list == []:
        return some_list
    if isinstance(some_list[0], list):
        return linear(some_list[0]) + linear(some_list[1:])
    return some_list[:1] + linear(some_list[1:])

print(*linear([[1, 2, 51, 31, "da"], 4, [[2, 4, 8, [0], {1, 2}], [[],[12,31]], 2 , 9]]))