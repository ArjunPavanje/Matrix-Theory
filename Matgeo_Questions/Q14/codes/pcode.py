import numpy as np
import matplotlib.pyplot as plt
import os

# Load the points from the text file
points = np.loadtxt("line_points.txt", delimiter=',', max_rows=len(list(open("./line_points.txt"))))

# Extract the x and y coordinates
centre=np.array([points[0][0],points[0][1]])
x = points[-101:, 0]
y = points[-101:, 1]
plt.figure()
plt.plot(x, y, label='', color='purple')
plt.gca().set_aspect('equal', adjustable='box')
plt.scatter(centre[0], centre[1], color='green', marker='o', label='(-2,3)')
#vector_max = max(np.abs(directionvector).max(), np.abs(normalvector).max())
#plt.xlim(-vector_max * 3, vector_max * 3)
#plt.ylim(-vector_max * 3, vector_max * 3)
#plt.xlim(-1,0.5)
#plt.ylim(2,4)
plt.xlabel("x")
plt.ylabel("y")
plt.title("Circle with centre(-2,3) and radius 4")
plt.grid(True)
plt.legend()
plt.show()
