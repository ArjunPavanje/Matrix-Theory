#Code by GVV Sharma
#September 12, 2023
#Revised July 21, 2024
#released under GNU GPL
#Point Vectors


import sys                                          #for path to external scripts
sys.path.insert(0, '/home/arjun-pavanje/Documents/Experiment /pythoncodes1/codes/CoordGeo')        #path to my scripts
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
    _fields_ = [('Q', (ctypes.c_int * 2)), ('P', (ctypes.c_int * 2)), ('Ra',(ctypes.c_int *2)),('Rb',(ctypes.c_int *2))]

ptr = ctypes.CDLL('./ccode.so')
ptr.get.argtypes = None
ptr.get.restype = points

pts = np.ctypeslib.as_array(ptr.get()).tolist()


#Given points

Q = np.array(([pts[0][0],pts[0][1]])).reshape(-1,1)
P = np.array(([pts[1][0],pts[1][1]])).reshape(-1,1)
Ra = np.array(([pts[2][0],pts[2][1]])).reshape(-1,1)
Rb = np.array(([pts[3][0],pts[3][1]])).reshape(-1,1)
#Generating all lines
x_P1 = line_gen(P,Ra)
x_P2 = line_gen(P,Rb)
x_PQ = line_gen(P,Q)
x_Q1 = line_gen(Q,Ra)
x_Q2 = line_gen(Q,Rb)

#Plotting all lines
plt.plot(x_P1[0,:],x_P1[1,:],label = '$PR$',color='red')
plt.plot(x_P2[0,:],x_P2[1,:],label='$PR$',color='green')
plt.plot(x_Q1[0,:],x_Q1[1,:],label = '$QR$',color='blue')
plt.plot(x_Q2[0,:],x_Q2[1,:],label='$QR$',color='blue')
plt.plot(x_PQ[0,:],x_PQ[1,:],label='$PQ$',color='blue')


# Scatter plot
tri_coords = np.block([P,Q,Ra,Rb])  # Stack A, B, C vertically
plt.scatter(tri_coords[0, :], tri_coords[1, :])
vert_labels = ['P','Q','R','R']

for i, txt in enumerate(vert_labels):
    # Annotate each point with its label and coordinates
    plt.text(tri_coords[0, i], tri_coords[1, i], f'{txt}\n({tri_coords[0, i]:.0f}, {tri_coords[1, i]:.0f})',
             fontsize=12, ha='center', va='bottom')


plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')
plt.title("Plot of points P,Q,R")
plt.show()
