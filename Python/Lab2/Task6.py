import random

list = [random.randint(-9, 9) for i in range(0, 10)]
print(list)

for i in range(1, len(list)):
    if list[i] * list[i - 1] > 0:
        print(list[i - 1], list[i])
        break