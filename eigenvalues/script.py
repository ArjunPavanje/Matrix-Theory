import numpy as np
from scipy.linalg import hessenberg
from scipy.linalg import qr
from pprint import pprint

A = np.array([
    [1.0 + -1.0j, 2.0 + 3.0j, -1.0 + 4.0j, 5.0 + -2.0j],
    [3.0 + 2.0j, 4.0 + -1.0j, 2.0 + 1.0j, -3.0 + 3.0j],
    [-2.0 + 1.0j, 1.0 + -3.0j, 3.0 + 0.0j, 4.0 + 2.0j],
    [5.0 + 0.0j, -1.0 + -2.0j, 4.0 + -1.0j, 3.0 + 1.0j]
])
H = hessenberg(A)
print(H)
Q, R = qr(H)

#print(R)

