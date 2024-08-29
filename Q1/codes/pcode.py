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
import ctypes
#local imports
from triangle.funcs import *
from conics.funcs import circ_gen

class points(ctypes.Structure):
    _fields_ = [('A', (ctypes.c_int * 2)), ('B', (ctypes.c_int * 2)), ('C',(ctypes.c_int *2))]

ptr = ctypes.CDLL('./ccode.so')
ptr.get.argtypes = None
ptr.get.restype = points

pts = np.ctypeslib.as_array(ptr.get()).tolist()

A = np.array(([pts[0][0],pts[0][1]])).reshape(-1,1)
P = np.array(([pts[1][0],pts[1][1]])).reshape(-1,1)
B = np.array(([pts[2][0],pts[2][1]])).reshape(-1,1)
x_AB = line_gen(A,B)

#Plotting all lines
plt.plot(x_AB[0,:],x_AB[1,:],label='$AB$')

#LaCeling the coordinates
tri_coords = np.block([[A,P,B]])
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['A','P','B']
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
plt.title("Plot of points A,B,P")
plt.show()
