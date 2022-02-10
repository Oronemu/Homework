height = input()

minHeight = 150
maxHeight = 190
count = 0

while height != "!":
    h = int(height)
    if h > 150 and h < 190:
        count += 1
        if h < minHeight:
            minHeight = h
        if h > maxHeight:
            maxHeight = h
    height = input()

print(count)
print(minHeight, maxHeight)