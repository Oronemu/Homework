import random

list = [random.randint(0, 9) for i in range(0, 10)]
print(list)

for i in range(1, len(list)):
    if list[i] > list[i - 1]:
        print(list[i])