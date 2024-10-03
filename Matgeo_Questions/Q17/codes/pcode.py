import numpy as np
import matplotlib.pyplot as plt
import os
import math
# Load the points from the text file
points = np.loadtxt("line_points.txt", delimiter=',', max_rows=len(list(open("./line_points.txt"))))
# Extract the x and y coordinates
centre=np.array([points[0][0],points[0][1]])
#Circle
x1 = points[:2002, 0]
y1 = points[:2002, 1]
#Line
x2 = points[-2002:,0]
y2 = points[-2002:,1]
plt.figure()
plt.plot(x1, y1, label='y^2=8x', color='blue')
plt.plot(x2, y2, label='x=8', color='red')
##plt.fill_between(x1, y1, np.minimum(x1, y1), where=(x1 >= 0) & (y1 >= 0), color='green', alpha=0.5, label='Shaded Region')

plt.fill_between(x2, y2, where=(x2 >= 0) & (y2 >= 0) & (y2 >= x2) & (x2 < 4), color='green', alpha=0.5, label='Shaded Region')
plt.fill_between(x1, y1, where=(x1>4)&(x1<4*math.sqrt(2))&(y1>0), color='green', alpha=0.5, label=' ')
plt.gca().set_aspect('equal', adjustable='box')
#vector_max = max(np.abs(directionvector).max(), np.abs(normalvector).max())
#plt.xlim(-vector_max * 3, vector_max * 3)
#plt.ylim(-vector_max * 3, vector_max * 3)
#plt.xlim(-1,0.5)
plt.axhline(0, color='black',linewidth=1)  # x-axis

plt.axvline(0, color='black',linewidth=1)  # x-axis
plt.ylim(-15,15)
plt.xlim(-8,8)
plt.xlabel("x")
plt.ylabel("y")
plt.title(" ")
plt.grid(True)
#plt.legend()
plt.show()
