width = int(input())
height = int(input())
symb = "*"

print(symb * width)
for i in range(1, height - 1):
    print(symb + " " * (width - 2) + symb)
print(symb * width)