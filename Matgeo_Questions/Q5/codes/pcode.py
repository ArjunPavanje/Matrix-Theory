import numpy as np
import matplotlib.pyplot as plt
import os
import matplotlib.image as mpimg
from mpl_toolkits.mplot3d import Axes3D

A = np.array([2, 3, 5]).reshape(-1,1)
B = np.array([4, 3, 1]).reshape(-1,1)
C = np.array([-3, 7, 2]).reshape(-1,1)
D = np.array([2, 4, -1]).reshape(-1,1)
E = np.array([-1, 3, -4]).reshape(-1,1)
F = np.array([1, -3, 4]).reshape(-1,1)
G = np.array([2, -1, 3]).reshape(-1,1)
H = np.array([-2, 1, 3]).reshape(-1,1)
fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111, projection='3d')

# Load the points from the text file
points = np.loadtxt("line_points1.txt", delimiter=',', max_rows=len(list(open("./line_points1.txt")))-1)
# Extract the x and y coordinates
x = points[:, 0]
y = points[:, 1]
z = points[:, 2]
ax.plot(x, y, z,label = ' ', linestyle='-', color='blue')

# Load the points from the text file
points = np.loadtxt("line_points2.txt", delimiter=',', max_rows=len(list(open("./line_points2.txt")))-1)
# Extract the x and y coordinates
x = points[:, 0]
y = points[:, 1]
z = points[:, 2]
ax.plot(x, y, z,label = ' ', linestyle='-', color='green')
# Load the points from the text file
points = np.loadtxt("line_points3.txt", delimiter=',', max_rows=len(list(open("./line_points3.txt")))-1)
# Extract the x and y coordinates
x = points[:, 0]
y = points[:, 1]
z = points[:, 2]
ax.plot(x, y, z,label = ' ', linestyle='-', color='orange')
# Load the points from the text file
points = np.loadtxt("line_points4.txt", delimiter=',', max_rows=len(list(open("./line_points4.txt")))-1)
# Extract the x and y coordinates
x = points[:, 0]
y = points[:, 1]
z = points[:, 2]
ax.plot(x, y, z,label = ' ', linestyle='-', color='red')

tri_coords = np.block([A,B,C,D,E,F,G,H])  
ax.scatter(tri_coords[0,:], tri_coords[1, :], tri_coords[2,:])
vert_labels = ['A','B','C','D','E','F','G','H']
for i, txt in enumerate(vert_labels):
    # Annotate each point with its label and coordinates
    ax.text(tri_coords[0, i], tri_coords[1, i], tri_coords[2, i], f'{txt}\n({tri_coords[0, i]:.0f}, {tri_coords[1, i]:.0f}, {tri_coords[2, i]:.0f})',
             fontsize=12, ha='center', va='bottom') 
plt.title("plot of points")
plt.grid(True)
plt.legend()
plt.show()
