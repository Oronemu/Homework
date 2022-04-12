class Summator:
    def transform(self, n):
        return n
 
    def sum(self, N):
        count = 0
        for i in range(N + 1):
            count += self.transform(int(i))
        return count

class PowerSummator(Summator):
    def __init__(self, b):
        self.b = b

    def transform(self, n):
        return n ** self.b

class SquareSummator(PowerSummator):
    def __init__(self):
        super().__init__(2)
 
class CubeSummator(PowerSummator):
    def __init__(self):
        super().__init__(3)

N = 10
summator = SquareSummator()
print(summator.sum(N))
print(N * (N + 1) * (2 * N + 1) / 6)