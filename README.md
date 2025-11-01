# Matrix-42

A C++17 linear algebra library supporting vectors and matrices. Implements basic operations, statistical analysis, and decomposition.

## Features

- **Vector Operations**: Add, subtract, scale, dot/cross products, norms (L1, L2, L∞), rotations (2D/3D), projections
- **Matrix Operations**: Arithmetic, transpose, trace, determinant, rank, inverse, row echelon forms, eigenvalues
- **Statistics**: Mean, variance, covariance, Pearson/Spearman correlation, Mahalanobis distance
- **Complex Support**: Compile-time switch between real (`double`) and complex numbers

## Building

```bash
make NB=00        # Compile example 00 → creates executable00
make NB=stats     # Statistics examples
make NB=complex   # Complex number mode (defines -DCOMPLEX)
make clean        # Remove object files
make fclean       # Remove all build artifacts
```

## Usage

```cpp
// Vectors
Vector u({2, 3}), v({5, 7});
u.add(v);
K dot = u.dot(v);
K norm = u.norm();

// Matrices
Matrix m({{1, 2}, {3, 4}});
K det = m.determinant();
Matrix inv = m.inverse();

// Advanced
auto [eigenvectors, eigenvalues] = matrix.eigh();
K correlation = u.pearson_correlation(v);
```

## Notes

- Formula visualization vscode extension: [Comment Formula Extension](https://marketplace.visualstudio.com/items?itemName=howcasperwhat.comment-formula)