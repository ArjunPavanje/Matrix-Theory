import numpy as np

# Define the complex matrix
matrix = np.array([
    [1.0 + -1.0j, -2.410843 + 2.706912j, 1.739174 + -3.378350j, -4.807224 + 2.883242j],
    [-5.456119 + -3.637412j, 0.627907 + 1.209302j, 4.322774 + 1.399789j, -0.830916 + 0.293569j],
    [0.0 + 0.0j, 4.725055 + -1.090534j, 6.906362 + -0.403645j, 1.078016 + 2.703115j],
    [0.0 + 0.0j, 0.0 + 0.0j, 1.006887 + 0.364786j, 2.465731 + -0.805658j]
])

# Calculate the eigenvalues
eigenvalues = np.linalg.eigvals(matrix)

# Display the eigenvalues
print("Eigenvalues of the matrix are:")
print(eigenvalues)

