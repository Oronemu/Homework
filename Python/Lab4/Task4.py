ACTION = {
    'read': 'R',
    'write': 'W',
    'execute': 'X',
}
 
file_system = {}
n = int(input())

for i in range(n):
    file, *actions = input().split()
    file_system[file] = set(actions)
 
for i in range(int(input())):
    action, file = input().split()
    if ACTION[action] in file_system[file]:
        print('OK')
    else:
        print('Access denied')