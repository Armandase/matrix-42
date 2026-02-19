import matplotlib.pyplot as plt
import numpy as np
from scipy.spatial.transform import Rotation as R

vec = np.array([2, 3, 1])
r = R.from_rotvec([np.pi/16, 0, 0]) # rotation of 90 degrees around the y-axis

vec_rot = r.apply(vec)
print("Original vector:", vec)
print("Rotated vector:", vec_rot)

# 3d plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.quiver(0, 0, 0, vec[0], vec[1], vec[2], color='r', label='Original Vector')
ax.quiver(0, 0, 0, vec_rot[0], vec_rot[1], vec_rot[2], color='b', label='Rotated Vector')
ax.set_xlim(0, 4)
ax.set_ylim(0, 4)
ax.set_zlim(0, 4)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.legend()
plt.show()