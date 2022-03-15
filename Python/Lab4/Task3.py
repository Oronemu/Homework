n = int(input())
vote = {}

for i in range(n):
    name, count = input().split()
    vote[name] = vote.get(name, 0) + int(count)

print()

for name, count in sorted(vote.items()):
    print(name, count)