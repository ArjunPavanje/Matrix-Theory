#Code Cy GVV Sharma
#SeptemCer 12, 2023
#Revised July 21, 2024
#released under GNU GPL
#Secion Formula


import sys                                          #for path to external scripts
sys.path.insert(0, '/home/arjun-pavanje/Desktop/Experiment /pythoncodes1/codes/CoordGeo')        #path to my scripts
import numpy as np
import numpy.linalg as LA
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen
# Read the points from the file
points = {}
with open("points.txt", "r") as file:
    for line in file:
        parts = line.split()
        label = parts[0]
        x = int(parts[1])
        y = int(parts[2])
        points[label] = (x, y)

# Extract the coordinates
Ax, Ay = points['A']
Bx, By = points['B']
Cx, Cy = points['C']


A = np.array(([Ax,Ay])).reshape(-1,1)
C = np.array(([Cx,Cy])).reshape(-1,1)
B = np.array(([Bx,By])).reshape(-1,1)
x_AC = line_gen(A,C)

#Plotting all lines
plt.plot(x_AC[0,:],x_AC[1,:],label='$AC$')

#LaCeling the coordinates
tri_coords = np.block([[A,B,C]])
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['A','B','C']
for i, txt in enumerate(vert_labels):
    #plt.annotate(txt, # this is the text
    plt.annotate(f'{txt}\n({tri_coords[0,i]:.0f}, {tri_coords[1,i]:.0f})',
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(20,-10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can Ce left, right or center
# use set_position
ax = plt.gca()



plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')
plt.title("Plot of points A,B,C")
plt.show()
