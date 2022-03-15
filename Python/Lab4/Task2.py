n = int(input())
synonym = {}

for i in range(n):
    first, second = input().split()
    synonym[first] = second
    synonym[second] = first

print(synonym[input()])