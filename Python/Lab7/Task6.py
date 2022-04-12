class SparseArray:
    def __init__(self):
        self.data = {}

    def __getitem__(self, key):
        return self.data.get(key, 0)

    def __setitem__(self, key, value):
        self.data[key] = value

arr = SparseArray()
arr[10] = 123
for i in range(8, 13):
    print('arr[{}] = {}'.format(i, arr[i]))