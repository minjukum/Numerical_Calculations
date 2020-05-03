from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

plt.rcParams["font.family"] = "Times New Roman"
plt.rcParams.update({'font.size': 15})

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')


with open('elliptic_int.txt') as f:
    lines = f.readlines()

    k = [float(line.split()[0]) for line in lines]
    phi = [float(line.split()[1]) for line in lines]
    F = [float(line.split()[2]) for line in lines]
    E = [float(line.split()[3]) for line in lines]


ax.scatter(k,phi,F, label = 'F(phi,k)')
#ax.scatter(k,phi,E, label = 'E(phi,k)')

ax.set_xlabel('k')
ax.set_ylabel('phi')
ax.set_zlabel('F')
#ax.set_zlabel('E')

plt.title('Elliptic integral for 0<k<1, 0<phi<2pi')
plt.legend()
plt.show()
