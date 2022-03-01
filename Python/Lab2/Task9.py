from turtle import width


count_of_queens = 8
width = []
height = []
is_correct = True

for i in range(0, count_of_queens):
    x_input, y_input = [int(line) for line in input().split()]
    width.append(x_input)
    height.append(y_input)

for i in range(count_of_queens):
    for j in range(i + 1, count_of_queens):
        if width[i] == width[j] or height[i] == height[j] or abs(width[i] - width[j]) == abs(height[i] - height[j]):
            correct = False

if is_correct:
    print('NO')
else:
    print('YES')