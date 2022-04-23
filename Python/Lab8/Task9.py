with open('/Users/ivanrovkov/Desktop/Homework/Python/Lab8/res/input.txt', 'r') as input_file:
    temp = [int(i) for i in input_file.read().split()]

metka1 = []
metka2 = []
metka3 = []

for i in temp:
    if i > 0:
        metka1.append(i)
    elif i < 0:
        metka2.append(i)
    else:
        metka3.append(i)

with open('/Users/ivanrovkov/Desktop/Homework/Python/Lab8/res/output.txt', 'w') as output_file:
    print(len(temp), file=output_file)
    print('1', len(metka1), '-1', len(metka2), '0', len(metka3), file=output_file)
