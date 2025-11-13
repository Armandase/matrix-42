import numpy as np
import scipy

data = np.array([
    [2.5, 2.4, 0.5],
    [0.5, 0.7, -0.1],
    [2.2, 2.9, 0.3],
])


def check_id(mat):
    id = mat.T @ mat  # Should be close to identity
    id = np.round(id, decimals=6)
    print("Verification (should be close to identity matrix):")
    print(id)

# gram_schmidt_result = scipy.linalg.orth(data.T)
q, r = scipy.linalg.qr(data)
print("Orthogonal basis using Gram-Schmidt process:")
print(q)
check_id(q)

exit()
def gram_schmidt(A):
    '''input: A set of linearly independent vectors stored
              as the columns of matrix A
       outpt: An orthongonal basis for the column space of A.'''
    # get the number of vectors.
    A = np.copy(A).astype(np.float64) # create a local instance of the array
    n = A.shape[1]
    for j in range(n):
        # For the vector in column j, find the perpendicular
        # of the projection onto the previous orthogonal vectors.
        for k in range(j):
            A[:, j] -= np.dot(A[:, k], A[:, j]) * A[:, k]
        # If original vectors aren't lin indep then we can check for this:
        # 
        if np.isclose(np.linalg.norm(A[:, j]), 0, rtol=1e-15, atol=1e-14, equal_nan=False):
            A[:, j] = np.zeros(A.shape[0])
        else:    
            A[:, j] = A[:, j] / np.linalg.norm(A[:, j])
    return A

gram_schmidt_result2 = gram_schmidt(data)
print("Orthogonal basis using Gram-Schmidt process:")
print(gram_schmidt_result2)
check_id(gram_schmidt_result2)

import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.quiver(0, 0, 0, gram_schmidt_result[0, 0], gram_schmidt_result[1, 0], gram_schmidt_result[2, 0], color='r', label='e1')
ax.quiver(0, 0, 0, gram_schmidt_result[0, 1], gram_schmidt_result[1, 1], gram_schmidt_result[2, 1], color='g', label='e2')
ax.quiver(0, 0, 0, gram_schmidt_result[0, 2], gram_schmidt_result[1, 2], gram_schmidt_result[2, 2], color='b', label='e3')

ax.quiver(0, 0, 0, gram_schmidt_result2[0, 0], gram_schmidt_result2[1, 0], gram_schmidt_result2[2, 0], color='r', linestyle='dashed'
          , label='e1 (custom)')
ax.quiver(0, 0, 0, gram_schmidt_result2[0, 1], gram_schmidt_result2[1, 1], gram_schmidt_result2[2, 1], color='g', linestyle='dashed'
          , label='e2 (custom)')
ax.quiver(0, 0, 0, gram_schmidt_result2[0, 2], gram_schmidt_result2[1, 2], gram_schmidt_result2[2, 2], color='b', linestyle='dashed'
          , label='e3 (custom)')
ax.set_xlim([-1, 1])
ax.set_ylim([-1, 1])
ax.set_zlim([-1, 1])
ax.set_xlabel('X axis')
ax.set_ylabel('Y axis')
ax.set_zlabel('Z axis')
ax.legend()
plt.show()