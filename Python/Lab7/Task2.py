class Balance:
    left= 0
    right = 0

    def add_left(self, x):
        self.left += int(x)

    def add_right(self, x):
        self.right += int(x)

    def result(self):
        if self.left > self.right:
            return "L"
        elif self.left < self.right:
            return 'R'
        else:
            return '='

balance = Balance()
balance.add_right(10)
balance.add_left(5)
balance.add_left(5)
print(balance.result())
balance.add_left(1)
print(balance.result())