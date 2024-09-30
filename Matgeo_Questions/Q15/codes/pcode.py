import numpy as np
import matplotlib.pyplot as plt
import os

# Load the points from the text file
points = np.loadtxt("line_points.txt", delimiter=',', max_rows=len(list(open("./line_points.txt"))))
# Extract the x and y coordinates
centre=np.array([points[0][0],points[0][1]])
x1 = points[:2002, 0]
y1 = points[:2002, 1]
x2 = points[-2002:,0]
y2 = points[-2002:,1]
plt.figure()
plt.plot(x1, y1, label='y^2=4x', color='blue')
plt.plot(x2, y2, label='x^2=4y', color='blue')
plt.fill_between(x2, y1, y2, where=(y2 >= y1), color='lightblue', alpha=0.5)
plt.fill_between(x1, y1, y2, where=(y2 >= y1), color='lightblue', alpha=0.5)
plt.gca().set_aspect('equal', adjustable='box')
#vector_max = max(np.abs(directionvector).max(), np.abs(normalvector).max())
#plt.xlim(-vector_max * 3, vector_max * 3)
#plt.ylim(-vector_max * 3, vector_max * 3)
#plt.xlim(-1,0.5)
#plt.ylim(2,4)
plt.xlabel("x")
plt.ylabel("y")
plt.title("Parabolas y^2=4x, x^2=4y")
plt.grid(True)
#plt.legend()
plt.show()
