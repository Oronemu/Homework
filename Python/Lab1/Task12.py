x = int(input())

lenght = 0
limit = 1
line = ""

for i in range(x):
  lenght += 1
  line += str(i + 1) + " "
  if (lenght == limit):
    lenght = 0
    limit += 1
    print(line)
    line = ""