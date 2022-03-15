def partial_sums(*args):
    sum = 0
    l = [0]
    for i in range(len(args)):
        sum += args[i]
        l.append(sum)
    return l

print(partial_sums(1, 0.5, 0.25, 0.125))