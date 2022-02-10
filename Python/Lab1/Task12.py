x = int(input())

lenght = 0
limit = 1
strin = ""

for i in range(x):
      lenght += 1
      strin += str(i + 1) + " "
      if (lenght == limit):
        lenght = 0
        limit += 1
        print(strin)
        strin = ""
print(strin)