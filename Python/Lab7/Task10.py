class Summator:
    def transform(self, n):
        return n
 
    def sum(self, n):
        count = 0
        for i in range(n + 1):
            count += self.transform(int(i))
        return count
 
class SquareSummator(Summator):
    def transform(self, n):
        return n ** 2
 
class CubeSummator(Summator):
    def transform(self, n):
        return n ** 3

n = 10
summator = SquareSummator()
print(summator.sum(n))
print(n * (n + 1) * (2 * n + 1) / 6)