#!/usr/bin/python3
"""
N Queens
"""
import sys


def check_diagonals(a, b):
    """
    Check if the two given positions are diagonally aligned
    """
    if a[0] - a[1] == b[0] - b[1] or a[0] + a[1] == b[0] + b[1]:
        return True
    return False

def check_position(positions, new_pos):
    """
    Check the given two positions, return False if they are aligned in any
    way, or True if they aren't.
    """

    for pos in positions:
        if pos[0] == new_pos[0]:
            return False
        if pos[1] == new_pos[1]:
            return False
        if check_diagonals(pos, new_pos):
            return False

    return True


def print_solutions(N):
    """
    Prints each possible solution for the Nqueens problem with given N.
    """
    # TODO fix logic for N > 4
    solutions = []
    for init_j in range(1, N):
        positions = []
        i = 0
        while i < N:
            if i == 0:
                j = init_j
            else:
                j = 0
            while j < N:
                new_pos = [i, j]
                if check_position(positions, new_pos):
                    positions.append(new_pos)
                j += 1
            i += 1
        if len(positions) == N:
            solutions.append(positions)

    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    n = int(sys.argv[1])
    if not isinstance(n, int):
        print("N must be a number")
        exit(1)

    if n < 4:
        print("N must be at least 4")
        exit(1)
    print_solutions(n)
