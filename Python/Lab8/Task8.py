def reverse():
    with open('/Users/ivanrovkov/Desktop/Homework/Python/Lab8/res/input.dat', 'rb') as input_file:
        temp = input_file.read()
    with open('/Users/ivanrovkov/Desktop/Homework/Python/Lab8/res/output.dat', 'wb') as out_file:
        out_file.write(temp[::-1])

reverse()
