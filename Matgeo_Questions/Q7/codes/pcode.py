import numpy as np
import matplotlib.pyplot as plt
import os

# Load the points from the text file
points = np.loadtxt("triangle_points.txt", delimiter=',', max_rows=len(list(open("./triangle_points.txt")))-1)

# Extract the x and y coordinates
x = points[:, 0]
y = points[:, 1]
Q = np.array([0, 1]).reshape(-1,1)
P=np.array([5, -3]).reshape(-1,1)
R1 = np.array([4, 6]).reshape(-1,1)
R2 = np.array([-4, 6]).reshape(-1,1)
plt.figure()
plt.plot(x, y, label='PR', linestyle='-', color='blue')

tri_coords = np.block([P,Q,R1,R2])  
plt.scatter(tri_coords[0,:], tri_coords[1, :])
vert_labels = ['P','Q','R','R']
plt.plot([Q[0], P[0]], [Q[1], P[1]], color='gray', linestyle='--', label='Line PQ')
plt.plot([Q[0], R1[0]], [Q[1], R1[1]], color='gray', linestyle='--', label='Line QR')
plt.plot([Q[0], R2[0]], [Q[1], R2[1]], color='gray', linestyle='--', label='Line QR')
for i, txt in enumerate(vert_labels):
    # Annotate each point with its label and coordinates
    plt.text(tri_coords[0, i], tri_coords[1, i], f'{txt}\n({tri_coords[0, i]:.0f}, {tri_coords[1, i]:.0f})',
             fontsize=12, color = 'black', ha='center', va='bottom')
plt.xlabel("x")
plt.ylabel("y")
plt.title("plot of points P,Q,R")
plt.grid(True)
plt.legend()
plt.show()
