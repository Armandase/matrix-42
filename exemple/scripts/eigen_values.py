import numpy as np

matrix = np.array([[2.5,  2.4,  0.5],
                   [0.5,  0.7, -0.1],
                   [2.2,  2.9,  0.3]], dtype=float)

print("Eigen values and Eigen vectors:")
eigen_values, eigen_vectors = np.linalg.eig(matrix)
print("Eigen values:", eigen_values)
print("Eigen vectors:\n", eigen_vectors)

print('Gaussian reduction :')
test = np.array([[-2.40696, -2.4, -0.5],
[-0.5, -0.606955, 0.1],
[-2.2, -2.9, -0.206955]], dtype=float)

test2 = np.array([[-0.906955, 2.4, 0.5],
                  [0.5, -2.70696, -0.1],
                  [2.2, 2.9, -3.10696]], dtype=float)


# reduced_matrix = np.linalg.matrix_rank(test)
from scipy.linalg import lu
pl, u = lu(test2, permute_l=True)
print("Rank of the matrix:", u)