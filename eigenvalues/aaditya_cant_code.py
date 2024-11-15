import numpy as np

# Define the matrix
matrix = np.array([
    [5, 9, 3, 5],
    [3, 3, 0, 2],
    [6, 2, 8, 9],
    [8, 7, 1, 8]
], dtype=complex)

# Compute the eigenvalues
eigenvalues = np.linalg.eigvals(matrix)

# Print the eigenvalues
print("Eigenvalues of the matrix:")
for eigenvalue in eigenvalues:
    print(f"{eigenvalue.real:.6f} + {eigenvalue.imag:.6f}i")

