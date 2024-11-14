#!/usr/bin/python3
"""
Island perimeter
"""


def cell_perimeter(grid, row, col, height, width):
    """
    Counts the side of a cell in the given grid, basically calculating
    its respective seaside perimeter. The grid is surrounded by water.

    Parameters:
        grid (list of lists): a list of lists of integers representing
            water with 0 and land with 1.
        row (int): row index of the targeted cell
        col (int): column index of the targeted cell
        height (int): grid height
        width (int): grid width

    Returns:
        cell_sea_sides (int): seaside perimeter of the local cell
    """
    cell_sea_sides = 0
    # Count each side facing the sea (by facing the side of the grid, or a 0)
    if col == 0 or grid[row][col - 1] == 0:
        cell_sea_sides += 1
    if col == width - 1 or grid[row][col + 1] == 0:
        cell_sea_sides += 1
    if row == 0 or grid[row - 1][col] == 0:
        cell_sea_sides += 1
    if row == height - 1 or grid[row + 1][col] == 0:
        cell_sea_sides += 1

    return cell_sea_sides


def island_perimeter(grid):
    """
    Calculates the perimeter of an island represented in the given grid.
    The grid is completely surrounded by water
    There is only one island (or nothing).
    The island doesn't have “lakes” (water inside that isn't connected to the
    water surrounding the island).

    Parameters:
        grid (list of lists of ints): A grid representing an island in the sea
            - 0 represents water
            - 1 represents land
            - Each cell is square, with a side length of 1
            - Cells are connected horizontally/vertically (not diagonally).
            - grid is rectangular, with its width and height not exceeding 100

    Returns:
        perimeter (int): the island perimeter
    """
    # NOTE the grid is supposed to be rectangular
    if len(grid) == 0:
        return 0
    height = len(grid)

    if len(grid[0]) == 0:
        return 0
    width = len(grid[0])

    perimeter = 0
    for i in range(height):
        for j in range(width):
            # If this is a land cell (part of an island)
            if grid[i][j] == 1:
                perimeter += cell_perimeter(grid, i, j, height, width)

    return perimeter
