import numpy as np

# Define the complex matrix
matrix = np.array([
    [1.0 + -1.0j, 2.0 + 3.0j, -1.0 + 4.0j, 5.0 + -2.0j],
    [3.0 + 2.0j, 4.0 + -1.0j, 2.0 + 1.0j, -3.0 + 3.0j],
    [-2.0 + 1.0j, 1.0 + -3.0j, 3.0 + 0.0j, 4.0 + 2.0j],
    [5.0 + 0.0j, -1.0 + -2.0j, 4.0 + -1.0j, 3.0 + 1.0j]
])

# Calculate the eigenvalues
eigenvalues = np.linalg.eigvals(matrix)

# Display the eigenvalues
print("Eigenvalues of the matrix are:")
print(eigenvalues)

