import numpy as np

arr_1 = np.full((3, 4), 3)
print('a)', arr_1)

arr_2 = np.random.randint(0, 9, size=(2, 4))
print('b)', arr_2)

print('c)', arr_1.size, arr_2.size)

print('d)', np.row_stack((arr_1, arr_2)))

arr_3 = np.array([1, 8, 6, 5, 8, 3])
print('e)', arr_3)

arr_4 = arr_3 * 3 + 1
print('f)', arr_4)

arr_5 = arr_3.reshape((2, 3))
print('g)', arr_5)

print('h)', np.min(arr_5, 1))

print('i)', np.mean(arr_5))

arr_6 = np.square(np.arange(11))
print('j)', arr_6)

print('k)', arr_6[::2])

print('l)', arr_6[::-1])

arr_6[::2] = 2
print('m)', arr_6)

print('n)', 49 in arr_6)

a = np.random.randint(-10, 10, size=(5, 5))
b = a[a < 0]
print('o) (a)', a)
print('o) (b)', b)