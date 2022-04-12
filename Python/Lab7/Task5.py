class ReversedList:
    def __init__(self, list):
        self.list = list[::-1]

    def __len__(self):
        return len(self.list)

    def __getitem__(self, index):
        return self.list[index]

reversed_list = ReversedList([10, 20, 30])

for list in range(len(reversed_list)):
    print(reversed_list[list])