import numpy as np
import matplotlib.pyplot as plt
import os
import matplotlib.image as mpimg
from mpl_toolkits.mplot3d import Axes3D
# Load the points from the text file
points = np.loadtxt("line_points.txt", delimiter=',', max_rows=len(list(open("./triangle_points.txt")))-1)
# Extract the x and y coordinates
x = points[:, 0]
y = points[:, 1]
z = points[:, 2]
A = np.array([-2, 3, 5]).reshape(-1,1)
B = np.array([1, 2, 3]).reshape(-1,1)
C = np.array([7, 0, -1]).reshape(-1,1)
fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111, projection='3d')
ax.plot(x, y, z, label='AC', linestyle='-', color='blue')

tri_coords = np.block([A,B,C])  
ax.scatter(tri_coords[0,:], tri_coords[1, :], tri_coords[2,:])
vert_labels = ['A','B','C)'];
for i, txt in enumerate(vert_labels):
    # Annotate each point with its label and coordinates
    ax.text(tri_coords[0, i], tri_coords[1, i], tri_coords[2, i], f'{txt}\n({tri_coords[0, i]:.0f}, {tri_coords[1, i]:.0f}, {tri_coords[2, i]:.0f})',
             fontsize=12, ha='center', va='bottom') 
plt.title("plot of points A,B,C")
plt.grid(True)
plt.legend()
plt.show()
