#Code by GVV Sharma
#September 12, 2023
#Revised July 21, 2024
#released under GNU GPL
#Point Vectors


import sys                                          #for path to external scripts
sys.path.insert(0, '/home/arjun-pavanje/Desktop/Experiment /pythoncodes1/codes/CoordGeo')        #path to my scripts
import numpy as np
import numpy.linalg as LA
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from mpl_toolkits.mplot3d import Axes3D

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen
import ctypes 

class points(ctypes.Structure):
    _fields_ = [('A', (ctypes.c_int * 3)), ('B', (ctypes.c_int * 3)), ('C',(ctypes.c_int *3))]

ptr = ctypes.CDLL('./ccode.so')
ptr.get.argtypes = None
ptr.get.restype = points

pts = np.ctypeslib.as_array(ptr.get()).tolist()


#Given points
A = np.array(([pts[0][0],pts[0][1],pts[0][2]])).reshape(-1,1) 
B = np.array(([pts[1][0],pts[1][1],pts[1][2]])).reshape(-1,1)  
C = np.array(([pts[2][0],pts[2][1],pts[2][2]])).reshape(-1,1)
#Generating all lines
x_AB = line_gen(A,B)
x_BC = line_gen(B,C)
x_CA = line_gen(C,A)
# Create a figure and a 3D Axes
fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111, projection='3d')
#Plotting all lines
ax.plot(x_CA[0,:],x_CA[1,:], x_CA[2,:],label='$AC$')
# Scatter plot
tri_coords = np.block([A,B,C])  # Stack A, B, C vertically
ax.scatter(tri_coords[0, :], tri_coords[1, :], tri_coords[2, :])
vert_labels = ['A', 'B','C']

for i, txt in enumerate(vert_labels):
    # Annotate each point with its label and coordinates
    ax.text(tri_coords[0, i], tri_coords[1, i], tri_coords[2, i], f'{txt}\n({tri_coords[0, i]:.0f}, {tri_coords[1, i]:.0f}, {tri_coords[2, i]:.0f})',
             fontsize=12, ha='center', va='bottom')

ax.spines['top'].set_color('none')
ax.spines['left'].set_position('zero')
ax.spines['right'].set_color('none')
ax.spines['bottom'].set_position('zero')

'''
ax.spines['left'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.spines['top'].set_visible(False)
ax.spines['bottom'].set_visible(False)
plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
'''
plt.grid() # minor
plt.axis('equal')
plt.show()
