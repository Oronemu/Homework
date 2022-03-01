line = input()
left = line[:line.find("h")]
center = line[line.find("h"):line.rfind("h") + 1]
right = line[line.rfind("h") + 1:]
print(left + center[::-1] + right)