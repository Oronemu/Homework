def recursive_len(some_list):
    if not some_list:
        return 0
    return 1 + recursive_len(some_list[:-1])

print(recursive_len([1, 2, 3]))