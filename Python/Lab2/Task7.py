import random

list = [random.randint(0, 10) for i in range(0, 11)]
print(list)

for i in range(0, len(list) - 1, 2):
    list[i], list[i + 1] = list[i + 1], list[i]

print(list)