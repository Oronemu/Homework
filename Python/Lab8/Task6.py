import random

file = open('/Users/ivanrovkov/Desktop/Homework/Python/Lab8/res/lines.txt', encoding='utf8')
data = file.read()
lines = data.split('\n')
n = len(lines)
if n:
    line = random.randrange(n)
    print(lines[line])
file.close()