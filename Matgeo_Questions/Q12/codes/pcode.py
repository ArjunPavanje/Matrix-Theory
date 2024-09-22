import numpy as np
import matplotlib.pyplot as plt
import os

# Load the points from the text file
points = np.loadtxt("line_points.txt", delimiter=',', max_rows=len(list(open("./line_points.txt")))-1)

# Extract the x and y coordinates
x1 = points[:21, 0]
y1 = points[:21, 1]
x = points[21:, 0]
y = points[21:, 1]

A = np.array([0, 0]).reshape(-1,1)
B = np.array([5, 0]).reshape(-1,1)
C = np.array([0, 0]).reshape(-1,1)
plt.figure()
plt.plot(x1, y1, label='2x+3y=9', linestyle='-', color='yellow')  
plt.plot(x, y, label='Perpendiculr to 2x+3y=9', linestyle='solid', color='green')
tri_coords = np.block([A,B,C])  
vert_labels = ['A','B','C'];
for i, txt in enumerate(vert_labels):
    # Annotate each point with its label and coordinates
    plt.text(tri_coords[0, i], tri_coords[1, i], f'{txt}\n({tri_coords[0, i]:.0f}, {tri_coords[1, i]:.0f})',
             fontsize=12, color = 'black', ha='center', va='bottom')
plt.xlabel("x")
plt.ylabel("y")
plt.title("Line 2x+3y=9, its perpendicular")
plt.grid(True)
plt.legend()
plt.show()
