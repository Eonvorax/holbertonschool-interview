#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    Given an `n x n` 2D matrix, rotate it 90 degrees clockwise.
    This does not return anything. The matrix is edited in-place.
    We assume the matrix will have 2 dimensions and will not be empty.
    """
    dim = len(matrix)
    # Create a copy of the matrix
    new_matrix = [row[:] for row in matrix]

    for row in range(dim):
        for col in range(dim):
            # Rotate the values by using (-column, row) indexes
            matrix[row][col] = new_matrix[-1 - col][row]
