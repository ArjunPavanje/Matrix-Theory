import numpy as np
import matplotlib.pyplot as plt
import os
import math
import matplotlib.image as mpimg
from mpl_toolkits.mplot3d import Axes3D
# Load the points from the text file
points = np.loadtxt("line_points.txt", delimiter=',', max_rows=len(list(open("./line_points.txt")))-1)
# Extract the x and y coordinates
x1 = points[:42, 0]
y1 = points[:42, 1]
z1 = points[:42, 2]
x = points[42:, 0]
y = points[42:, 1]
z = points[42:, 2]
A = np.array([1,-7,7]).reshape(-1,1)
B = np.array([3,-2,2]).reshape(-1,1)
C = np.array([0,0.707,0.707]).reshape(-1,1)
D = np.array([0,-0.707,-0.707]).reshape(-1,1)

E = np.array([0,0,0]).reshape(-1,1)
fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111, projection='3d')

ax.plot(x1, y1, z1, label='plane containing vectors a,b', linestyle='-', color='yellow')  
ax.plot(x, y, z, label='perpendicular to the plane', linestyle='solid', color='orange')
ax.plot_trisurf([A[0,0], B[0,0], E[0,0]], [A[1,0], B[1,0], E[1,0]], [A[2,0], B[2,0], E[2,0]], color='yellow', alpha=0.5)

tri_coords = np.block([A,B,C,D])  
ax.scatter(tri_coords[0,:], tri_coords[1, :], tri_coords[2,:])
vert_labels = ['A','B','X','X'];
for i, txt in enumerate(vert_labels):
    # Annotate each point with its label and coordinates
    ax.text(tri_coords[0, i], tri_coords[1, i], tri_coords[2, i], f'{txt}\n({tri_coords[0, i]:.0f}, {tri_coords[1, i]:.0f}, {tri_coords[2, i]:.0f})',
             fontsize=12, ha='center', va='bottom') 
plt.title("plot of the vector")
plt.grid(True)
plt.legend()
plt.show()
