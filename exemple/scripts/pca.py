import numpy as np
# {
#                 {2.5,  2.4,  0.5, 5.5,  4.4,  6.5},
#                 {0.5,  0.7, -0.1, 1.5,  1.7,  0.9},
#                 {2.2,  2.9,  0.3, 4.2,  4.9,  3.3},
#                 {1.9,  2.2,  0.4, 3.9,  4.2,  3.4},
#                 {3.1,  3.0,  0.5, 5.1,  5.0,  6.5},
#                 {2.3,  2.7,  0.6, 4.3,  4.7,  5.6},
#                 {2,    1.6, -0.1, 3.8,  3.2,  4.8},
#             };

matrix = np.array([[2.5,  2.4,  0.5, 5.5,  4.4,  6.5],
                   [0.5,  0.7, -0.1, 1.5,  1.7,  0.9],
                   [2.2,  2.9,  0.3, 4.2,  4.9,  3.3],
                   [1.9,  2.2,  0.4, 3.9,  4.2,  3.4],
                   [3.1,  3.0,  0.5, 5.1,  5.0,  6.5],
                   [2.3,  2.7,  0.6, 4.3,  4.7,  5.6],
                   [2,    1.6, -0.1, 3.8,  3.2,  4.8]], dtype=float)

cpy = matrix.copy()
for col in range(matrix.shape[1]):
    mean = np.mean(matrix[:, col])
    matrix[:, col] -= mean
print("Centered matrix:\n", matrix)
cov_matrix = np.cov(matrix, rowvar=False)
print("Covariance matrix:\n", cov_matrix)
eigenvalues, eigenvectors = np.linalg.eig(cov_matrix)
print("Eigenvalues:\n", eigenvalues)
print("Eigenvectors:\n", eigenvectors)
