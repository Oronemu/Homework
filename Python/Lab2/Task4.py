line = input()
if line.count("f") == 1:
    print(line.find("f"))
elif line.count("f") > 1:
    print(line.find("f"), line.rfind("f"))