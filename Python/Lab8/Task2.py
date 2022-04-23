import numpy as np

def make_field(size):
    chess = np.zeros((size, size), dtype='int8')
    chess[size % 2::2, ::2] = 1 
    chess[(size + 1) % 2::2, 1::2] = 1 
    return chess

print(make_field(50))
