class Selector:
    def __init__(self, list):
        self.list = list
        self.even = []
        self.odd = []
        for i in self.list:
            if i % 2 == 0:
                self.even.append(i)
            else:
                self.odd.append(i)

    def get_odds(self):
        return self.odd

    def get_evens(self):
        return self.even

values = [11, 12, 13, 14, 15, 16, 22, 44, 66]
selector = Selector(values)
odds = selector.get_odds()
evens = selector.get_evens()
print(' '.join(map(str, odds)))
print(' '.join(map(str, evens)))