line = input()
left = line[:line.find("h")]
centre = line[line.find("h"):line.rfind("h") + 1]
right = line[line.rfind("h") + 1:]
print(left + centre[::-1] + right)