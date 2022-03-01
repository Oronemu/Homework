import random

list = [random.randint(0, 10) for i in range(0, 10)]
print(list)

for i in range(0, len(list)):
    for j in range(0, len(list)):
        if i != j and list[i] == list[j]:
            break
    else:
        print(list[i], end=' ')