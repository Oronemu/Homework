a = input()
max = max(a)
min = min(a)

for i in a:
    if i != max and i != min:
        break
if (int(max) + int(min)) / 2 == int(i):
    print("Вы ввели красивое число")
else:
    print("Жаль, вы ввели обычное число")