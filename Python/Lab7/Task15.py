class Digits:
    def __init__(self, list):
        self.list = [int(x) for x in list.split()]
 
    def make_negative(self):
        for i in range(len(self.list)):
            self.list[i] = -abs(self.list[i])
 
    def square(self):
        for i in range(len(self.list)):
            self.list[i] = (self.list[i]) ** 2
 
    def strange_command(self):
        for i in range(len(self.list)):
            if self.list[i] % 5 == 0:
                self.list[i] += 1
 
    def stringify(self):
        for i in range(len(self.list)):
            self.list[i] = str(self.list[i])
            
digits = Digits(input())

for i in range(int(input())):
    operation = input()
    if operation == 'make_negative':
        digits.make_negative()
    elif operation == 'square':
        digits.square()
    else:
        digits.strange_command()

digits.stringify()
print(' '.join(digits.list))