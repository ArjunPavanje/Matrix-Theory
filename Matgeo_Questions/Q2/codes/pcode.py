import numpy as np
import matplotlib.pyplot as plt
import os

# Load the points from the text file
points = np.loadtxt("line_points.txt", delimiter=',', max_rows=len(list(open("./triangle_points.txt")))-1)

# Extract the x and y coordinates
x = points[:, 0]
y = points[:, 1]
O = np.array([0, 0]).reshape(-1,1)
A = np.array([1, 2]).reshape(-1,1)
B = np.array([2, 4]).reshape(-1,1)
plt.figure()
plt.plot(x, y, label='OA', linestyle='-', color='blue')

tri_coords = np.block([O,A,B])  
plt.scatter(tri_coords[0,:], tri_coords[1, :])
vert_labels = ['O','A','B=(a,2a)'];
for i, txt in enumerate(vert_labels):
    # Annotate each point with its label and coordinates
    plt.text(tri_coords[0, i], tri_coords[1, i], f'{txt}\n({tri_coords[0, i]:.0f}, {tri_coords[1, i]:.0f})',
             fontsize=12, color = 'black', ha='center', va='bottom')
plt.xlabel("x")
plt.ylabel("y")
plt.title("plot of points O,A,B")
plt.grid(True)
plt.legend()
plt.show()
