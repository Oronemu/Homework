import numpy as np

def super_sort(rows, cols):
    A = np.random.randint(1, 101, (rows, cols))
    B = A.copy()
    B[:,::2]=-np.sort(-B[:,::2], axis=0)
    B[:,1::2]=np.sort(B[:,1::2], axis=0)
    return A, B

print(super_sort(4, 4))