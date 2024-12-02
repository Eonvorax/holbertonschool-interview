#!/usr/bin/python3
"""
Pascal's triangle
"""


def pascal_triangle(n):
    """
    Builds a list of lists of integers representing the Pascal's triangle of n.

    Args:
        n (int): the number of rows of Pascal's triangle to build.

    Returns:
        triangle (list of lists of int): the rows representing the triangle.
    """
    if n <= 0:
        return []

    # Set up the triangle with the first row, since we know n >= 1
    triangle = [[1]]

    # For each following row after the first
    for i in range(1, n):
        # Create the first element of the row (always 1)
        row = [1]

        # Calculate every value of the row besides the 1st and last values
        for j in range(1, i):
            # Add the two numbers above this value (in the previous row)
            row.append(triangle[i - 1][j - 1] + triangle[i - 1][j])

        # Add the last element of the row (always 1)
        row.append(1)

        # Add the row of values to the triangle
        triangle.append(row)

    return triangle
