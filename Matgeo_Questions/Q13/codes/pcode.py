import numpy as np
import matplotlib.pyplot as plt
import os

# Load the points from the text file
points = np.loadtxt("line_points.txt", delimiter=',', max_rows=len(list(open("./line_points.txt")))-1)

# Extract the x and y coordinates
x1 = points[:21, 0]
y1 = points[:21, 1]
directionvector = np.loadtxt("line_points.txt", delimiter=',', skiprows=len(list(open("./line_points.txt")))-2, max_rows=1)
normalvector = np.loadtxt("line_points.txt", delimiter=',', skiprows=len(list(open("./line_points.txt")))-1, max_rows=1)
dmagnitude=np.linalg.norm(directionvector)
nmagnitude=np.linalg.norm(normalvector)
scale=1.0;
directionvector=(directionvector/dmagnitude)*scale
normalvector=(normalvector/nmagnitude)*scale
origin = np.array([0, 3])
plt.figure()
plt.plot(x1, y1, label='3=2x+y', color='blue')
plt.quiver(origin[0], origin[1], directionvector[0], directionvector[1], angles='xy', scale_units='xy', scale=1, color='red', label='Direction vector')
plt.quiver(origin[0], origin[1], normalvector[0], normalvector[1], angles='xy', scale_units='xy', scale=1, color='orange', label='Normal vector')
plt.gca().set_aspect('equal', adjustable='box')
vector_max = max(np.abs(directionvector).max(), np.abs(normalvector).max())
#plt.xlim(-vector_max * 3, vector_max * 3)
#plt.ylim(-vector_max * 3, vector_max * 3)
plt.xlim(-1,0.5)
plt.ylim(2,4)
plt.xlabel("x")
plt.ylabel("y")
plt.title("Line 3=2x+y, its perpendicular")
plt.grid(True)
plt.legend()
plt.show()
