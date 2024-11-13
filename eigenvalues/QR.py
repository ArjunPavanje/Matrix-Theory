import numpy as np
from scipy.linalg import qr

# Define the complex matrix
A = np.array([
    [1.000000 + -1.000000j, -2.410843 + 2.706912j, 1.739174 + -3.378350j, -4.807224 + 2.883242j],
    [-5.456119 + -3.637412j, 0.627907 + 1.209302j, 4.322774 + 1.399789j, -0.830916 + 0.293569j],
    [-0.000000 + 0.000000j, 4.725055 + -1.090534j, 6.906362 + -0.403645j, 1.078016 + 2.703115j],
    [0.000000 + 0.000000j, 0.000000 + 0.000000j, 1.006887 + 0.364786j, 2.465731 + -0.805658j]
])

# Perform QR decomposition
Q, R = qr(A)

# Print Q and R matrices
print("Q matrix:")
print(Q)
print("\nR matrix:")
print(R)

